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

char f[100][101];
const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };

int h, w;
int n;

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int k;
  while (scanf("%d%d", &h, &k) >= 1) {
    for (int y = 0; y < h; y++)
      scanf("%s", f[y]);
    w = strlen(f[0]);

    vector<pii> xs, ys;
    vvi ids(h, vi(w, -1));

    n = 0;
    for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++)
      if (f[y][x] != '0' && ids[y][x] < 0) {
        int x2 = x;
        while (x2 + 1 < w && f[y][x2 + 1] == f[y][x]) x2++;

        int y2 = y;
        while (y2 + 1 < h && f[y2 + 1][x] == f[y][x]) y2++;

        for (int cy = y; cy <= y2; cy++)
        for (int cx = x; cx <= x2; cx++)
          ids[cy][cx] = n;

        xs.pb(mp(x, x2));
        ys.pb(mp(y, y2));
        n++;
      }

    vvi ne(n, vi(8, -1));
    for (int i = 0; i < n; i++)
    for (int dp = 0; dp < 4; dp++)
    for (int cp = -1; cp <= 1; cp += 2) {
      int id = dp * 2 + (cp == 1);
      int np = (dp + cp) & 3;

      int cdx = dx[dp] + dx[np];
      int cdy = dy[dp] + dy[np];
      assert(abs(cdx) == 1 && abs(cdy) == 1);
      int x = cdx < 0 ? xs[i].first : xs[i].second;
      int y = cdy < 0 ? ys[i].first : ys[i].second;
      x += dx[dp];
      y += dy[dp];
      if (x < 0 || y < 0 || x >= w || y >= h) continue;
      ne[i][id] = ids[y][x];
    }

    int bp = 0, dp = 0, cp = -1;
    for (int i = 0; i < k; i++) {
      int id = dp * 2 + (cp == 1);
      if (ne[bp][id] >= 0) {
        bp = ne[bp][id];
      } else {
        if (cp < 0) {
          cp = 1;
        } else {
          cp = -1;
          dp = (dp + 1) & 3;
        }
      }
    }
    printf("%c\n", f[ys[bp].first][xs[bp].first]);
  }
  return 0;
}