#include <stdio.h>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

vvi g, gw, gi;
vi p, in, out;
vvi add, del;
const int L = 18;
int lc[200005][L];
int lcw[200005][L];
int TIMER = 0;

int getp(int v) {
  if (p[v] == v) return v;
  return p[v] = getp(p[v]);
}

bool join(int a, int b) {
  a = getp(a);
  b = getp(b);
  if (a == b) return false;
  if (rand() % 2) swap(a, b);
  p[a] = b;
  return true;
}

void dfs(int v, int pr) {
  in[v] = TIMER++;
  lc[v][0] = pr;
  for (int i = 0; i < g[v].size(); ++i) {
    int nv = g[v][i];
    if (nv == pr) continue;
    lcw[nv][0] = gw[v][i];
    dfs(nv, v);
  }
  out[v] = TIMER++;
}

bool upper (int a, int b) {
  return in[a] <= in[b] && out[a] >= out[b];
}

int lca (int a, int b) {
  if (upper (a, b))  return a;
  if (upper (b, a))  return b;
  for (int i=L-1; i>=0; --i)
    if (! upper (lc[a][i], b))
      a = lc[a][i];
  return lc[a][0];
}

int getma(int a, int b) {
//  if (a == b) return 0;
  int res = 0;
  for (int i=L-1; i>=0; --i) {
    if (upper(b, lc[a][i])) {
      res = max(res, lcw[a][i]);
      a = lc[a][i];
    }
  }
  return res;
}

vi res;
multiset<int> d[200001];
void dfs1(int v, int pr) {
  for (int i = 0; i < g[v].size(); ++i) {
    if (g[v][i] == pr) continue;
    dfs1(g[v][i], v);
    if (!d[g[v][i]].empty()) res[gi[v][i]] = min(res[gi[v][i]], *d[g[v][i]].begin() - 1);
  }
  for (int i = 0; i < g[v].size(); ++i) {
    if (g[v][i] == pr) continue;
    if (d[v].size() < d[g[v][i]].size()) d[v].swap(d[g[v][i]]);
    for (int x : d[g[v][i]]) d[v].insert(x);
    d[g[v][i]].clear();
  }
  for (int x : add[v]) d[v].insert(x);
  for (int x : del[v]) d[v].erase(d[v].find(x));
}

int main() {
  //  std::ios::sync_with_stdio(false);
  int n, m;
  scanf("%d%d", &n, &m);
  g.resize(n);
  gi.resize(n);
  add.resize(n);
  del.resize(n);
  p.resize(n);
  in.resize(n);
  out.resize(n);
  gw.resize(n);
  vector<array<int, 4>> e(m);
  for (int i = 0; i < m; ++i) {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    --a; --b;
/*    g[a].push_back(b);
    g[b].push_back(a);
    gw[a].push_back(c);
    gw[b].push_back(c);*/
    e[i] = {c, a, b, i};
  }
  for (int i = 0; i < n; ++i) p[i] = i;
  sort(e.begin(), e.end());
  vi used(m);
  for (int it = 0; it < m; ++it) {
    int a = e[it][1], b = e[it][2], c = e[it][0];
    if (join(a, b)) {
      used[it] = 1;
      g[a].push_back(b);
      g[b].push_back(a);
      gw[a].push_back(c);
      gw[b].push_back(c);
      gi[a].push_back(e[it][3]);
      gi[b].push_back(e[it][3]);
    }
  }
  dfs(0, 0);
  for (int i = 1; i < L; ++i) for (int j = 0; j < n; ++j) {
    lc[j][i] = lc[lc[j][i-1]][i-1];
    lcw[j][i] = max(lcw[j][i-1], lcw[lc[j][i-1]][i-1]);
  }
  const int MAX = 2e9;
  res.assign(m, MAX);
  for (int it = 0; it < m; ++it) {
    if (!used[it]) {
      int a = e[it][1], b = e[it][2], c = e[it][0];
      int pr = lca(a, b);
      res[e[it][3]] = max(getma(a, pr), getma(b, pr)) - 1;
      if (a != pr) {
        add[a].push_back(c);
        del[pr].push_back(c);
      }
      if (b != pr) {
        add[b].push_back(c);
        del[pr].push_back(c);
      }
    }
  }
  dfs1(0, -1);
  for (int i = 0; i < m; ++i) {
    if (res[i] == MAX) res[i] = -1;
    printf("%d ", res[i]);
  }
  return 0;
}