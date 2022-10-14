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

class Solver {
  typedef struct _node {
    static _node NUL;

    _node *l, *r;
    int ccnt; 
    double g;

    _node() : l(&NUL), r(&NUL), ccnt(0), g(0) {}
    void recalc() {
      g = ccnt + l->g + r->g;
    }

    void add(int v, int e, int maxp = 30) {
      if (v == 1) {
        ccnt += e;
      } else {
        while ((1 << maxp) > v) maxp--;
        assert(maxp >= 1);
        assert(v & (1 << maxp));
        if ((v & (1 << (maxp - 1))) == 0) {
          if (l == &NUL) l = new _node();
          v ^= 1 << maxp;
          v |= 1 << (maxp - 1);
          l->add(v, e, maxp - 1);
        } else {
          if (r == &NUL) r = new _node();
          v ^= 1 << maxp;
          v |= 1 << (maxp - 1);
          r->add(v, e, maxp - 1);
        }
      }
      recalc();
    }
    double get(double maxv = 0) {
      double res = 0;
      if (l->g != r->g) {
        if (l->g > r->g) {
          res += l->get(max(maxv, r->g + ccnt));
        } else {
          res += r->get(max(maxv, l->g + ccnt));
        }
        res += max(maxv, max(l->g, r->g) + ccnt);
      } else {
        res += 2 * max(maxv, l->g + ccnt);
      }
      return res / 2;
    }
  } *node;

  _node root;

  public:
  Solver() : root() {}
  void add(int v, int e) {
    root.add(v, e);
  }
  double decay() { return root.get(); }
};
Solver::_node Solver::_node::NUL;

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int h, q;
  while (scanf("%d%d", &h, &q) >= 2) {
    Solver s;
    for (int id = 0; id < q; id++) {
      char op[16];
      scanf("%s", op);
      if (!strcmp(op, "add")) {
        int v, e;
        scanf("%d%d", &v, &e);
        s.add(v, e);
      } else {
        assert(!strcmp(op, "decay"));
        printf("%.18lf\n", s.decay());
      }
    }
    break;
  }
  return 0;
}