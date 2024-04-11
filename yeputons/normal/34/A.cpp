#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int eprintf(const char* format, ...) {
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
typedef pair<int, int> pii;

int n;

int main() {
  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  
  while (scanf("%d", &n) >= 1) {
    vi a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    a.pb(a[0]);

    int ans = 1e9, ansi = -1;
    for (int i = 0; i < n; i++) {
      if (abs(a[i] - a[i + 1]) < ans) {
        ans = abs(a[i] - a[i + 1]);
        ansi = i;
      }
    }
    printf("%d %d\n", ansi + 1, (ansi + 1) % n + 1);
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}