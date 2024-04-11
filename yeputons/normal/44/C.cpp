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

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<bool> vb;

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, m;
  while (scanf("%d%d", &n, &m) >= 2) {
    vi cnt(n, 0);
    for (int i = 0; i < m; i++) {
      int l, r; scanf("%d%d", &l, &r), l--, r--;
      for (int i2 = l; i2 <= r; i2++) cnt[i2]++;
    }

    for (int i = 0; i < n; i++)
      if (cnt[i] != 1) {
        printf("%d %d\n", i + 1, cnt[i]);
        goto end;
      }
    printf("OK\n");

    end:;
    
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}