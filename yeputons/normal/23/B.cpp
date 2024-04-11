#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdarg>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

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

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

typedef long long ll;
typedef vector<ll> vll;

#define INF 2e9

int main() {
  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  int TC;
  while (scanf("%d", &TC) >= 1) {
    for (int T = 0; T < TC; T++) {
      int n; assert(scanf("%d", &n) >= 1);
      printf("%d\n", (n >= 3) ? n - 2 : 0);
    }

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}