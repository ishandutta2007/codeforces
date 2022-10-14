#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <cstring>
#include <algorithm>
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

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<ll> vll;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<bool> vb;

char buf[51];
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%s", buf) >= 1) {
    n = strlen(buf);
    vector<vll> dyn(n + 1, vll(10, 0));
    for (int pr = 0; pr < 10; pr++)
      dyn[n][pr] = 1;

    for (int i = n - 1; i; i--)
      for (int pr = 0; pr < 10; pr++) {
        int x = (buf[i] - '0' + pr);
        dyn[i][pr] += dyn[i + 1][x >> 1];
        if (x & 1)
          dyn[i][pr] += dyn[i + 1][(x >> 1) + 1];
      }

    ll a = 0;
    for (int pr = 0; pr < 10; pr++)
      a += dyn[1][pr];

    bool bad = true;
    for (int i = 1; i < n; i++)
      if (abs(buf[i] - buf[i - 1]) > 1) {
        bad = false;
      }
    if (bad) a--;
    printf("%I64d\n", a);
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}