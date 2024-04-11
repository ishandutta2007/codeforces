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

const int inf = 1e9;

class Solver {
  struct Edge {
    int b, ne, w, c, c0;
    Edge() {}
    Edge(int b, int ne, int w, int c) : b(b), ne(ne), w(w), c(c), c0(c) {}
  };
  vi firs;
  vector<Edge> es;

  public:
  Solver(int n) : firs(n, -1), es() {}
  void adde(int a, int b, int w, int c) {
    es.pb(Edge(b, firs[a], w, c)); firs[a] = sz(es) - 1;
    es.pb(Edge(a, firs[b], 0, -c)); firs[b] = sz(es) - 1;
//    eprintf("%d-->%d (%d %d)\n", a, b, w, c);
  }
  pii solve(int st, int en) {
    const int n = sz(firs);
//    eprintf("st=%d, en=%d\n", st, en);

    {
      vi d(n, inf);
      d[st] = 0;
      for (;;) {
        bool cont = false;
        for (int i = 0; i < sz(es); i++) if (es[i].w > 0) {
          int b = es[i].b, a = es[i ^ 1].b;
          int nw = d[a] + es[i].c;
          if (nw < d[b]) {
            d[b] = nw;
            cont = true;
          }
        }
        if (!cont) break;
      }
      for (int i = 0; i < sz(es); i++) {
        int a = es[i ^ 1].b, b = es[i].b;
        es[i].c += d[a] - d[b];
        if (es[i].w > 0)
          assert(es[i].c >= 0);
      }
    }

    int fl = 0, sumc = 0;
    for (;;) {
      vi d(n, inf), fre(n, -1);
      priority_queue<pii> q;
      d[st] = 0;
      q.push(mp(-d[st], st));

      while (!q.empty()) {
        int cd = -q.top().first;
        int v = q.top().second;
        q.pop();
        if (cd != d[v]) continue;

        for (int i = firs[v]; i >= 0; i = es[i].ne) if (es[i].w > 0) {
          int b = es[i].b;
          int nd = cd + es[i].c;
          if (nd < d[b]) {
            d[b] = nd;
            fre[b] = i;
            q.push(mp(-d[b], b));
          }
        }
      }
      if (d[en] >= inf) break;

//      eprintf("found\n");
      fl++;
      for (int y = en; y != st;) {
        int eid = fre[y];
        sumc += es[eid].c0;
        es[eid].w--;
        es[eid ^ 1].w++;
//        eprintf("  %d-->%d (c0=%d)\n", es[eid ^ 1].b, y, es[eid].c0);
        y = es[eid ^ 1].b;
      }

      for (int i = 0; i < sz(es); i++) {
        int a = es[i ^ 1].b, b = es[i].b;
        es[i].c += d[a] - d[b];
        if (es[i].w > 0)
          assert(es[i].c >= 0);
      }
    }
//    eprintf("fl=%d, sumc=%d\n", fl, sumc);
    return mp(fl, sumc);
  }
};

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int h, w;
  while (scanf("%d%d", &h, &w) >= 1) {
    vvi f(h, vi(w));
    for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++)
      scanf("%d", &f[y][x]);

    Solver s(h * w + 2);
    for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++) if ((x + y) % 2 == 0) {
      for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;

        int a = y * w + x, b = ny * w + nx;
        s.adde(a, b, 1, f[y][x] == f[ny][nx] ? -1 : 0);
      }
    }

    int st = h * w, en = st + 1;
    for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++) if ((x + y) % 2 == 0) {
        s.adde(st, y * w + x, 1, 0);
      } else {
        s.adde(y * w + x, en, 1, 0);
      }

    pii res = s.solve(st, en);
    assert(res.first == h * w / 2);
    int ans = h * w / 2 + res.second;
    printf("%d\n", ans);
  }
  return 0;
}