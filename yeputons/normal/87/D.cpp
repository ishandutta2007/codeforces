#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdarg>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

class Dss {
  vi par, sz;

  public:
  Dss(int n) {
    par = vi(n);
    for (int i = 0; i < n; i++) par[i] = i;
    sz = vi(n, 1);
  }

  int get(int x) { return par[x] == x ? x : par[x] = get(par[x]); }
  int size(int x) { return sz[get(x)]; }

  void merge(int a, int b) {
    a = get(a); b = get(b);
    if (a == b) return;

    if (sz[a] > sz[b]) {
      par[b] = a;
      sz[a] += sz[b];
    } else {
      par[a] = b;
      sz[b] += sz[a];
    }
  }
};

vvi es, esw;
vi par, parw;
vi h;
vb was;

struct Edge {
  int a, b, w, id;
  Edge() : a(-1), b(-1), w(0), id(-1) {}
  Edge(int _a, int _b, int _w, int _id) : a(_a), b(_b), w(_w), id(_id) {}
  int up() const { return h[a] < h[b] ? a : b; }
  int down() const { return h[a] > h[b] ? a : b; }

  bool operator<(const Edge &e) const {
    if (w != e.w) return w < e.w;
    int h1 = h[up()], h2 = h[e.up()];
    return h1 > h2;
  }
};

void dfs(int v) {
  was[v] = true;
  for (int i = 0; i < sz(es[v]); i++) {
    int b = es[v][i];
    if (was[b]) continue;

    par[b] = v; parw[b] = esw[v][i];
    h[b] = h[v] + 1;
    dfs(b);
  }
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    es = vvi(n);
    esw = vvi(n);
    vector<Edge> ses;

    for (int i = 1; i < n; i++) {
      int a, b, w;
      scanf("%d%d%d", &a, &b, &w), a--, b--;
      ses.pb(Edge(a, b, w, i));
      es[a].pb(b); esw[a].pb(w);
      es[b].pb(a); esw[b].pb(w);
    }
    par = vi(n, -1);
    parw = vi(n, 0);
    was = vb(n, false);
    h = vi(n, 0);
    dfs(0);

    vector<pair<ll, int> > trees(sz(ses));
    for (int i = 0; i < sz(ses); i++)
      trees[i] = mp(0, i);

    sort(ses.begin(), ses.end());
    Dss lessGo(n), newGo(n);

    int prw = ses[0].w;
    int st = 0;
    for (int i = 0; i <= sz(ses); i++) {
      if (i >= sz(ses) || ses[i].w != prw) {
        for (int i2 = st; i2 < i; i2++)
          newGo.merge(ses[i2].a, ses[i2].b);

        // First: check
        for (int i2 = st; i2 < i; i2++) {
          ll bcnt = newGo.size(ses[i2].down());
          ll dcnt = lessGo.size(ses[i2].down());
          ll ucnt = bcnt - dcnt;
//          eprintf("edge from %d to %d. ucnt=%I64d, dcnt=%I64d\n", ses[i2].a + 1, ses[i2].b + 1, ucnt, dcnt);
          trees[i2].first = dcnt * ucnt;
          lessGo.merge(ses[i2].a, ses[i2].b);
        }

        st = i;
        prw = ses[i].w;
      }
    }
    sort(trees.begin(), trees.end());
    reverse(trees.begin(), trees.end());
    ll best = trees[0].first;
    vi res;
    for (int i = 0; i < sz(trees) && trees[i].first == best; i++) 
      res.pb(ses[trees[i].second].id);
    sort(res.begin(), res.end());

    printf("%I64d %d\n", best * 2, sz(res));
    for (int i = 0; i < sz(res); i++)
      printf("%d%c", res[i], "\n "[i + 1 < sz(res)]);
    
    break;
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}