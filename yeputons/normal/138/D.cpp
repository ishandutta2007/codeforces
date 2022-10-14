#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

const int MAXH = 25;
const int MAXW = 25;

char f[MAXH][MAXW + 1];
int h, w;

int d[MAXH][MAXW][MAXH][MAXW];
int get(int x1, int y1, int x2, int y2) {
  if (x1 > x2 || y1 > y2) return 0;
  return d[y1][x1][y2][x2];
}

char sf[MAXH][MAXW + 1];
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int sh, sw;
  while (scanf("%d%d", &sh, &sw) >= 1) {
    for (int y = 0; y < sh; y++)
      scanf("%s", sf[y]);

    int ans = 0;
    for (int curp = 0; curp < 2; curp++) {
      h = w = (sh + sw) / 2;
      memset(f, ' ', sizeof f);
      for (int y = 0; y < sh; y++)
      for (int x = 0; x < sw; x++) if ((y + x) % 2 == curp) {
        f[(y + x) / 2][(x - y + sh - 1) / 2] = sf[y][x];
      }

/*      #ifdef DEBUG
      for (int y = 0; y < h; y++) {
        f[y][w] = '|';
        f[y][w + 1] = 0;
        eprintf("%s\n", f[y]);
      }
      eprintf("=====\n");
      #endif*/

      memset(d, 0, sizeof d);
      for (int ch = 1; ch <= h; ch++)
      for (int cw = 1; cw <= w; cw++)
      for (int y1 = 0; y1 + ch <= h; y1++)
      for (int x1 = 0; x1 + cw <= w; x1++) {
        int x2 = x1 + cw - 1;
        int y2 = y1 + ch - 1;
        vi vals;

        for (int y = y1; y <= y2; y++)
        for (int x = x1; x <= x2; x++) if (f[y][x] != ' ') {
          switch (f[y][x]) {
          case 'L':
            vals.pb(get(x1, y1, x2, y - 1) ^ get(x1, y + 1, x2, y2));
            break;
          case 'R':
            vals.pb(get(x1, y1, x - 1, y2) ^ get(x + 1, y1, x2, y2));
            break;
          case 'X':
            vals.pb(get(x1, y1, x - 1, y - 1) ^ get(x + 1, y1, x2, y - 1) ^
                    get(x1, y + 1, x - 1, y2) ^ get(x + 1, y + 1, x2, y2));
            break;
          default:
            assert(false);
          }
        }
        sort(vals.begin(), vals.end());
        vals.resize(unique(vals.begin(), vals.end()) - vals.begin());

        int cv = 0;
        while (cv < sz(vals) && vals[cv] == cv) cv++;
        d[y1][x1][y2][x2] = cv;
      }
      ans ^= d[0][0][h - 1][w - 1];
    }
    printf(ans ? "WIN\n" : "LOSE\n");
//    break;
  }
  return 0;
}