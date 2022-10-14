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

class fenv_tree_2d {
  inline static int f(int x) { return x & -x; }
  vector<vector<ll> > tr;

  public:
  fenv_tree_2d(int n = 0) : tr(n + 1, vector<ll>(n + 1, 0)) {}
  void update(int x0, int y0, ll v) {
    for (int y = y0 + 1; y < sz(tr); y += f(y))
    for (int x = x0 + 1; x < sz(tr[y]); x += f(x))
      tr[y][x] ^= v;
  }
  ll get(int x0, int y0) {
    ll res = 0;
    for (int y = y0 + 1; y > 0; y -= f(y))
    for (int x = x0 + 1; x > 0; x -= f(x))
      res ^= tr[y][x];
    return res;
  }
};

class Solver {
  fenv_tree_2d trs[2][2];
  int n, n2;

  public:
  Solver(int n) : n(n), n2((n + 1) / 2) {
    for (int a = 0; a < 2; a++)
    for (int b = 0; b < 2; b++)
      trs[a][b] = fenv_tree_2d(n2);
  }
  void update(int x, int y, ll v) {
    trs[x & 1][y & 1].update(x >> 1, y >> 1, v);
  }
  ll get(int x, int y) {
    return trs[x & 1][y & 1].get(x >> 1, y >> 1);
  }
};

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int n, m;
  while (scanf("%d%d", &n, &m) >= 1) {
    Solver tr(n);
    while (m --> 0) {
      int ty;
      int x1, y1, x2, y2;
      scanf("%d", &ty);
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
      x1--, y1--, x2--, y2--;

      if (ty == 1) {
        // query
        ll ans = tr.get(x2, y2);
        if (x1) ans ^= tr.get(x1 - 1, y2);
        if (y1) ans ^= tr.get(x2, y1 - 1);
        if (x1 && y1) ans ^= tr.get(x1 - 1, y1 - 1);
        printf("%I64d\n", ans);
      } else {
        // change
        assert(ty == 2);
        ll val;
        scanf("%I64d", &val);
        tr.update(x1, y1, val);
        if (x2 < n) tr.update(x2 + 1, y1, val);
        if (y2 < n) tr.update(x1, y2 + 1, val);
        if (x2 < n && y2 < n) tr.update(x2 + 1, y2 + 1, val);
      }
    }
  }
  return 0;
}