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

char buf[201];
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, mil, mal;
  while (scanf("%d%d%d", &n, &mil, &mal) >= 3) {
    scanf("%s", buf);
    int l = strlen(buf);
    if (l > n * mal || l < n * mil) {
      printf("No solution");
    } else {
      int alen = l / n;
      vi lens(n, alen);
      for (int i = 0; i < (l % n); i++)
        lens[i % n]++;

      for (int i = 0; i < n; i++)
        assert(lens[i] >= mil && lens[i] <= mal);

      int pos = 0;
      for (int i = 0; i < n; i++) {
        for (int i2 = 0; i2 < lens[i]; i2++)
          printf("%c", buf[pos++]);
        printf("\n");
      }
    }
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}