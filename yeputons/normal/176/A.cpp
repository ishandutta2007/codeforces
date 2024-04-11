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

struct Ty {
  int a, b, c;
};

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, m, k;
  while (scanf("%d%d%d", &n, &m, &k) >= 1) {
    vector<vector<Ty> > tys(n, vector<Ty>(m));

    for (int i = 0; i < n; i++) {
      scanf("%*s");
      for (int i2 = 0; i2 < m; i2++)
        scanf("%d%d%d", &tys[i][i2].a, &tys[i][i2].b, &tys[i][i2].c);
    }

    int ans = 0;
    vector<int> ts;
    for (int a = 0; a < n; a++)
    for (int b = 0; b < n; b++) if (a != b) {
      ts.clear();
      for (int i = 0; i < m; i++)
        if (tys[a][i].a < tys[b][i].b) {
          for (int i2 = 0; i2 < tys[a][i].c; i2++)
            ts.pb(tys[b][i].b - tys[a][i].a);
        }
      sort(ts.begin(), ts.end(), greater<int>());
      int cans = 0;
      for (int i = 0; i < sz(ts) && i < k; i++)
        cans += ts[i];
      ans = max(ans, cans);
    }
    printf("%d\n", ans);
  }
  return 0;
}