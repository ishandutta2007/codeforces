#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <map>
#include <set>

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

const int MAXH = 1700;
const int MAXW = 1700;

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };

int f[MAXH][MAXW];
int h, w;
bool check_circ(int x0, int y0, int maxr) {
  int rs = sqrt(maxr) + 5;
  while (rs * rs > maxr) rs--;

  for (int dy = -rs; dy <= rs; dy++)
  for (int dx = -rs; dx <= rs; dx++)
    if (dx * dx + dy * dy <= maxr) {
      int x = x0 + dx, y = y0 + dy;
      if (x < 0 || y < 0 || x >= w || y >= h) return false;
      if (!f[y][x]) return false;
    }
  return true;
}

int was[MAXH][MAXW];

const int C = 5;
int sumx, sumy, sumc;
vector<pii> pts;

void dfs(int x, int y) {
  if (x < 0 || y < 0 || x >= w || y >= h) return;
  if (was[y][x]) return;
  if (!f[y][x]) return;

  bool g = true;
  for (int y1 = -C; y1 <= C; y1++)
  for (int x1 = -C; x1 <= C; x1++) {
    int nx = x + x1, ny = y + y1;
    if (nx < 0 || ny < 0 || nx >= w || ny >= h)
      g = false;
    else
      g = g && f[ny][nx];
  }
  if (g) {
    sumx += x;
    sumy += y;
    sumc++;
  } else {
    pts.pb(mp(x, y));
  }

  was[y][x] = true;
  for (int i = 0; i < 4; i++)
    dfs(x + dx[i], y + dy[i]);
}

double radius;
void dfs2(int x, int y) {
  if (x < 0 || y < 0 || x >= w || y >= h) return;
  if (was[y][x] >= 2) return;
  if (!f[y][x]) return;
  
  int curd = (x - sumx) * (x - sumx) + (y - sumy) * (y - sumy);
  if (sqrt(curd) <= radius + 5) return;

  was[y][x] = 2;
  for (int i = 0; i < 4; i++)
    dfs2(x + dx[i], y + dy[i]);
}

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  while (scanf("%d%d", &h, &w) >= 1) {
    for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++)
      scanf("%d", &f[y][x]);

    vi anses;

    memset(was, 0, sizeof was);
    for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++) if (f[y][x] && !was[y][x]) {
      sumx = 0;
      sumy = 0;
      sumc = 0;
      pts.clear();

      dfs(x, y);
      assert(sumc);
      sumx /= sumc;
      sumy /= sumc;
      f[sumy][sumx] = 2;

      int L = 0, R = min(w, h) * min(w, h) + 100;
      while (L + 1 < R) {
        int M = (L + R) / 2;
        if (check_circ(sumx, sumy, M)) L = M;
        else R = M;
      }
      radius = sqrt(L);

      int cans = 0;
      for (int i = 0; i < sz(pts); i++) {
        int x = pts[i].first, y = pts[i].second;

        int cd = (x - sumx) * (x - sumx) + (y - sumy) * (y - sumy);
        if (sqrt(cd) <= radius + 6) continue;
        f[y][x] = 3;
        if (was[y][x] >= 2) continue;

        cans++;
        dfs2(x, y);
      }
      anses.pb(cans);
    }
    #ifdef DEBUG
    for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++)
      printf("%d%c", f[y][x], "\n "[x + 1 < w]);
    #endif

    sort(anses.begin(), anses.end());
    printf("%d\n", sz(anses));
    for (int i = 0; i < sz(anses); i++)
      printf("%d%c", anses[i], "\n "[i + 1 < sz(anses)]);
  }
  return 0;
}