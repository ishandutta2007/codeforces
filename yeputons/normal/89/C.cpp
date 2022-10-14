#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdarg>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

const int INF = 1e8;
const char * dc = "LRUD";

int get(vi &t, int x) {
  assert(x >= 0 && x < sz(t));
  if (t[x] == -1) return x;
  return t[x] = get(t, t[x]);
}

const int MAXW = 5000;
char buf[MAXW + 1];
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int h, w;
  while (scanf("%d%d", &h, &w) >= 2) {
    vector<string> f(h);
    for (int y = 0; y < h; y++)
      scanf("%s", buf), f[y] = buf;

    vvi trl(h, vi(w + 2, -1)), trr(h, vi(w + 2, -1));
    vvi tru(w, vi(h + 2, -1)), trd(w, vi(h + 2, -1));

    int mans = -1, mcnt = 0;
    for (int sy = 0; sy < h; sy++) {
      for (int sx = 0; sx < w; sx++) if (f[sy][sx] != '.') {
        #define zero(x, y) \
            trl[y][x + 1] = x; \
            trr[y][x + 1] = x + 2; \
            tru[x][y + 1] = y; \
            trd[x][y + 1] = y + 2;

        #define unzero(x, y) \
            trl[y][x + 1] = \
            trr[y][x + 1] = \
            tru[x][y + 1] = \
            trd[x][y + 1] = -1;

        for (int y = 0; y < h; y++)
          for (int x = 0; x < w; x++) if (f[y][x] == '.') {
            zero(x, y);
          } else {
            unzero(x, y);
          }

        int ans = 0;
        int y = sy, x = sx;
        while (1) {
          ans++;
          int d = 0;
          for (; assert(d < 4), dc[d] != f[y][x]; d++);

          zero(x, y);

          if (x < 0 || y < 0 || x >= w || y >= h) break;
          switch (d) {
          case 0: x = get(trl[y], x + 1) - 1; break;
          case 1: x = get(trr[y], x + 1) - 1; break;
          case 2: y = get(tru[x], y + 1) - 1; break;
          case 3: y = get(trd[x], y + 1) - 1; break;
          }
          if (x < 0 || y < 0 || x >= w || y >= h) break;
        }
        if (mans < ans) {
          mans = ans;
          mcnt = 0;
        }
        if (mans == ans)
          mcnt++;
      }
    }
    printf("%d %d\n", mans, mcnt);
    
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}