#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>

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

class cart_tree {
  typedef struct _node {
    _node *l, *r;
    int x, y, cnt;

    _node(int _x) : l(0), r(0), x(_x), y((rand() << 16) | rand()), cnt(1) {}
    ~_node() {
      delete l;
      delete r;
    }
    void recalc() {
      cnt = 1;
      if (l) cnt += l->cnt;
      if (r) cnt += r->cnt;
    }
  } *node;

  node merge(node l, node r) {
    if (!l) return r;
    if (!r) return l;

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

  void split(node v, int key, node &l, node &r) {
    l = r = 0;
    if (!v) return;

    if (v->x < key) {
      split(v->r, key, v->r, r);
      v->recalc();
      l = v;
    } else {
      split(v->l, key, l, v->l);
      v->recalc();
      r = v;
    }
  }

  node root;
  public:
  cart_tree() : root(0) {}
  void insert(int x) {
    node l, r;
    split(root, x, l, r);
    root = merge(merge(l, new _node(x)), r);
  }
  void erase(int x) {
    node l, m1, m2, r;
    split(root, x, l, m1);
    split(m1, x + 1, m2, r);
    delete m2; m2 = 0;
    root = merge(l, r);
  }
  // (-inf, key)
  int get(int key) {
    node l, r;
    split(root, key, l, r);
    int res = l ? l->cnt : 0;
    root = merge(l, r);
    return res;
  }
  // [l, r)
  int get(int l, int r) { return get(r) - get(l); }
};
int n;
struct Segm {
  int l, r;
  Segm() : l(0), r(-1) {}
  Segm(int _l, int _r) : l(_l), r(_r) {}
  int len() const { return min(r, n) - max(l, 1) + 1; }
  bool operator<(const Segm &s) const {
    if (len() != s.len())
      return len() > s.len();
    return l > s.l;
  }
};
struct cmpl {
  bool operator()(const Segm &s1, const Segm &s2) const {
    return s1.l < s2.l;
  }
};

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int m;
  while (scanf("%d%d", &n, &m) >= 1) {
    set<Segm> ss;
    set<Segm, cmpl> ss2;
    ss.insert(Segm(0, n + 1));
    ss2.insert(Segm(0, n + 1));

    vi as(m);
    vi ls(m, -1), rs(m, -1);

    for (int i = 0; i < m; i++) {
      scanf("%d", &as[i]);
      if (!as[i])
        scanf("%d%d", &ls[i], &rs[i]);
    }

    cart_tree tr;
    map<int, int> cur;

    for (int id = 0; id < m; id++) {
      if (!as[id]) {
        printf("%d\n", tr.get(ls[id], rs[id] + 1));
      } else {
        if (!cur.count(as[id])) {
          Segm s = *ss.begin();
          ss.erase(s); ss2.erase(s);

          int x = (max(1, s.l) + min(s.r, n) + 1) / 2;
          if (s.l < x) ss.insert(Segm(s.l, x - 1)), ss2.insert(Segm(s.l, x - 1));
          if (x < s.r) ss.insert(Segm(x + 1, s.r)), ss2.insert(Segm(x + 1, s.r));

          tr.insert(x);
          cur[as[id]] = x;
        } else {
          int x = cur[as[id]];
          tr.erase(x);

          set<Segm, cmpl>::iterator it2 = ss2.lower_bound(Segm(x, -1)), it1 = it2;
          assert(it2 != ss2.begin() && it2 != ss2.end());
          it1--;

          Segm s1 = *it1, s2 = *it2;
          Segm s(x, x);
          if (s1.r + 1 == x) {
            ss.erase(s1); ss2.erase(s1);
            s.l = s1.l;
          }
          if (x + 1 == s2.l) {
            ss.erase(s2); ss2.erase(s2);
            s.r = s2.r;
          }
          
          ss.insert(s);
          ss2.insert(s);

          cur.erase(as[id]);
        }
      }
    }
  }
  return 0;
}