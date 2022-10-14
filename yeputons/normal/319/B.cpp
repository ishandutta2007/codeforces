#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int n0;
  while (scanf("%d", &n0) >= 1) {
    vi as(n0);
    for (int i = 0; i < n0; i++)
      scanf("%d", &as[i]);

    vi ne(n0), pr(n0);
    for (int i = 0; i < n0; i++) {
      ne[i] = i + 1;
      pr[i] = i - 1;
    }
    pr[0] = n0;

    vi tokill;
    vb alive(n0, true);
    for (int i = n0 - 2; i >= 0; i--)
      if (as[i] > as[ne[i]]) {
        tokill.pb(ne[i]);
      }

    int ans = 0;
    while (!tokill.empty()) {
      ans++;
      vi nk;
      for (int i = 0; i < sz(tokill); i++) {
        int b = tokill[i];
        if (!alive[b]) continue;

        alive[b] = false;

        int a = pr[b], c = ne[b];
        assert(a < n0);
        ne[a] = c;
        if (c < n0) {
          pr[c] = a;
          if (as[a] > as[c]) {
            nk.pb(c);
          }
        }
        pr[b] = ne[b] = n0;
      }
      tokill.swap(nk);
    }
    printf("%d\n", ans);
  }
  return 0;
}