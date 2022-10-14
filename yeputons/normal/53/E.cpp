#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdarg>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) {}
#endif

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;

int main() {
  #ifdef DEBUG
  freopen("stdin.txt", "r", stdin);
  freopen("stdout.txt", "w", stdout);
  #endif

  int n, m, mk;
  while (scanf("%d%d%d", &n, &m, &mk) >= 3) {
    vvi es(n);
    for (int i = 0; i < m; i++) {
      int a, b; scanf("%d%d", &a, &b), a--, b--;
      es[a].pb(b);
      es[b].pb(a);
    }

    vector<vll> d(1 << n, vll(1 << n, 0));
    d[0][0] = 1;
    for (int m = 1; m < (1 << n); m++) if (__builtin_popcount(m) > 2) {
      for (int subm = m; subm > 0; subm = (subm - 1) & m) {
        int k = __builtin_popcount(subm);
        d[m][subm] = 0;
        for (int i = 0; i < n; i++) if (subm & (1 << i)) {
          for (int i2 = 0; i2 < es[i].size(); i2++) if (m & (1 << es[i][i2])) {
            int b = es[i][i2];
            if (subm & (1 << b)) continue;

            int nm = m ^ (1 << i);
            int nsm = subm ^ (1 << i);
            d[m][subm] += d[nm][nsm];
            d[m][subm] += d[nm][nsm ^ (1 << b)];
          }
        }

        assert(!(d[m][subm] % k));
        d[m][subm] /= k;
      }
    } else {
      if (__builtin_popcount(m) == 2) {
        int a = -1, b = -1;
        for (int i = 0; i < n; i++) if (m & (1 << i)) { if (a < 0) a = i; else b = i; }
        for (int i = 0; i < es[a].size(); i++)
          if (es[a][i] == b) {
            d[m][m] = 1;
          }
      }
    }
    ll ans = 0;
    for (int subm = 0; subm < (1 << n); subm++) if (__builtin_popcount(subm) == mk) {
      ans += d[(1 << n) - 1][subm];
    }
    printf("%I64d\n", ans);

    #ifndef DEBUG
    #warning No multitest!!!
    break;
    #endif
  }
  return 0;
}