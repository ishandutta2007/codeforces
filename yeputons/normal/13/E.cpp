#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;

typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

const int BSZ = 450;
int n, k;
vi nes;
vi st, en;
vector<pii> pc;

void recalc(int id) {
  for (int i = en[id]; i >= st[id]; i--) {
    pc[i] = mp(0, i);
    if (nes[i] <= en[id])
      pc[i] = pc[nes[i]];
    pc[i].first++;
  }
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int m;
  while (scanf("%d%d", &n, &m) >= 2) {
    nes = vi(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &nes[i]), nes[i] += i;

    k = 0;
    st.clear(); en.clear();
    for (int i = 0; i < n; i += BSZ) {
      st.pb(i);
      en.pb(min(n - 1, i + BSZ - 1));
      k++;
    }
    pc = vector<pii>(n);
    for (int i = 0; i < k; i++)
      recalc(i);

    for (int tn = 0; tn < m; tn++) {
      int ty, a, b;
      scanf("%d%d", &ty, &a), a--;
      if (ty == 0) {
        scanf("%d", &b);
        nes[a] = a + b;
        for (int i = 0; i < k; i++)
          if (st[i] <= a && a <= en[i])
            recalc(i);
      } else {
        int cans = 0;
        int pr = a;

        while (a < n) {
          cans += pc[a].first;
          a = nes[pr = pc[a].second];
        }
        printf("%d %d\n", pr + 1, cans);
      }
    }
  }
  return 0;
}