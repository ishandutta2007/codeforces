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

const int dx[] = { 1, 1, -1, -1, 2, 0, -2, 0 };
const int dy[] = { 1, -1, -1, 1, 0, 2, 0, -2 };

char   f[1000][1001];
char res[1000][1001];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int h, w;
  while (scanf("%d%d", &h, &w) >= 1) {
    for (int y = 0; y < h; y++)
      scanf("%s", f[y]);

    try {
      memset(res, '.', sizeof res);
      for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
          if (f[y][x] == 'b') {
            char minc = 'a';
            for (int d = 0; d < 8; d++) {
              int nx = x + dx[d], ny = y + dy[d];
              if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
              if (f[ny][nx] == '.') continue;
              assert(f[ny][nx] == 'b');
              if (res[ny][nx] == minc) { minc++; d = -1; }
            }
            assert(minc <= 'd');

            if (y && f[y - 1][x] == 'w' && y + 1 < h && f[y + 1][x] == 'w') {
              res[y - 1][x] = minc;
              res[y][x] = minc;
              res[y + 1][x] = minc;
              f[y - 1][x] = f[y + 1][x] = '.';
            } else if (x && f[y][x - 1] == 'w' && x + 1 < w && f[y][x + 1] == 'w') {
              res[y][x - 1] = minc;
              res[y][x] = minc;
              res[y][x + 1] = minc;
              f[y][x - 1] = f[y][x + 1] = '.';
            } else
              throw 0;
          }

      for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
          if ((res[y][x] == '.') && (f[y][x] != '.'))
            throw 0;

      ff:
      printf("YES\n");
      for (int y = 0; y < h; y++) {
        res[y][w] = 0;
        printf("%s\n", res[y]);
      }
    } catch (...) {
      printf("NO\n");
    }

    break;
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}