#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <list>

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
vb deled;

class segm_tree {
  vector<list<int> > tr;
  vi xs;
  int off;

  int lr, rr, rv;
  void _norm(int v) {
    while (!tr[v].empty() && deled[tr[v].front()])
      tr[v].pop_front();
  }
  void _add(int v, int lt, int rt) {
    if (rt <= lr || rr <= lt) return;
    if (lr <= lt && rt <= rr) {
      assert(tr[v].empty() || tr[v].back() <= rv);
      tr[v].pb(rv);
      return;
    }
    int m = (lt + rt) / 2;
    _add(2 * v, lt, m);
    _add(2 * v + 1, m, rt);
  }
  int _get(int v, int lt, int rt) {
    if (rt <= lr || rr <= lt) return INF;
    _norm(v);
    int res = tr[v].empty() ? INF : *tr[v].begin();
    if (v < off) {
      int m = (lt + rt) / 2;
      res = min(res, _get(2 * v, lt, m));
      res = min(res, _get(2 * v + 1, m, rt));
    }
    return res;
  }

  public:
  segm_tree() : off(0) {}
  segm_tree(const vi &_xs) : xs(_xs) {
    sort(xs.begin(), xs.end());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
    off = 1; while (off < sz(xs)) off <<= 1;
    tr = vector<list<int> >(2 * off);
  }
  segm_tree(const segm_tree &t1, const segm_tree &t2) {
    xs = vi(sz(t1.xs) + sz(t2.xs));
    merge(t1.xs.begin(), t1.xs.end(), t2.xs.begin(), t2.xs.end(), xs.begin());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
    off = 1; while (off < sz(xs)) off <<= 1;
    tr = vector<list<int> >(2 * off);
  }

  void add(int _l, int _r, int _v) {
    lr = lower_bound(xs.begin(), xs.end(), _l) - xs.begin();
    rr = lower_bound(xs.begin(), xs.end(), _r) - xs.begin();
    rv = _v;
    _add(1, 0, off);
  }
  int get(int x) {
    lr = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    rr = lr + 1;
    return _get(1, 0, off);
  }
};

struct pt {
  int x, y;
};
class segm_tree_2d {
  vector<segm_tree > tr;
  vi xs;
  int off;

  int lr, rr, rv;
  int y1, y2;
  void _add(int v, int lt, int rt) {
    if (rt <= lr || rr <= lt) return;
    if (lr <= lt && rt <= rr) {
      tr[v].add(y1, y2, rv);
      return;
    }
    int m = (lt + rt) / 2;
    _add(2 * v, lt, m);
    _add(2 * v + 1, m, rt);
  }
  int _get(int v, int lt, int rt) {
    if (rt <= lr || rr <= lt) return INF;
    int res = tr[v].get(y1);
    if (v < off) {
      int m = (lt + rt) / 2;
      res = min(res, _get(2 * v, lt, m));
      res = min(res, _get(2 * v + 1, m, rt));
    }
    return res;
  }

  public:
  segm_tree_2d(const vector<pt> &pts) {
    for (int i = 0; i < sz(pts); i++)
      xs.pb(pts[i].x);
    sort(xs.begin(), xs.end());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
    off = 1; while (off < sz(xs)) off <<= 1;

    tr = vector<segm_tree>(2 * off);
    vvi ys(sz(xs));
    for (int i = 0; i < sz(pts); i++)
      ys[lower_bound(xs.begin(), xs.end(), pts[i].x) - xs.begin()].pb(pts[i].y);
    for (int i = 0; i < sz(xs); i++) {
      tr[off + i] = segm_tree(ys[i]);
    }
    for (int i = off - 1; i >= 1; i--)
      tr[i] = segm_tree(tr[2 * i], tr[2 * i + 1]);
  }

  void add(int _l, int _r, int _y1, int _y2, int _v) {
    lr = lower_bound(xs.begin(), xs.end(), _l) - xs.begin();
    rr = lower_bound(xs.begin(), xs.end(), _r) - xs.begin();
    y1 = _y1; y2 = _y2;
    rv = _v;
    _add(1, 0, off);
  }
  int get(int x, int y) {
    lr = lower_bound(xs.begin(), xs.end(), x) - xs.begin(); rr = lr + 1;
    y1 = y; y2 = y + 1;
    return _get(1, 0, off);
  }
};

struct Rect {
  int x1, x2, y1, y2, z;
};

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vector<Rect> rs(n);

    vi zs;
    for (int i = 0; i < n; i++) {
      scanf("%d%d%d%d%d", &rs[i].x1, &rs[i].x2, &rs[i].y1, &rs[i].y2, &rs[i].z);
      zs.pb(rs[i].z);
      rs[i].x2++, rs[i].y2++;
    }
    sort(zs.begin(), zs.end());
    assert(unique(zs.begin(), zs.end()) == zs.end());

    vi ids(n);
    for (int i = 0; i < n; i++) {
      rs[i].z = lower_bound(zs.begin(), zs.end(), rs[i].z) - zs.begin();
      ids[rs[i].z] = i;
    }
    deled = vb(n, false);

    int k;
    scanf("%d", &k);
    vector<pt> pts(k);
    for (int i = 0; i < k; i++)
      scanf("%d%d", &pts[i].x, &pts[i].y);

    eprintf("Create...\n");
    segm_tree_2d tr(pts);
    eprintf("Init...\n");
    for (int _i = 0; _i < n; _i++) {
      int i = ids[_i];
      tr.add(rs[i].x1, rs[i].x2, rs[i].y1, rs[i].y2, rs[i].z);
    }
    eprintf("Solve...\n");

    for (int i = 0; i < k; i++) {
      int z = tr.get(pts[i].x, pts[i].y);
      int id = -1;
      if (z < INF) {
        id = ids[z];
        deled[rs[id].z] = true;
      }
      printf("%d\n", id + 1);
    }
    eprintf("Done.\n");
  }
  return 0;
}