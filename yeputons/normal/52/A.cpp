#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdarg>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

inline int eprintf(const char* format, ...) {
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

int n;
int main() {
  #ifdef DEBUG
  freopen("stdin.txt", "r", stdin);
  freopen("stdout.txt", "w", stdout);
  #endif

  while (scanf("%d", &n) >= 1) {
    vi c(3);
    for (int i = 0; i < n; i++) { int x; scanf("%d", &x), x--; c[x]++; }

    int ans = c[0] + c[1];
    ans = min(ans, c[0] + c[2]);
    ans = min(ans, c[1] + c[2]);
    printf("%d\n", ans);
    
    #ifndef DEBUG
    #warning No multitest!!!
    break;
    #endif
  }
  return 0;
}