#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

const int MAXH = 31;
const int MAXW = 31;
const int MAXK = 50;

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };
const char *dc = "RULD";

int getDir(int x, int y) {
  assert(!x || !y);
  assert(x || y);
  if (!x) return y > 0 ? 1 : 3;
  return x > 0 ? 0 : 2;
}
void cut(int &x, int l, int r) {
  x = max(min(x, r - 1), l);
}

pair<pii, int> ans[MAXH][MAXW][4][MAXK + 1];
int ne[MAXH][MAXW][4];

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int n, h, w;
  while (scanf("%d%d", &n, &h) >= 1) {
    w = h;
    h++, w++;

    memset(ans, -1, sizeof ans);
    for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++)
    for (int i = 0; i < 4; i++)
      ne[y][x][i] = i;
    for (int i = 0; i < n; i++) {
      int x1, y1, x2, y2;
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
      int dir = getDir(x2 - x1, y2 - y1);
      if (x1 > x2) swap(x1, x2);
      if (y1 > y2) swap(y1, y2);

      for (int y = y1; y <= y2; y++)
      for (int x = x1; x <= x2; x++)
      for (int t = 0; t < 4; t++)
        ne[y][x][t] = dir;
    }
    for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++)
    for (int i = 0; i < 4; i++) {
      int nd = ne[y][x][i];
      int nx = x + dx[nd];
      int ny = y + dy[nd];
      cut(nx, 0, w);
      cut(ny, 0, h);
      ans[y][x][i][0] = mp(mp(nx, ny), nd);
    }
    for (int k = 1; k <= MAXK; k++) {
      for (int y = 0; y < h; y++)
      for (int x = 0; x < w; x++)
      for (int i = 0; i < 4; i++) {
        int nx = ans[y][x][i][k - 1].first.first;
        int ny = ans[y][x][i][k - 1].first.second;
        int nd = ans[y][x][i][k - 1].second;
        ans[y][x][i][k] = ans[ny][nx][nd][k - 1];
      }
    }
    int q;
    scanf("%d", &q);
    while (q --> 0) {
      int x, y;
      char c;
      ll t;
      scanf("%d%d %c%I64d", &x, &y, &c, &t);
      int d = strchr(dc, c) - dc;
      assert(0 <= d && d < 4);

      for (int i = MAXK - 1; i >= 0; i--)
        if (t >= (1LL << i)) {
          pair<pii, int> res = ans[y][x][d][i];
          x = res.first.first;
          y = res.first.second;
          d = res.second;
          t -= 1LL << i;
        }
      printf("%d %d\n", x, y);
    }
  }
  return 0;
}