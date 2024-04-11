#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
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

const int INF = 1e9;
class Solver {
  int n;
  vvi es, esw;

  public:
  Solver(int n) : n(n), es(n), esw(n) {}
  void adde(int a, int b, int w) {
    es[a].pb(b);
    esw[a].pb(w);
  }

  bool solve(int st) {
    vi need;
    for (int i = 0; i < n; i++) if (i == st || !es[i].empty())
      need.pb(i);

    int k = sz(need);
    vi d(n, INF);
    d[st] = 0;
    for (int step = 0;; step++) {
      bool ch = false;
      for (int _i = 0; _i < k; _i++) {
        int v = need[_i];
        if (d[v] >= INF) continue;
        for (int i2 = 0; i2 < sz(es[v]); i2++) {
          int b = es[v][i2], nw = d[v] + esw[v][i2];
          if (d[b] > nw) {
            d[b] = nw;
            ch = true;
          }
        }
      }
      if (!ch) break;
      if (step > k && ch)
        return true;
    }
    return false;
  }
};

const int MAXH = 2000;
const int MAXW = 2000;

char f[MAXH][MAXW + 1];
const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };
const int dty[] = { 0, 1, 0, 1 };
const int dk[] = { 1, 1, -1, -1 };

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int h, w;
  while (scanf("%d%d", &h, &w) >= 1) {
    int sx = -1, sy = -1;
    for (int y = 0; y < h; y++) {
      scanf("%s", f[y]);
      for (int x = 0; x < w; x++) if (f[y][x] == 'S') {
        f[y][x] = '.';
        sx = x;
        sy = y;
      }
    }

    for (int cty = 0; cty < 2; cty++) {
      vvi was(h, vi(w, 0));
      int cid = 1;
      for (int y0 = 0; y0 < h; y0++)
      for (int x0 = 0; x0 < w; x0++) if (!was[y0][x0] && f[y0][x0] == '.') {
        was[y0][x0] = cid;
        deque<pii> q;
        q.pb(mp(x0, y0));
        while (!q.empty()) {
          int x = q.front().first, y = q.front().second; q.pop_front();
          for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= w || ny >= h) {
              if (dty[d] == cty) continue;
              nx += w; while (nx >= w) nx -= w;
              ny += h; while (ny >= h) ny -= h;
            }
            if (was[ny][nx] || f[ny][nx] == '#') continue;
            was[ny][nx] = cid;
            q.pb(mp(nx, ny));
          }
        }
        cid++;
      }
/*      for (int y = 0; y < h; y++)
      for (int x = 0; x < w; x++)
        eprintf("%d%c", was[y][x], "\n "[x + 1 < w]);*/

      for (int ck = -1; ck <= 1; ck += 2) {
        Solver s(cid);
        for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++) if (was[y][x]) {
          for (int d = 0; d < 4; d++) if (dty[d] == cty) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && ny >= 0 && nx < w && ny < h) continue;

            nx += w; while (nx >= w) nx -= w;
            ny += h; while (ny >= h) ny -= h;
            if (!was[ny][nx]) continue;
            s.adde(was[y][x], was[ny][nx], dk[d] * ck);
          }
        }
        if (s.solve(was[sy][sx])) {
          printf("Yes\n");
          goto end;
        }
      }
    }

    printf("No\n");
    end:;
  }
  return 0;
}