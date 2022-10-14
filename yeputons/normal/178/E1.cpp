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
#define sqr(x) ((x) * (x))

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

const int INF = 1e9;

int h, w;
vvi f;

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };

bool check(int x, int y) { return 0 <= x && x < w && 0 <= y && y < h && f[y][x]; }

vvi was;

double sumx, sumy;
int cnt;
void dfs1(int x, int y) {
  if (was[y][x] >= 1) return;

  was[y][x] = 1;
  sumx += x; sumy += y;
  cnt++;

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (!check(nx, ny)) continue;
    dfs1(nx, ny);
  }
}

vector<double> dis;
vector<pii> pts;

void dfs2(int x, int y) {
  if (was[y][x] >= 2) return;
  was[y][x] = 2;
  bool bord = false;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (!check(nx, ny)) { bord = true; continue; }
    dfs2(nx, ny);
  }
  if (bord) {
    pts.pb(mp(x, y));
    dis.pb((x - sumx) * (x - sumx) + (y - sumy) * (y - sumy));
  }
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%d", &h) >= 1) {
    w = h;
    f = vvi(h, vi(w));
    for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++)
      scanf("%d", &f[y][x]);

    int c1 = 0, c2 = 0;
    was = vvi(h, vi(w, 0));

    for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++) if (!was[y][x] && f[y][x]) {
      sumx = 0, sumy = 0;
      cnt = 0;
      dfs1(x, y);
      assert(cnt > 0);
      sumx /= cnt, sumy /= cnt;

      dis.clear();
      pts.clear();
      dfs2(x, y);
      sort(dis.begin(), dis.end());

      double maxd = 0;
      for (int a = 0; a < sz(pts); a++)
      for (int b = 0; b < sz(pts); b++)
        maxd = max(maxd, (double)(sqr(pts[a].first - pts[b].first) + sqr(pts[a].second- pts[b].second)));
      maxd = sqrt(maxd);

      double diff = dis[sz(dis) - 1] - dis[0];
      double k = maxd / diff;
      if (k < 0.5)
        c2++;
      else
        c1++;
    }
    printf("%d %d\n", c1, c2);
  }
  return 0;
}