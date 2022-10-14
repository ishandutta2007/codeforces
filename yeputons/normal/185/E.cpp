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

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

const ll INFLL = 1e18;
class fenv_tree {
  vll xs;
  vector<pair<ll, int> > tr;
  static int f(int x) { return x ^ (x & (x - 1)); }

  public:
  fenv_tree(const vll &_xs) : xs(_xs), tr(sz(xs) + 1, mp(INFLL, -1)) {}
  void relax(ll x, const pair<ll, int> &val) {
    x = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    x++;
    assert(0 < x && x < sz(tr));
    for (; x > 0; x -= f(x))
      tr[x] = min(tr[x], val);
  }
  pair<ll, int> get(ll x) {
    x = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    x++;
    assert(0 <= x && x < sz(tr));
    pair<ll, int> res(INFLL, -1);
    for (; x < sz(tr); x += f(x))
      res = min(res, tr[x]);
    return res;
  }
};

struct pt {
  ll x, y;
  pt(ll _x = 0, ll _y = 0) : x(_x), y(_y) {}
  bool operator<(const pt &p2) const { return y != p2.y ? y < p2.y : x < p2.x; }
};

class segm_tree2 {
  vector<vll> tr;
  int off;
  vll ys;

  bool get(const vll &t, ll x1, ll x2) {
    int i = lower_bound(t.begin(), t.end(), x1) - t.begin();
    return i < sz(t) && t[i] <= x2;
  }

  public:
  segm_tree2() {}
  segm_tree2(const vector<pt> &pts) : ys(sz(pts)) {
    for (int i = 0; i < sz(pts); i++)
      ys[i] = pts[i].y;
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    off = 1; while (off <= sz(ys)) off <<= 1;
    tr = vector<vll>(2 * off);

    for (int i = 0; i < sz(pts); i++) {
      int v = lower_bound(ys.begin(), ys.end(), pts[i].y) - ys.begin();
      tr[off + v].pb(pts[i].x);
    }
    for (int i = off; i < sz(tr); i++) {
      sort(tr[i].begin(), tr[i].end());
      tr[i].erase(unique(tr[i].begin(), tr[i].end()), tr[i].end());
    }
    for (int i = off - 1; i >= 1; i--) {
      const vll &l = tr[2 * i], &r = tr[2 * i + 1];
      tr[i].resize(sz(l) + sz(r));
      merge(l.begin(), l.end(), r.begin(), r.end(), tr[i].begin());
      tr[i].erase(unique(tr[i].begin(), tr[i].end()), tr[i].end());
    }
  }
  bool get(ll x1, ll x2, ll y1, ll y2) {
    y1 = lower_bound(ys.begin(), ys.end(), y1) - ys.begin();
    y2 = upper_bound(ys.begin(), ys.end(), y2) - ys.begin() - 1;

    y1 += off; y2 += off;
    while (y1 <= y2) {
      if (y1 & 1) if (get(tr[y1++], x1, x2)) return true;
      if (!(y2 & 1)) if (get(tr[y2--], x1, x2)) return true;
      y1 >>= 1;
      y2 >>= 1;
    }
    return false;
  }
};

struct Ev {
  int ty;
  ll x, y;
  int  id;
  Ev(int _ty, ll _x, ll _y, int _id) : ty(_ty), x(_x), y(_y), id(_id) {}
  bool operator<(const Ev &e2) const {
    if (y != e2.y) return y > e2.y;
    if (x != e2.x) return x > e2.x;
    return ty > e2.ty;
  }
};

ll maxt;
void cross(ll &mix, ll &mxx, ll &miy, ll &mxy, const pt &p) {
  mix = max(mix, p.x - maxt);
  miy = max(miy, p.y - maxt);
  mxx = min(mxx, p.x + maxt);
  mxy = min(mxy, p.y + maxt);
}

vector<pt> subs;
segm_tree2 str;

#ifdef DEBUG
bool _findSubway(ll x1, ll x2, ll y1, ll y2) {
  for (int i = 0; i < sz(subs); i++)
    if (x1 <= subs[i].x && subs[i].x <= x2)
    if (y1 <= subs[i].y && subs[i].y <= y2)
      return true;
  return false;
}
#endif
bool findSubway(ll x1, ll x2, ll y1, ll y2)  {
//  eprintf("%d\n", _findSubway(x1, x2, y1, y2));
  #ifdef DEBUG
  assert(str.get(x1, x2, y1, y2) == _findSubway(x1, x2, y1, y2));
  #endif
  return str.get(x1, x2, y1, y2);
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, m;
  while (scanf("%d%d", &n, &m) >= 1) {
    vector<pt> pts(n);
    subs.resize(m);
    for (int i = 0; i < n; i++)
      scanf("%I64d%I64d", &pts[i].x, &pts[i].y);
    for (int i = 0; i < m; i++)
      scanf("%I64d%I64d", &subs[i].x, &subs[i].y);

    vi nearest(n, -1);
    vll ndist(n, INFLL);
    for (int step = 0; step < 4; step++) {
      vll xs;
      for (int i = 0; i < n; i++) xs.pb(pts[i].x);
      for (int i = 0; i < m; i++) xs.pb(subs[i].x);
      sort(xs.begin(), xs.end());
      xs.erase(unique(xs.begin(), xs.end()), xs.end());

      fenv_tree tr(xs);
      vector<Ev> evs;
      for (int i = 0; i < n; i++)
        evs.pb(Ev(0, pts[i].x, pts[i].y, i));
      for (int i = 0; i < m; i++)
        evs.pb(Ev(1, subs[i].x, subs[i].y, i));
      sort(evs.begin(), evs.end());

      for (int i = 0; i < sz(evs); i++) {
        if (evs[i].ty == 1) {
          tr.relax(evs[i].x, mp(evs[i].x + evs[i].y, evs[i].id));
        } else {
          pair<ll, int> cd = tr.get(evs[i].x);
          if (cd.second >= 0) {
            ll ncand = cd.first - evs[i].x - evs[i].y;
            if (ndist[evs[i].id] > ncand) {
              ndist[evs[i].id] = ncand;
              nearest[evs[i].id] = cd.second;
            }
          }
        }
      }

      if ((step & 1) == 0) {
        for (int i = 0; i < n; i++) pts[i].x = -pts[i].x;
        for (int i = 0; i < m; i++) subs[i].x = -subs[i].x;
      } else {
        for (int i = 0; i < n; i++) pts[i].y = -pts[i].y;
        for (int i = 0; i < m; i++) subs[i].y = -subs[i].y;
      }
    }

/*    #ifdef DEBUG
    for (int a = 0; a < n; a++) {
      ll bd = INFLL;
      for (int b = 0; b < m; b++)
        bd = min(bd, abs(pts[a].x - subs[b].x) + abs(pts[a].y - subs[b].y));
      assert(bd == ndist[a]);
      if (nearest[a] >= 0) {
        int b = nearest[a];
        assert(bd == abs(pts[a].x - subs[b].x) + abs(pts[a].y - subs[b].y));
      }
    }
    #endif*/

    vector<pair<ll, int> > ord(n);
    for (int i = 0; i < n; i++)
      ord[i] = mp(ndist[i], i);
    sort(ord.begin(), ord.end());

    for (int i = 0; i < n; i++) {
      pts[i] = pt(pts[i].x + pts[i].y, pts[i].x - pts[i].y);
    }
    for (int i = 0; i < m; i++) {
      subs[i] = pt(subs[i].x + subs[i].y, subs[i].x - subs[i].y);
    }
    sort(subs.begin(), subs.end());
    str = segm_tree2(subs);

    eprintf("go\n");
    ll L = -1, R = ord[n - 1].first;
    while (L + 1 < R) {
      maxt = (L + R) / 2;

      ll mix = -INFLL, miy = -INFLL;
      ll mxx = INFLL, mxy = INFLL;
      int ptr = n - 1;
      for (; ptr >= 0 && ord[ptr].first > maxt; ptr--) {
        cross(mix, mxx, miy, mxy, pts[ord[ptr].second]);
      }

      for (; ptr >= 0 && mix <= mxx && miy <= mxy; ptr--) {
        ll remt = maxt - ord[ptr].first;
        assert(remt >= 0);
        if (findSubway(mix - remt, mxx + remt, miy - remt, mxy + remt)) {
          break;
        } else {
          cross(mix, mxx, miy, mxy, pts[ord[ptr].second]);
        }
      }
      if (mix <= mxx && miy <= mxy) {
        R = maxt;
      } else
        L = maxt;
    }
    printf("%I64d\n", R);
  }
  return 0;
}