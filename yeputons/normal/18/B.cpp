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

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;

#define INF 2000000000
#define mp make_pair
#define pb push_back

#ifdef linux
#define LLD "%lld"
#elif _WIN32
#define LLD "%I64d"
#else
#error Invalid OS. WTF?
#endif

int main() {
  ll n, d, m, l;
  while (scanf(LLD LLD LLD LLD, &n, &d, &m, &l) >= 4) {
    ll x = 0; ll coord = 0;
    vi was(m, INF); vll wasc(m, 0);
    for (ll i = 0;;) {
      if ((x > l) || (i >= n)) {
        printf(LLD "\n", coord);
        break;
      }
      was[x] = i; wasc[x] = coord;
      x += d; coord += d;
      while (x >= m) { x -= m; i++; }
      if (was[x] < INF) {
        ll delta = i - was[x];
        ll deltaC = coord - wasc[x];
        while (i + delta < n) {
          i += delta;
          coord += deltaC;
        }
      }
    }

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}