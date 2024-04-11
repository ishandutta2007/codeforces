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
#ifdef M_PI
#undef M_PI
#endif
const double M_PI = 4.0 * atan(1.0);

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

struct pt {
  double x, y;
  pt() : x(0), y(0) {}
  pt(double _x, double _y) : x(_x), y(_y) {}
  pt operator+(const pt &p2) const {
    return pt(x + p2.x, y + p2.y);
  }
  pt operator-(const pt &p2) const {
    return pt(x - p2.x, y - p2.y);
  }
  pt operator*(const pt &p2) const {
    return pt(x * p2.x - y * p2.y, x * p2.y + y * p2.x);
  }
  void setLength(const double &l) {
    double cl = sqrt(x * x + y * y);
    assert(fabs(cl) > 1e-9);
    x = x * l / cl;
    y = y * l / cl;
  }
};

struct trans {
  pt a, b;

  trans() : a(1, 0), b() {}
  trans(const pt &_a, const pt &_b) : a(_a), b(_b) {}
  pt operator()(const pt &p) const {
    return a * p + b;
  }
  trans operator*(const trans &n2) const {
    return trans(
      a * n2.a,
      a * n2.b + b
    );
  }
};

#ifdef DEBUG
//#define TREE_DEBUG
#endif
class segm_tree {
  vector<trans> tr;
  #ifdef TREE_DEBUG
  vector<trans> tmp;
  #endif
  int off;

  public:
  segm_tree(int n, const trans &init) {
    off = 1;
    while (off < n) off <<= 1;
    tr = vector<trans>(2 * off);
    #ifdef TREE_DEBUG
    tmp = vector<trans>(n);
    #endif

    for (int i = 1; i < n; i++) {
      tr[off + i] = init;
      #ifdef TREE_DEBUG
      tmp[i] = init;
      #endif
    }
    for (int i = off - 1; i >= 1; i--)
      tr[i] = tr[2 * i] * tr[2 * i + 1];
  }
  trans get(int l, int r) {
    #ifdef TREE_DEBUG
    trans real;
    for (int i = l; i <= r; i++)
      real = real * tmp[i];
    return real;
    #endif
    l += off; r += off;
    trans resl, resr;
    while (l <= r) {
      if (l & 1) resl = resl * tr[l++];
      if (!(r & 1)) resr = tr[r--] * resr;
      l >>= 1;
      r >>= 1;
    }
    return resl * resr;
  }
  void add(int x, const trans &v) {
    #ifdef TREE_DEBUG
    tmp[x] = v * tmp[x];
    #endif
    x += off;
    tr[x] = v * tr[x];
    for (x >>= 1; x >= 1; x >>= 1)
      tr[x] = tr[2 * x] * tr[2 * x + 1];
  }
};

#ifdef DEBUG
//#define PRINT_DEBUG
#endif

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    segm_tree tr(n + 1, trans(pt(1, 0), pt(1, 0)));
    forn (i, m) {
      int ty, id, diff;
      scanf("%d%d%d", &ty, &id, &diff);
      id--;
      assert(0 <= id && id < n);

      #ifdef PRINT_DEBUG
      {
        pt a = tr.get(0, id)(pt());
        pt b = tr.get(0, id + 1)(pt());
        eprintf("a=%.2lf %.2lf; b=%.2lf %.2lf\n", a.x, a.y, b.x, b.y);
      }
      #endif

      trans cur;
      if (ty == 1) {
        pt dir = tr.get(id + 1, id + 1).b;
        dir.setLength(diff);
        cur = trans(pt(1, 0), dir);
      } else {
        double ang = -diff * M_PI / 180;
        pt p(cos(ang), sin(ang));
        cur = trans(p, pt());
      }
//      eprintf("cur=%.2lf %.2lf; %.2lf %.2lf\n", cur.a.x, cur.a.y, cur.b.x, cur.b.y);
      tr.add(id + 1, cur);

      #ifdef PRINT_DEBUG
      for (int i = 0; i <= n; i++) {
        cur = tr.get(i, i);
        eprintf("[%d]=%.2lf %.2lf; %.2lf %.2lf\n", i, cur.a.x, cur.a.y, cur.b.x, cur.b.y);
      }

      {
        pt a, b;
        a = tr.get(0, id)(pt());
        b = tr.get(0, id + 1)(pt());
        eprintf("a=%.2lf %.2lf; b=%.2lf %.2lf\n", a.x, a.y, b.x, b.y);
      }
      #endif

      {
        trans res = tr.get(0, n);
        pt p = res(pt());
        printf("%.10lf %.10lf\n", (double)p.x, (double)p.y);
      }
      eprintf("\n");
    }
  }

  return 0;
}