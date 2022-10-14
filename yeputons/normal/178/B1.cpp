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

class Dsu {
  vi par, ss;

  public:
  Dsu(int n = 0) : par(n), ss(n, 1) {
    for (int i = 0; i < n; i++)
      par[i] = i;
  }
  int get(int x) { return par[x] == x ? x : par[x] = get(par[x]); }
  void merge(int a, int b) {
    a = get(a); b = get(b);
    if (a == b) return;
    if (ss[a] > ss[b]) swap(a, b);
    par[a] = b;
    ss[b] += ss[a];
  }
};

class Tree {
  static const int K = 18;
  vvi pars;
  vi hs;
  vvi es;
  int root;

  void dfs(int v, int par = -1) {
    for (int i = 0; i < sz(es[v]); i++) {
      int b = es[v][i];
      if (b == par) continue;

      hs[b] = hs[v] + 1;
      pars[b][0] = v;
      for (int i2 = 1; i2 < K; i2++)
        if (pars[b][i2 - 1] >= 0)
          pars[b][i2] = pars[pars[b][i2 - 1]][i2 - 1];
        else
          break;

      dfs(b, v);
    }
  }

  int lca(int a, int b) {
    if (hs[a] < hs[b]) swap(a, b);
    for (int i = K - 1; i >= 0; i--)
      if (hs[a] - (1 << i) >= hs[b]) {
        a = pars[a][i];
      }
    assert(hs[a] == hs[b]);
    for (int i = K - 1; i >= 0; i--)
      if (pars[a][i] != pars[b][i]) {
        a = pars[a][i];
        b = pars[b][i];
      }
    if (a != b)
      a = pars[a][0], b = pars[b][0];
    assert(a == b);
    return a;
  }

  public:
  Tree(int n) : es(n) {}
  void adde(int a, int b) {
    es[a].pb(b);
    es[b].pb(a);
  }
  void init(int _root) {
    root = _root;
    pars = vvi(sz(es), vi(K, -1));
    hs = vi(sz(es), 0);
    dfs(root);
  }
  int solve(int a, int b) {
    int c = lca(a, b);
    return hs[a] + hs[b] - 2 * hs[c];
  }
};

vvi es;
vb was;

vi stim;
int ctim;

Dsu dsu;

int dfs(int v, int par = -1) {
  assert(!was[v]);
  was[v] = true;
  stim[v] = ctim++;

  int up = stim[v];
  for (int i = 0; i < sz(es[v]); i++) {
    int b = es[v][i];
    if (b == par) continue;

    if (was[b]) {
      up = min(up, stim[b]);
      continue;
    }
    int cval = dfs(b, v);
    up = min(up, cval);
  }
  if (up < stim[v]) {
    if (par >= 0)
      dsu.merge(par, v);
  }
  return up;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, m;
  while (scanf("%d%d", &n, &m) >= 1) {
    eprintf("%d %d\n", n, m);
    es = vvi(n);
    for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b), a--, b--;
      es[a].pb(b);
      es[b].pb(a);
    }

    was = vb(n, false);
    stim = vi(n, -1);
    ctim = 0;
    dsu = Dsu(n);
    dfs(0);

    Tree t(n);
    for (int i = 0; i < n; i++)
    for (int i2 = 0; i2 < sz(es[i]); i2++) {
      int a = dsu.get(i);
      int b = dsu.get(es[i][i2]);
      if (a != b)
        t.adde(a, b);
    }
    t.init(dsu.get(0));

    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      a = dsu.get(a - 1);
      b = dsu.get(b - 1);
      printf("%d\n", t.solve(a, b));
    }
  }
  return 0;
}