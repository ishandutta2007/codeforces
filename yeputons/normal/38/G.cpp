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

const int INF = 1e9;

class Solver {
  typedef struct _node {
    static _node NUL;

    _node *l, *r;
    int y;
    int cnt;

    int a, maxa, id;

    _node() : l(&NUL), r(&NUL), y(0x3FFFFFFF), cnt(0), a(-INF), maxa(-INF), id(-1) {}
    _node(int _a, int _id) : l(&NUL), r(&NUL), y((rand() << 16) | rand()), cnt(1), a(_a), maxa(_a), id(_id) {}
    ~_node() {
      if (l != &NUL) delete l;
      if (r != &NUL) delete r;
    }
    void recalc() {
      cnt = 1 + l->cnt + r->cnt;
      maxa = max(a, max(l->maxa, r->maxa));
    }
    bool nul() { return this == &NUL; }
  } *node;
  
  node merge(node l, node r) {
    if (l->nul()) return r;
    if (r->nul()) return l;

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
    l = r = &_node::NUL;
    if (v->nul()) return;

    node tmp;
    if (v->l->cnt >= key) {
      split(v->l, key, l, tmp);
      v->l = tmp;
      v->recalc();
      r = v;
    } else {
      split(v->r, key - v->l->cnt - 1, tmp, r);
      v->r = tmp;
      v->recalc();
      l = v;
    }
  }

  node root;
  vi *res;

  void dump(node v) {
    if (v->nul()) return;
    dump(v->l);
    res->pb(v->id);
    dump(v->r);
  }

  public:
  Solver() : root(&_node::NUL) {}

  void insert(int a, int c, int id) {
    int cpos = 0;
    for (node v = root; !v->nul();) {
      if (v->maxa < a) { cpos += v->cnt; break; }
      if (v->l->maxa >= a) {
        v = v->l;
        continue;
      } else
        cpos += v->l->cnt;
      if (v->a >= a) {
        break;
      } else
        cpos++;
      v = v->r;
    }
    cpos = min(cpos, c);

    node l, r;
    split(root, cpos, l, r);
    assert(l->cnt == cpos);
    root = merge(merge(l, new _node(a, id)), r);
  }
  void get(vi &_res) {
    res = &_res;
    dump(root);
    reverse(res->begin(), res->end());
  }
};
Solver::_node Solver::_node::NUL;

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    Solver s;
    for (int i = 0; i < n; i++) {
      int a, c;
      scanf("%d%d", &a, &c);
      s.insert(a, c, i);
    }

    vi res;
    s.get(res);
    for (int i = 0; i < n; i++)
      printf("%d%c", res[i] + 1, "\n "[i + 1 < n]);
  }
  return 0;
}