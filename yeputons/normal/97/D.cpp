#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>

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

const int MAXH = 150;
const int MAXW = 150;
const int MAXK = 1e5;
char s[MAXK + 1];
char f[MAXH][MAXW + 1];

typedef bitset<(MAXH + 2) * (MAXW + 2)> field;
int id(int x, int y) { return (y + 1) * (MAXW + 2) + x + 1; }

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };
const char* dc = "DRUL";

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int h, w, k;
  while (scanf("%d%d%d", &h, &w, &k) >= 1) {
    for (int y = 0; y < h; y++)
      scanf("%s", f[y]);
    scanf("%s", s);

    field need, fre;

    for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++)
      if (f[y][x] != '#') {
        fre.set(id(x, y));
        if (f[y][x] == 'E')
          need.set(id(x, y));
      }
    field cur = fre, walls = ~fre;

    for (int i = 0; i <= k; i++) {
/*      eprintf("cur:\n");
      for (int y = -1; y <= h; y++)
      for (int x = -1; x <= w; x++)
        eprintf("%d%c", !!cur[id(x, y)], "\n "[x < w]);*/

      if (cur == need) { printf("%d\n", i); break; }
      if (i >= k) { printf("-1\n"); break; }

      for (int d = 0; d < 4; d++) if (s[i] == dc[d]) {
        int off = id(dx[d], dy[d]) - id(0, 0);
        if (off >= 0) {
          cur <<= off;
          cur = (cur & fre) | ((cur & walls) >> off);
        } else {
          off = -off;
          cur >>= off;
          cur = (cur & fre) | ((cur & walls) << off);
        }
      }
    }
  }
  return 0;
}