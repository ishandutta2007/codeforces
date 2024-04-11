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

const double eps = 1e-8;
class Solver {
  struct Edge {
    int b, w;
    double c, c0;
    int revi;

    Edge(int b, int w, double c, int revi) : b(b), w(w), c(c), c0(c), revi(revi) {}
  };
  int n;
  vector<vector<Edge> > es;

  public:
  Solver(int n) : n(n), es(n) {}
  void adde(int a, int b, int maxf, double c) {
    int aid = sz(es[a]), bid = sz(es[b]);
    es[a].pb(Edge(b, maxf, c, bid));
    es[b].pb(Edge(a, 0, -c, aid));
  }
  pair<int, double> solve() {
    int curf = 0; double curc = 0;
    for (;;) {
      vector<double> d(n, 1e100);
      vi fr(n, -1), fre(n, -1);
      d[0] = 0;
      vb red(n, false);
      for (;;) {
        double minv = 1e100; int mini = -1;
        for (int i = 0; i < n; i++) if (!red[i] && minv - eps > d[i]) {
          minv = d[i];
          mini = i;
        }
        if (mini < 0) break;

//        eprintf("d[%d]=%.2lf, fr=%d\n", mini, minv, fr[mini]);
        red[mini] = true;
        for (int i2 = 0; i2 < sz(es[mini]); i2++) if (es[mini][i2].w > 0) {
          int b = es[mini][i2].b;
          double nd = minv + es[mini][i2].c;
          if (d[b] <= nd + eps) continue;

//          eprintf("  -->%d (%.2lf %.2lf)\n", b, es[mini][i2].c, nd);
          d[b] = nd;
          fr[b] = mini;
          fre[b] = i2;
        }
      }
      if (!red[n - 1]) break;

      curf++;
      for (int v = n - 1; v > 0;) {
        int x = fr[v], xi = fre[v];
        assert(es[x][xi].b == v);
        curc += es[x][xi].c0;
        assert(es[x][xi].w > 0);
        es[x][xi].w--;
        es[v][es[x][xi].revi].w++;
        v = x;
      }
      for (int i = 0; i < sz(es); i++)
      for (int i2 = 0; i2 < sz(es[i]); i2++) {
        es[i][i2].c += d[i] - d[es[i][i2].b];
        if (es[i][i2].w > 0)
          assert(es[i][i2].c >= -eps);
      }

//      eprintf("%d %.2lf\n", curf, curc);
    }
    return mp(curf, curc);
  }
};

struct pt {
  int x, y;
  pt() : x(0), y(0) {}
  pt(int x, int y) : x(x), y(y) {}
  pt operator-(const pt &p2) const { return pt(x - p2.x, y - p2.y); }
  double dist() const { return sqrt(x * x + y * y); }
};

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vector<pt> pts(n);
    for (int i = 0; i < n; i++)
      scanf("%d%d", &pts[i].x, &pts[i].y);

    Solver s(2 * n + 2);
    for (int i = 0; i < n; i++) {
      s.adde(0, 1 + i, 1, 0);
      for (int j = 0; j < n; j++)
        if (pts[i].y < pts[j].y)
          s.adde(1 + i, 1 + n + j, 1, (pts[i] - pts[j]).dist());
      s.adde(1 + n + i, 1 + n + n, 2, 0);
    }
    pair<int, double> res = s.solve();
    if (res.first != n - 1) printf("-1\n");
    else printf("%.18lf\n", res.second);
  }
  return 0;
}