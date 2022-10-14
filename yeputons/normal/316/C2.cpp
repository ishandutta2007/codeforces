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

const int inf = 1e9;

class Solver {
  int n;
  vvi c0;

  #define c(x, y) (c0[x][y] + dx[x] + dy[y])

  vi xy, yx;
  vi dx, dy;
  vb wasx, wasy;

  bool findPair(int x) {
    if (wasx[x]) return false;

    wasx[x] = true;
    for (int y = 0; y < n; y++) if (c(x, y) == 0)
      if (yx[y] < 0) {
        xy[x] = y;
        yx[y] = x;
        return true;
      }
    for (int y = 0; y < n; y++) if (c(x, y) == 0) {
      wasy[y] = true;
      if (findPair(yx[y])) {
        xy[x] = y;
        yx[y] = x;
        return true;
      }
    }
    return false;
  }

  public:
  Solver(int n) : n(n), c0(n, vi(n, inf)) {}
  void adde(int a, int b, int c) {
    assert(0 <= a && a < n);
    assert(0 <= b && b < n);
    c0[a][b] = min(c0[a][b], c);
  }
  int solve() {
    xy = vi(n, -1);
    yx = vi(n, -1);
    dx = vi(n, 0);
    dy = vi(n, 0);
    for (int cnt = 0; cnt < n;) {
      wasx.assign(n, false);
      wasy.assign(n, false);

      int k = 0;
      for (int i = 0; i < n; i++)
        if (xy[i] < 0 && findPair(i))
          k++;
      cnt += k;
      if (k > 0) continue;

      int v = inf;
      for (int x = 0; x < n; x++) if (wasx[x])
        for (int y = 0; y < n; y++) if (!wasy[y]) {
          assert(c(x, y) > 0);
          v = min(v, c(x, y));
        }

      for (int x = 0; x < n; x++) if (wasx[x])
        dx[x] -= v;
      for (int y = 0; y < n; y++) if (wasy[y])
        dy[y] += v;

      #ifdef DEBUG
      for (int y = 0; y < n; y++)
        for (int x = 0; x < n; x++)
          assert(c(x, y) >= 0);
      #endif
    }
    int cans = 0;
    for (int i = 0; i < n; i++) {
      assert(xy[i] >= 0);
      cans += c0[i][xy[i]];
    }
    return cans;
  }
  #undef c
};

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int h, w;
  while (scanf("%d%d", &h, &w) >= 1) {
    vvi f(h, vi(w));
    for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++)
      scanf("%d", &f[y][x]);

    vvi ids(h, vi(w, -1));
    {
      int is[2] = { 0 };
      for (int y = 0; y < h; y++)
      for (int x = 0; x < w; x++) {
        int t = (x + y) % 2;
        ids[y][x] = is[t]++;
      }
    }

    Solver s(h * w / 2);
    for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++) if ((x + y) % 2 == 0) {
      for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;

        s.adde(ids[y][x], ids[ny][nx], f[y][x] == f[ny][nx] ? 0 : 1);
      }
    }

    int res = s.solve();
    int ans = res;
    printf("%d\n", ans);
  }
  return 0;
}