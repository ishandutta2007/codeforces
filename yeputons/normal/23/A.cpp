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

char buf[101];
int main() {
  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif


  while (scanf("%s", buf) >= 1) {
    int n = strlen(buf);
    bool found = false;
    for (int l = n - 1; l >= 0; l--) {
      for (int a = 0; a + l <= n; a++)
        for (int b = a + 1; b + l <= n; b++) {
          found = true;
          for (int i = 0; i < l; i++)
            if (buf[a + i] != buf[b + i]) {
              found = false;
              break;
            }
          if (found) { printf("%d\n", l); goto end; }
        }
    }
    end:
    int x = 0;

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}