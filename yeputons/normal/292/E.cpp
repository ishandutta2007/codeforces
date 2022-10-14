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

class segm_tree {
  vi trset;
  int off;

  void norm(int v) {
    if (trset[v] < 0 || v >= off) return;
    trset[2 * v] = trset[v];
    trset[2 * v + 1] = trset[v];
    trset[v] = -1;
  }

  int xr;
  int _get(int v, int lt, int rt) {
    if (rt < xr || xr < lt) return -1;
    norm(v);
    if (xr == lt && xr == rt)
      return trset[v];
    int mt = (lt + rt) / 2;
    return max(_get(2 * v, lt, mt), _get(2 * v + 1, mt + 1, rt));
  }

  int lr, rr, vr;
  void _set(int v, int lt, int rt) {
    if (rt < lr || rr < lt) return;
    if (lr <= lt && rt <= rr) {
      trset[v] = vr;
      return;
    }
    norm(v);
    int mt = (lt + rt) / 2;
    _set(2 * v, lt, mt);
    _set(2 * v + 1, mt + 1, rt);
  }
  
  public:
  segm_tree(int n) {
    off = 1; while (off < n) off <<= 1;
    trset = vi(off * 2, -1);
  }
  int get(int x) {
    xr = x;
    return _get(1, 0, off - 1);
  }
  void set(int l, int r, int v) {
    lr = l;
    rr = r;
    vr = v;
    _set(1, 0, off - 1);
  }
};

struct Op {
  int x, y, k;
};

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int n, m;
  while (scanf("%d%d", &n, &m) >= 1) {
    vi as(n), bs(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &as[i]);
    for (int i = 0; i < n; i++)
      scanf("%d", &bs[i]);

    segm_tree tr(n);

    vector<Op> ops(m);
    for (int i = 0; i < m; i++) {
      int t;
      scanf("%d", &t);
      if (t == 1) {
        int x, y, k;
        scanf("%d%d%d", &x, &y, &k), x--, y--;
        ops[i].x = x;
        ops[i].y = y;
        ops[i].k = k;
        tr.set(y, y + k - 1, i);
      } else {
        int x;
        scanf("%d", &x), x--;
        int id = tr.get(x);
        int res = bs[x];

        if (id >= 0) {
          x -= ops[id].y;
          x += ops[id].x;
          res = as[x];
        }
        printf("%d\n", res);
      }
    }
  }
  return 0;
}