#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>

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

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;

#define INF (ll)1e15
#define mp make_pair
#define pb push_back
#define forn(i, n) for (int i = 0; i < n; i++)

#ifdef linux
#define LLD "%lld"
#elif _WIN32
#define LLD "%I64d"
#endif

#define MAXT 6000
int main() {
  int n;
  while (scanf("%d", &n) >= 1) {
    vi t(n), c(n);
    forn(i, n) scanf("%d%d", &t[i], &c[i]), t[i]++;

    vvll dyn(n, vll(MAXT + 1, INF));
    dyn[0][0] = 0;
    dyn[0][t[0]] = c[0];
    for (int i = 1; i < n; i++) {
      for (int ot = 0; ot <= MAXT; ot++)
        dyn[i][ot] = dyn[i - 1][ot];
      for (int ot = 0; ot <= MAXT; ot++) {
        int nt = ot + t[i];
        if (nt > MAXT) nt = MAXT;
        dyn[i][nt] = min(dyn[i][nt], dyn[i - 1][ot] + (ll)c[i]);
      }
    }

    ll ans = INF;
    for (int ot = n; ot <= MAXT; ot++)
      ans = min(ans, dyn[n - 1][ot]);
    printf(LLD "\n", ans);
    
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}