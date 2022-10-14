#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <list>

using namespace std;

int eprintf(const char *format, ...) {
  #ifdef DEBUG
  va_list args;
  va_start(args, format);
  int ret = vfprintf(stderr, format, args);
  va_end(args);
  return ret;
  #else
  return 0;
  #endif
}

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<ll> vll;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<bool> vb;

const ll MOD = 1000000007;

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int m;
  while (scanf("%d", &m) >= 1) {
    vi xs(m), cnt(m);
    int n = 0;
    for (int i = 0; i < m; i++) scanf("%d", &xs[i]), n += xs[i];
    for (int i = 0; i < m; i++) scanf("%d", &cnt[i]);

    vector<vll> c(n + 1, vll(n + 1, 0));
    for (int i = 0; i <= n; i++) {
      c[i][0] = c[i][i] = 1;
      for (int k = 1; k < i; k++) {
        c[i][k] = c[i - 1][k - 1] + c[i - 1][k];
        while (c[i][k] >= MOD) c[i][k] -= MOD;
      }
    }

    vector<vll> dyn(m + 1, vll(n + 1, 0));
    dyn[m][0] = 1;
    for (int i = m - 1; i >= 0; i--)
      for (int _rem = 0; _rem <= n - xs[i]; _rem++) {
        int rem = _rem + xs[i];
        for (int cur = 0; cur <= min(rem, cnt[i]); cur++) {
          dyn[i][_rem] += dyn[i + 1][rem - cur] * c[rem][cur];
          dyn[i][_rem] %= MOD;
        }
      }

    int rem = n;
    for (int i = 0; i < m; i++) {
      dyn[0][0] *= c[rem][xs[i]];
      dyn[0][0] %= MOD;
      rem -= xs[i];
    }
    printf("%I64d\n", dyn[0][0]);
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}