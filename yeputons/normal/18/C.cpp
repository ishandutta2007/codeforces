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
#endif

int main() {
  int n;
  while (scanf("%d", &n) >= 1) {
    vll as(n); ll sum = 0;
    for (int i = 0; i < n; i++) scanf(LLD, &as[i]), sum += as[i];
    int ans = 0;
    if (!(sum & 1)) {
      sum >>= 1;
      ll cs = 0;
      for (int i = 0; i + 1 < n; i++) {
        cs += as[i];
        if (cs == sum) ans++;
      }
    }
    printf("%d\n", ans);
    
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}