#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>

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

const int INF = 1e9 + 1e6;

class Solver {
  struct Edge {
    int b, revi;
    int w, c;

    Edge(int _b, int _revi, int _w, int _c) : b(_b), revi(_revi), w(_w), c(_c) {}
  };
  int n;
  vector<vector<Edge> > es;

  public:
  Solver(int _n) : n(_n), es(n) {}
  int adde(int a, int b, int w, int c) {
    int ai = sz(es[a]);
    int bi = sz(es[b]);

    es[a].pb(Edge(b, bi, w, c));
    es[b].pb(Edge(a, ai, 0, -c));
    return ai;
  }
  int getRem(int a, int id) { return es[a][id].w; }
  void solve(int maxfl) {
    for (int step = 0; step < maxfl; step++) {
      vi ds(n, INF), fr(n, -1), fre(n, -1);
      ds[0] = 0;
      deque<int> q;
      vb inq(n, false);
      q.pb(0); inq[0] = true;

      while (!q.empty()) {
        int v = q.front(); q.pop_front(); inq[v] = false;
        for (int i = 0; i < sz(es[v]); i++) if (es[v][i].w > 0) {
          int b = es[v][i].b;
          if (ds[b] > ds[v] + es[v][i].c) {
            ds[b] = ds[v] + es[v][i].c;
            fr[b] = v; fre[b] = i;
            if (!inq[b]) {
              inq[b] = true;
              q.pb(b);
            }
          }
        }
      }

      for (int v = 0; v < n; v++)
      for (int i = 0; i < sz(es[v]); i++)
        es[v][i].c += ds[v] - ds[es[v][i].b];

      if (ds[n - 1] >= INF) break;
      int v = n - 1;
      for (; v != 0; v = fr[v]) {
        int pr = fr[v], pre = fre[v];
        es[pr][pre].w--;
        es[v][es[pr][pre].revi].w++;
      }
    }
  }
};

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, k;
  while (scanf("%d%d", &n, &k) >= 1) {
    vi ss(n), es(n), cs(n);
    for (int i = 0; i < n; i++)
      scanf("%d%d%d", &ss[i], &es[i], &cs[i]), es[i] += ss[i];

    vi xs = ss;
    xs.pb(2e9 + 1000);
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    Solver s(sz(xs));
    for (int i = 0; i + 1 < sz(xs); i++)
      s.adde(i, i + 1, INF, 0);

    vector<pii> ids(n);
    for (int i = 0; i < n; i++) {
      int a = lower_bound(xs.begin(), xs.end(), ss[i]) - xs.begin();
      int b = lower_bound(xs.begin(), xs.end(), es[i]) - xs.begin();
      ids[i] = mp(a, s.adde(a, b, 1, -cs[i]));
    }
    s.solve(k);
    for (int i = 0; i < n; i++)
      printf("%d%c", 1 - s.getRem(ids[i].first, ids[i].second), "\n "[i + 1 < n]);
  }
  return 0;
}