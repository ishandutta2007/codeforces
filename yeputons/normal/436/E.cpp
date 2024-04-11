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
#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#endif
#define sz(x) ((int)(x).size())
#define forn(i, n) for (int i = 0; i < (n); i++)

#ifdef DEBUG
struct Timestamper {
  string msg;
  clock_t start;

  Timestamper(const string &_msg) : msg(_msg), start(clock()) {}
  ~Timestamper() {
    eprintf("[ %s ] Time=%.3lfs\n", msg.c_str(), (clock() - start) * 1.0 / CLOCKS_PER_SEC);
  }
} __timestamper("end");
#else
struct Timestamper {};
#endif

typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

const int inf = 1e9;

  typedef struct _node {
    int x, y, cnt;
    ll sum;
    _node *l, *r;

    explicit _node(int _x = 0)
        : x(_x)
        , y((rand() << 16) ^ rand())
        , cnt(1)
        , sum(ll(x))
        , l(nullptr)
        , r(nullptr) {}

    void recalc() {
      sum = x;
      cnt = 1;
      if (l) sum += l->sum, cnt += l->cnt;
      if (r) sum += r->sum, cnt += r->cnt;
    }
  } *node;
  const int BFSZ = 3e6;
  _node memnode[BFSZ];
  int memptr = 0;

  node newnode(int x) {
    return &(memnode[memptr++] = _node(x));
  }

class Magic {

  node merge(node l, node r) {
    if (!l || !r) return l ? l : r;
    if (l->y < r->y) {
      l->r = merge(l->r, r);
      l->recalc();
      return l;
    } else {
      r->l = merge(l, r->l);
      r->recalc();
      return r;
    }
  }
  void split_cnt(node v, int key, node &l, node &r) {
    if (!v) { l = r = nullptr; return; }
    int lcnt = v->l ? v->l->cnt : 0;
    if (key <= lcnt) {
      split_cnt(v->l, key, l, v->l);
      r = v; v->recalc();
    } else {
      split_cnt(v->r, key - lcnt - 1, v->r, r);
      l = v; v->recalc();
    }
  }
  void split_key(node v, int key, node &l, node &r) {
    if (!v) { l = r = nullptr; return; }
    if (key < v->x) {
      split_key(v->l, key, l, v->l);
      r = v; v->recalc();
    } else {
      split_key(v->r, key, v->r, r);
      l = v; v->recalc();
    }
  }

  node getLeftMost(node v) {
    assert(v);
    if (!v->l) return v;
    return getLeftMost(v->l);
  }
  void deleteRightMost(node &v, int x) {
    assert(v);
    if (v->r) {
      deleteRightMost(v->r, x);
      v->recalc();
    } else {
      assert(v->x == x);
      node ne = v->l;
      v->l = nullptr;
//      delete v;
      v = ne;
    }
  }

  int getKth(node v, int cnt) {
    int lcnt = v->l ? v->l->cnt : 0;
    if (cnt < lcnt) return getKth(v->l, cnt);
    else cnt -= lcnt;
    if (!cnt) return v->x;
    else cnt--;
    return getKth(v->r, cnt);
  }

  node root;

public:
  Magic() : root(nullptr) {} 
  void add(int x) {
    node l, r;
    split_key(root, x, l, r);
    root = merge(merge(l, newnode(x)), r);
  }
  void del(int x) {
    node l, r;
    split_key(root, x, l, r);
    deleteRightMost(l, x);
    root = merge(l, r);
  }
  size_t size() const { return root ? root->cnt : 0; }
  ll getSumK(int k) {
    node l, r;
    split_cnt(root, k, l, r);
    ll res = l ? l->sum : 0;
    root = merge(l, r);
    return res;
  }
  int getKth(int k) {
    return getKth(root, k);
/*    node l, r;
    split_cnt(root, k, l, r);
    int val = getLeftMost(r)->x;
    root = merge(l, r);
    return val;*/
  }
};

struct Lev {
  int a, b, id;
  bool operator<(const Lev &l2) const {
    if (b != l2.b) return b < l2.b;
    return a < l2.a;
  }
};

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int n, w;
  while (scanf("%d%d", &n, &w) >= 1) {
    eprintf("n=%d\n", n);
    vector<Lev> ls(n);
    forn (i, n)
      scanf("%d%d", &ls[i].a, &ls[i].b), ls[i].id = i;
    sort(ls.begin(), ls.end());

    ll ans = 9e18;
    int ac2 = -1, ack1 = -1, ack2 = -1;

    Magic rems, diffs;
    forn (i, n) rems.add(ls[i].a);

    ll csum = 0;
    for (int c2 = 0; c2 <= n; c2++) {
      assert(sz(rems) == n - c2);
      int need = max(0, w - 2 * c2);
      if (need <= sz(rems)) {
        int candel = min(max(0, 2 * c2 - w), sz(diffs));
        int ff2 = candel;
        
        int L = -1, R = min(sz(rems) - need, sz(diffs) - ff2);
        while (L + 1 < R) {
          int M = (L + R) / 2;
          ll diff = rems.getKth(need + M) + diffs.getKth(ff2 + M);
          if (diff < 0) L = M;
          else R = M;
        }
        int ff1 = L + 1;

        ll csum2 = csum + rems.getSumK(need + ff1) + diffs.getSumK(ff1 + ff2);
        if (csum2 < ans) {
          ans = csum2;
          ac2 = c2;
          ack1 = need + ff1;
          ack2 = ff1 + ff2;
        }
      }

      if (c2 < n) {
        csum += ls[c2].b;
        diffs.add(ls[c2].a - ls[c2].b);
        rems.del(ls[c2].a);
      }
    }

    printf("%I64d\n", ans);

    vi res(n, 0);
    {
      multiset<pii> mrems, mdiffs;
      for (int i = 0; i < ac2; i++) {
        mdiffs.insert(mp(ls[i].a - ls[i].b, ls[i].id));
        res[ls[i].id] = 2;
      }
      for (int i = ac2; i < n; i++) {
        mrems.insert(mp(ls[i].a, ls[i].id));
      }
      for (; ack1 > 0; ack1--) {
        assert(!mrems.empty());
        auto v = *mrems.begin(); mrems.erase(mrems.begin());
        assert(res[v.second] == 0);
        res[v.second] = 1;
      }
      for (; ack2 > 0; ack2--) {
        assert(!mdiffs.empty());
        auto v = *mdiffs.begin(); mdiffs.erase(mdiffs.begin());
        assert(res[v.second] == 2);
        res[v.second] = 1;
      }
    }
    for (int i = 0; i < n; i++)
      printf("%d", res[i]);
    printf("\n");
  }
  return 0;
}