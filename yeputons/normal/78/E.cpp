#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdarg>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

int h, w, t;
vvb can;
vvi lasti;

const int dx[] = { 1, 0, -1 , 0 };
const int dy[] = { 0, 1, 0, -1 };

bool cango(int sx, int sy, int ex, int ey) {
  vvi d(h, vi(w, t + 1));
  d[sy][sx] = 0;

  deque<pii> q;
  q.pb(mp(sx, sy));
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop_front();

    int nd = d[y][x] + 1;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 0 || ny < 0 || nx >= w || ny >= h || !can[ny][nx] || lasti[ny][nx] < nd) continue;
      if (lasti[ny][nx] == nd) {
        if (nx == ex && ny == ey)
          return true;
        continue;
      }

      if (d[ny][nx] > nd) {
        d[ny][nx] = nd;
        q.pb(mp(nx, ny));
      }
    }
  }
  return d[ey][ex] <= t;
}

int n;
vvi es;
vi p, ty;
vi chain;
vb was;

bool dfs(int v) {
  if (was[v]) return false;

  was[v] = true;
  assert(0 <= v && v < n);
  if (ty[v] == 0) {
    for (int i = 0; i < es[v].size(); i++) {
      int b = es[v][i];
      if (dfs(b)) {
        chain.pb(v);
        return true;
      }
    }
  } else {
    if (p[v] < 0 || dfs(p[v])) {
      chain.pb(v);
      return true;
    }
  }
  return false;
}

int findSolution() {
  p = vi(n, -1);

  int ans = 0;
  for (;;) {
    bool g = false;
    for (int i = 0; i < n; i++) if (ty[i] == 0 && p[i] < 0) {
      was = vb(n, false);
      chain.clear();
      if (dfs(i)) {
        reverse(chain.begin(), chain.end());
        assert(chain.size() % 2 == 0);
        for (int i2 = 0; i2 < chain.size(); i2 += 2) {
          p[chain[i2]] = chain[i2 + 1];
          p[chain[i2 + 1]] = chain[i2];
        }
      
        g = true; ans++;
        break;
      }
    }
    if (!g) break;
  }
  return ans;
}

char buf[11];
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%d%d", &h, &t) >= 1) {
    w = h;
    can = vvb(h, vb(w, true));
    vvi cnt1(h, vi(w, 0));
    vvi cnt2(h, vi(w, 0));

    int bx = -1, by = -1;
    for (int y = 0; y < h; y++) {
      scanf("%s", buf);
      for (int x = 0; x < w; x++)
        if (buf[x] >= '0' && buf[x] <= '9') {
          cnt1[y][x] = buf[x] - '0';
        } else {
          can[y][x] = false;
          if (buf[x] == 'Z') { bx = x; by = y; }
        }
    }
    for (int y = 0; y < h; y++) {
      scanf("%s", buf);
      for (int x = 0; x < w; x++)
        if (buf[x] >= '0' && buf[x] <= '9')
          cnt2[y][x] = buf[x] - '0';
    }

    lasti = vvi(h, vi(w, t));
    deque<pii> q;
    lasti[by][bx] = 0; q.pb(mp(bx, by));
    while (!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;
      q.pop_front();
      int nv = lasti[y][x] + 1;
      for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx < 0 || ny < 0 || nx >= w || ny >= h || !can[ny][nx]) continue;
        if (lasti[ny][nx] > nv) {
          lasti[ny][nx] = nv;
          q.pb(mp(nx, ny));
        }
      }
    }

    n = 0;
    ty = vi();
    vvi sids1(h, vi(w, -1));
    vvi sids2(h, vi(w, -1));
    for (int y = 0; y < h; y++)
      for (int x = 0; x < w; x++) {
        sids1[y][x] = n; n += cnt1[y][x];
        sids2[y][x] = n; n += cnt2[y][x];

        for (int i = 0; i < cnt1[y][x]; i++) ty.pb(0);
        for (int i = 0; i < cnt2[y][x]; i++) ty.pb(1);
      }
    es = vvi(n);

    for (int y1 = 0; y1 < h; y1++)
    for (int x1 = 0; x1 < w; x1++) if (cnt1[y1][x1])
    for (int y2 = 0; y2 < h; y2++)
    for (int x2 = 0; x2 < w; x2++) if (cnt2[y2][x2])
      if (cango(x1, y1, x2, y2)) {
        eprintf("%d,%d --> %d,%d\n", x1, y1, x2, y2);
        for (int a = 0; a < cnt1[y1][x1]; a++)
        for (int b = 0; b < cnt2[y2][x2]; b++) {
          int aid = sids1[y1][x1] + a;
          int bid = sids2[y2][x2] + b;
          es[aid].pb(bid);
          es[bid].pb(aid);
        }
      }

    printf("%d\n", findSolution());

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}