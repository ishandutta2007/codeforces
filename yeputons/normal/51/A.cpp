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

bool eq(char* a, char* b) {
  for (int i = 0; i < 4; i++) {
    int p1 = 0, p2 = i;
    bool g = true;
    for (int i2 = 0; i2 < 4; i2++) {
      if (a[p1] != b[p2]) g = false;
      p1 = (p1 + 1) % 4;
      p2 = (p2 + 1) % 4;
    }
    if (g) return true;
  }
  return false;
}

int n;
char data[1000][5];
int main() {
  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  while (scanf("%d", &n) >= 1) {
    char buf[3];
    
    for (int i = 0; i < n; i++) {
      scanf("%s%s", data[i] + 0, data[i] + 2);
      swap(data[i][2], data[i][3]);
      if (i + 1 < n)
        scanf("%s", buf);
    }

    int a = 0;
    for (int i = 0; i < n; i++) {
      bool g = true;
      for (int i2 = 0; i2 < i; i2++)
        if (eq(data[i], data[i2])) { g = false; break; }
      if (g) a++;
    }
    printf("%d\n", a);
    
    #ifndef DEBUG
    #warning No multitest!!!
    break;
    #endif
  }
  return 0;
}