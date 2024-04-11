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

#define EPS 1e-8
class segm_tree {
  vector<double> tr, trmul;
  vi xs;
  int off;

  void norm(int v) {
    if (fabs(trmul[v] - 1) < EPS) return;
    if (v < off) {
      trmul[2 * v] *= trmul[v];
      trmul[2 * v + 1] *= trmul[v];
    }
    tr[v] *= trmul[v];
    trmul[v] = 1;
  }

  int lr, rr; double vr;
  void _add(int v, int lt, int rt) {
    if (rt < lr || rr < lt) return;
    norm(v);
    if (lr <= lt && rt <= rr) {
      trmul[v] *= vr;
      return;
    }
    int mt = (lt + rt) / 2;
    _add(2 * v, lt, mt);
    _add(2 * v + 1, mt + 1, rt);
    norm(2 * v);
    norm(2 * v + 1);
    tr[v] = tr[2 * v] * tr[2 * v + 1];
  }
  double _get(int v, int lt, int rt) {
    if (rt < lr || rr < lt) return 1;
    norm(v);
    if (lr <= lt && rt <= rr) return tr[v];
    int mt = (lt + rt) / 2;
    return _get(2 * v, lt, mt) * _get(2 * v + 1, mt + 1, rt);
  }

  public:
  segm_tree(const vi &_xs) : xs(_xs) {
    off = 1;
    while (off < sz(xs)) off <<= 1;
    tr = vector<double>(2 * off, 1);
    trmul = vector<double>(2 * off, 1);
  }
  void add(int _l, int _r, double _v) {
    lr = lower_bound(xs.begin(), xs.end(), _l) - xs.begin();
    rr = upper_bound(xs.begin(), xs.end(), _r) - xs.begin() - 1;
    vr = _v;
    _add(1, 0, off - 1);
  }
  double get(int x) {
    lr = rr = lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    return _get(1, 0, off - 1);
  }
};

struct Tr {
  int x, h;
  double l, r;
};
struct Mush {
  int x, id;
  double p;
};

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, m;
  while (scanf("%d%d", &n, &m) >= 1) {
    vector<Tr> ts(n);
    for (int i = 0; i < n; i++) {
      scanf("%d%d%lf%lf", &ts[i].x, &ts[i].h, &ts[i].l, &ts[i].r);
      ts[i].l /= 100.0;
      ts[i].r /= 100.0;
    }
    vector<Mush> ms(m);
    for (int i = 0; i < m; i++)
      scanf("%d%lf", &ms[i].x, &ms[i].p), ms[i].id = i;

    vi xs;
    for (int i = 0; i < m; i++)
      xs.pb(ms[i].x);
    sort(xs.begin(), xs.end());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());

    segm_tree tr(xs);
    for (int i = 0; i < n; i++) {
      tr.add(ts[i].x - ts[i].h, ts[i].x - 1, 1 - ts[i].l);
      tr.add(ts[i].x + 1, ts[i].x + ts[i].h, 1 - ts[i].r);
    }

    double res = 0;
    for (int i = 0; i < m; i++)
      res += ms[i].p * tr.get(ms[i].x);
    printf("%.18lf\n", res);
  }
  return 0;
}