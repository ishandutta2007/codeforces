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

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<bool> vb;

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, a, b, c;
  while (scanf("%d%d%d%d", &n, &a, &b, &c) >= 4) {
    ll ans = 0;
    for (int a1 = 0; a1 <= a; a1 += 2)
      for (int b1 = 0; b1 <= b; b1++) {
        int rem = n - (a1 >> 1) - b1;
        if (rem < 0) break;
        if (!(rem & 1) && (rem <= c * 2)) ans++;
      }
    printf("%I64d\n", ans);
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}