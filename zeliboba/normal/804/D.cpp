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

vi p, dw, up;
vvi g;

void dfs(int v, int col) {
  if (p[v] != -1) return;
  p[v] = col;
  for (int nv : g[v]) {
    if (p[nv] == -1) {
      dfs(nv, col);
      dw[v] = max(dw[v], dw[nv] + 1);
    }
  }
}

void dfs1(int v, int pr, int& D, vi & ta) {
  vii ts(1, pii(up[v], -1));
  ts.push_back(pii(0, -1));
  for (int nv : g[v]) if (nv != pr) {
    ts.push_back(pii(dw[nv]+1, nv));
  }
  sort(ts.rbegin(), ts.rend());
  for (int nv : g[v]) if (nv != pr) {
    int x = ts[0].first;
    if (ts[0].second == nv) {
      x = ts.size() < 2 ? 0 : ts[1].first;
    }
    up[nv] = 1 + x;
    dfs1(nv, v, D, ta);
  }
  D = max(D, ts[0].first + ts[1].first);
  ta.push_back(ts[0].first);
}

int n, m, q;
vvi vals;
vvl sum;
vi diam;

double calc(int a, int b) {
  if (vals[a].size() > vals[b].size()) swap(a, b);
  int D = max(diam[a], diam[b]);
  ll res = 0;
  for (int x : vals[a]) {
    int it = lower_bound(vals[b].begin(), vals[b].end(), D - x) - vals[b].begin();
    res += D * (ll)it;
    res += sum[b].back() - sum[b][it] + (vals[b].size() - it) * (ll)(1 + x);
  }
  return ((double)res) / vals[a].size() / vals[b].size();
}

int main() {
//  std::ios::sync_with_stdio(false);
  scanf("%d%d%d", &n,&m,&q);
  g.resize(n);
  dw.assign(n, 0);
  diam.assign(n, 0);
  up.assign(n, 0);
  p.assign(n, -1);
  vals.resize(n);
  sum.resize(n);
  for (int i = 0; i < m; ++i) {
    int a,b;
    scanf("%d%d", &a,&b);
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 0; i < n; ++i) if (p[i] == -1) {
    dfs(i, i);
    dfs1(i, -1, diam[i], vals[i]);
    sort(vals[i].begin(), vals[i].end());
    sum[i].assign(vals[i].size() + 1, 0);
    for (int j = 0; j < vals[i].size(); ++j) {
      sum[i][j+1] = sum[i][j] + vals[i][j];
    }
  }
  map<pii, double> ans;
  for (int test = 1; test <= q; ++test) {
    int a,b;
    scanf("%d%d", &a,&b);
    --a; --b;
    a = p[a];
    b = p[b];
    if (a > b) swap(a, b);
    if (ans.count(pii(a, b))) {
      printf("%.10lf\n", ans[pii(a, b)]);
    } else if (a == b) {
      printf("-1\n");
    } else {
      double res = calc(a, b);
      ans[pii(a, b)] = res;
      printf("%.10lf\n", res);
    }
  }
  return 0;
}