#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <iostream>

#define pb push_back
#define mp make_pair
#define TASKNAME ""

#ifdef DEBUG
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("[" #x "] Time = %.3lfs\n",clock()*1.0/CLOCKS_PER_SEC)

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

#define sz(x) ((int)(x).size())
#define forn(i, n) for (int i = 0; i < (n); i++)

using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;

const int inf = 1e9;
const double eps = 1e-9;
const int INF = inf;
const double EPS = eps;

#ifdef DEBUG
struct __timestamper {
  ~__timestamper(){
    TIMESTAMP(end);
  }
} __Timestamper;
#else
struct __timestamper {};
#endif

/*Template end*/

class Solver {
  typedef struct _node {
    int x, y, cnt, sum;
    bool rev;
    _node *l, *r;

    _node(int _x) : x(_x), y((rand() << 16) ^ rand()), cnt(1), sum(_x), rev(false), l(nullptr), r(nullptr) {}
    void recalc() {
      cnt = 1; sum = x;
      if (l) cnt += l->cnt, sum += l->sum;
      if (r) cnt += r->cnt, sum += r->sum;
    }
    void norm() {
      if (!rev) return;
      swap(l, r);
      rev = false;
      if (l) l->rev = !l->rev;
      if (r) r->rev = !r->rev;
    }
    ~_node() {
      delete l; l = nullptr;
      delete r; r = nullptr;
    }
  } *node;

  node merge(node l, node r) {
    if (!l || !r) return l ? l : r;
    l->norm(); r->norm();
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
    l = r = nullptr;
    if (!v) return;

    v->norm();
    int lcnt = v->l ? v->l->cnt : 0;
    if (key <= lcnt) {
      split(v->l, key, l, v->l);
      v->recalc();
      r = v;
    } else {
      split(v->r, key - lcnt - 1, v->r, r);
      v->recalc();
      l = v;
    }
  }

  void _add(node v, int key, int val) {
    assert(v);
    assert(0 <= key && key < v->cnt);

    v->norm();
    int lcnt = v->l ? v->l->cnt : 0;
    if (key < lcnt) _add(v->l, key, val);
    else {
      key -= lcnt;
      if (key == 0) v->x += val;
      else {
        key--;
        _add(v->r, key, val);
      }
    }
    v->recalc();
  }
  int _get(node v, int key) {
    assert(v);
    assert(0 <= key && key < v->cnt);

    v->norm();
    int lcnt = v->l ? v->l->cnt : 0;
    
    if (key < lcnt) return _get(v->l, key);
    key -= lcnt;

    if (key == 0) return v->x;
    key--;

    return _get(v->r, key);
  }

  node root;
public:
  Solver() : root(nullptr) {}
  void push_back(int val) {
    root = merge(root, new _node(val));
  }
  int size() const { return root ? root->cnt : 0; }
  void add(int id, int val) {
    _add(root, id, val);
  }
  int getVal(int id) {
    return _get(root, id);
  }
  int getSum(int l, int r) {
    assert(root);
    assert(0 <= l && l <= r && r < root->cnt);

    node L, M1, M2, R;
    split(root, l, L, M1);
    split(M1, r - l + 1, M2, R);
    int res = M2->sum;
    root = merge(merge(L, M2), R);
    return res;
  }
  void eraseFirst(int k) {
    assert(root);
    assert(0 <= k && k <= root->cnt);

    node L, R;
    split(root, k, L, R);
    delete L; L = nullptr;
    root = R;
  }
  void reverseAndPushBackFirst(int k) {
    assert(root);
    assert(0 <= k && k <= root->cnt);
    if (!k) return;

    node L, R;
    split(root, k, L, R);
    assert(L);
    L->rev = !L->rev;
    root = merge(R, L);
  }
};

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int n, q;
  while (scanf("%d%d", &n, &q) == 2) {
    Solver s;
    forn (i, n) s.pb(1);

    while (q --> 0) {
      int ty;
      scanf("%d", &ty);
      if (ty == 1) {
        int len;
        scanf("%d", &len);

        int st = max(0, 2 * len - sz(s));
        int en = len;
        int cnt = en - st;
//        eprintf("%d %d; %d\n", st, en, cnt);
        for (int i = 0; i < cnt; i++) {
          s.add(en + i, s.getVal(en - 1 - i));
        }
        s.reverseAndPushBackFirst(st);
        s.eraseFirst(cnt);
      } else {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", s.getSum(l, r - 1));
      }
    }
    #ifdef DEBUG
    printf("\n");
    #endif
  }

  return 0;
}