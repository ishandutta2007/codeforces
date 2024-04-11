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

typedef vector<bool> vb;

int main() {
  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  
  int n;
  while (scanf("%d", &n) >= 1) {
    if (n & 1) {
      printf("1");
      for (int i = 1; i < n; i += 2)
        printf(" %d %d", i + 2, i + 1);
    } else {
      for (int i = 0; i < n; i += 2) {
        if (i) printf(" ");
        printf("%d %d", i + 2, i + 1);
      }
    }

    printf("\n");
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}