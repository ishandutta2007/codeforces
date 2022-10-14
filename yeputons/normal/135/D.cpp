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
#include <deque>

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

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };

const int MAXC = 2000;
char f[MAXC][MAXC + 1];
int sums[MAXC + 1][MAXC + 1];
vvi was; int ver;
int ans;
int h, w;

void goZero(int x, int y) {
  deque<pii> q;
  q.pb(mp(x, y));
  was[y][x] = ver;

  vector<pii> spts;
  int cnt = 0;

  while (!q.empty()) {
    pii cur = q.front(); q.pop_front();
    cnt++; spts.pb(cur);

    for (int dx8 = -1; dx8 <= 1; dx8++)
    for (int dy8 = -1; dy8 <= 1; dy8++) if (dx8 || dy8) {
      int nx = cur.first + dx8, ny = cur.second + dy8;
      if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
      if (was[ny][nx] >= ver) continue;
      if (f[ny][nx] != 0) continue;
      was[ny][nx] = ver;
      q.pb(mp(nx, ny));
    }
  }

  vector<pii> pts;
  for (int i = 0; i < sz(spts); i++) {
    if (spts[i].first == 0 || spts[i].first == w - 1) return;
    if (spts[i].second == 0 || spts[i].second == h - 1) return;
    for (int dx8 = -1; dx8 <= 1; dx8++)
    for (int dy8 = -1; dy8 <= 1; dy8++) if (dx8 || dy8) {
      int nx = spts[i].first + dx8;
      int ny = spts[i].second + dy8;
      if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
      if (f[ny][nx] != 1) continue;
      pts.pb(mp(nx, ny));
    }
  }
  sort(pts.begin(), pts.end());
  pts.resize(unique(pts.begin(), pts.end()) - pts.begin());

  if (!sz(pts)) return;

  ver++;
  q.clear();
  int rcnt = 0;
  q.pb(pts[0]); was[pts[0].second][pts[0].first] = ver;
  while (!q.empty()) {
    pii cur = q.front(); q.pop_front();
    rcnt++;
    for (int i = 0; i < 4; i++) {
      int nx = cur.first + dx[i], ny = cur.second + dy[i];
      if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
      if (was[ny][nx] >= ver) continue;
      if (!binary_search(pts.begin(), pts.end(), mp(nx, ny))) continue;
      was[ny][nx] = ver;
      q.pb(mp(nx, ny));
    }
  }
  if (rcnt != sz(pts)) return;
  
  for (int i = 0; i < sz(pts); i++) {
    int cnt = 0;
    for (int i2 = 0; i2 < 4; i2++) {
      int nx = pts[i].first + dx[i2];
      int ny = pts[i].second + dy[i2];
      if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
      if (binary_search(pts.begin(), pts.end(), mp(nx, ny)))
        cnt++;
    }
//    eprintf("%d %d: %d\n", pts[i].first, pts[i].second, cnt);
    if (cnt != 2) return;
  }
  ans = max(ans, sz(pts));
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%d%d", &h, &w) >= 1) {
    for (int y = 0; y < h; y++) {
      scanf("%s", f[y]);
      for (int x = 0; x < w; x++)
        f[y][x] -= '0';
    }

    memset(sums, 0, sizeof sums);
    for (int y = 0; y < h; y++)
      for (int x = 0; x < w; x++)
        sums[y + 1][x + 1] = f[y][x] + sums[y][x + 1] + sums[y + 1][x] - sums[y][x];

    was = vvi(h, vi(w, 0));
    ver = 1;

    ans = 0;
    for (int y = 0; y < h; y++)
      for (int x = 0; x < w; x++) if (!was[y][x] && f[y][x] == 0) {
        goZero(x, y);
        ver++;
      }
    for (int y = 0; y + 1 < h; y++)
    for (int x = 0; x + 1 < w; x++)
      if (f[y][x] && f[y + 1][x] && f[y][x + 1] && f[y + 1][x + 1])
        ans = max(ans, 4);
    printf("%d\n", ans);

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}