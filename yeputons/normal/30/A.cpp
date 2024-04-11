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
#define TASKNAME ""

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<bool> vb;

int pow(int a, int b) {
  int res = 1;
  while (b --> 0) res *= a;
  return res;
}
int sgn(int a) {
  if (a < 0) return -1;
  else if (!a) return 0;
  else return 1;
}

int main() {
  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  int a, b, n;
  while (scanf("%d%d%d", &a, &b, &n) >= 3) {
    if (!a) {
      if (!b) printf("0\n");
      else printf("No solution\n");
    } else if (b % a) {
      printf("No solution\n");
    } else {
      b /= a;
      int sig = sgn(b);
      b = abs(b);

      int x = 0;
      for (; abs(pow(x, n)) < b; x++) eprintf("x=%d, n=%d\n", x, n);

      if (pow(x, n) == b) {
        printf("%d\n", x * sig);
      } else {
        printf("No solution\n");
      }
    }
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}