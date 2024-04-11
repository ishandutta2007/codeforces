#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
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

class fenv_tree_2d {
  vvi tr;
  static int f(int x) { return x ^ (x & (x - 1)); }

  int get(int sx, int y) {
    int res = 0;
    for (; y > 0; y -= f(y))
    for (int x = sx; x > 0; x -= f(x)) {
      res += tr[y][x];
    }
    return res;
  }

  public:
  fenv_tree_2d(int h = 0, int w = 0) : tr(h + 1, vi(w + 1)) {}
  fenv_tree_2d(const vvi &init) : tr(sz(init) + 1, vi(sz(init[0]) + 1)) {
    for (int y = 0; y < sz(init); y++) {
      for (int x = 0; x < sz(init[y]); x++)
        tr[y + 1][x + 1] = init[y][x];

      for (int x = 0; x < sz(tr[y]); x++)
        if (x + f(x) < sz(tr[y]))
          tr[y][x + f(x)] += tr[y][x];
    }

    for (int y = 0; y < sz(tr); y++) if (y + f(y) < sz(tr)) {
      for (int x = 0; x < sz(tr[y]); x++)
        tr[y + f(y)][x] += tr[y][x];
    }
  }
  int get(int y1, int y2, int x1, int x2) { 
    y1 = max(y1, 0); y2 = min(y2, sz(tr) - 2);
    x1 = max(x1, 0); x2 = min(x2, sz(tr[0]) - 2);
    if (y1 > y2 || x1 > x2) return 0;

    y2++, x2++;
    return get(x2, y2) - get(x1, y2) - get(x2, y1) + get(x1, y1);
  }
  void add(int y, int sx, int k) {
    y++, sx++;
    assert(0 < y && y < sz(tr));
    assert(0 < sx && sx < sz(tr[0]));
    for (; y < sz(tr); y += f(y))
      for (int x = sx; x < sz(tr[y]); x += f(x)) {
        tr[y][x] += k;
      }
  }
};

fenv_tree_2d trs;
int h, w;

pii getp(int xy, int xyh) {
  int x = xy + xyh - (h - 1);
  assert(!(x & 1)); x >>= 1;
  int y = xy - x;
  assert(x + y == xy);
  assert(x - y + h - 1 == xyh);
  return mp(y, x);
}

bool check(int x, int y, int d) {
  int x1 = x - d + y, x2 = x + d + y;
  int y1 = x - y - d + h - 1, y2 = x - y + d + h - 1;

  return trs.get(x1, x2, y1, y2) > 0;
}

pii getMinX(int x, int y1, int y2) {
  if (trs.get(x, x, y1, y2) == 0) return mp(1e9, 1e9);

  int L = y1, R = y2 + 1;
  while (L + 1 < R) {
    int M = (L + R) / 2;
    if (trs.get(x, x, M, y2) > 0) L = M;
    else R = M;
  }
  return getp(x, L);
}
pii getMinY(int y, int x1, int x2) {
  if (trs.get(x1, x2, y, y) == 0) return mp(1e9, 1e9);

  int L = x1 - 1, R = x2;
  while (L + 1 < R) {
    int M = (L + R) / 2;
    assert(L < M && M < R);
    if (trs.get(x1, M, y, y) > 0) R = M;
    else L = M;
  }
  return getp(R, y);
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int k;
  while (scanf("%d%d%d", &h, &w, &k) >= 1) {
    eprintf("start\n");
    {
      vvi init(h + w, vi(h + w));
      for (int y = 0; y < h; y++)
      for (int x = 0; x < w; x++)
        init[x + y][x - y + h - 1] = 1;
      eprintf("build\n");
      trs = fenv_tree_2d(init);
    }
    eprintf("go\n");

    while (k --> 0) {
      int x, y;
      scanf("%d%d", &y, &x), x--, y--;
      int ax = -1, ay = -1;
      if (check(x, y, 0)) {
        ax = x; ay = y;
      } else {
        int L = 0, R = 3 * max(h, w);
        assert(check(x, y, R));
        while (L + 1 < R) {
          int M = (L + R) / 2;
          if (!check(x, y, M)) L = M;
          else R = M;
        }

        int d = R;

        int x1 = x - d + y, x2 = x + d + y;
        int y1 = x - y - d + h - 1, y2 = x - y + d + h - 1;

        pii res = min(getMinX(x1, y1, y2), getMinX(x2, y1, y2));
        res = min(res, min(getMinY(y1, x1, x2), getMinY(y2, x1, x2)));
        ax = res.second;
        ay = res.first;
      }
      trs.add(ax + ay, ax - ay + h - 1, -1);
      printf("%d %d\n", ay + 1, ax + 1);
    }
    #ifdef DEBUG
    printf("\n");
    #endif
  }
  return 0;
}