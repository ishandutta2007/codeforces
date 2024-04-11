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
#include <array>
#include <bitset>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef long double ld;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//typedef long long int;

vvi g;
vvi dyn;

int solve(int c, const vi& d, const vi& good, int add = 0) {
  int l = 0, r = 1e8;
  while (r - l > 1) {
    int x = (l + r) / 2;
    int cnt = 0;
    for (int l = 0; l < good.size(); ++l) if (good[l]) {
      int it = lower_bound(dyn[l].begin(), dyn[l].begin() + c + add, x - d[l]) - dyn[l].begin();
//      cerr << "it " << it << ' ' << dyn[l][it] << ' ' << x << ' ' << d[l] << endl;
      cnt += c + add - it;
    }
//    cerr << c << ' ' << x << ' ' << cnt << endl;
    if (cnt >= c) {
      l = x;
    } else {
      r = x;
    }
  }
  return l;
}

vi vis;
void dfs(int v, int p) {
  vis[v] = 1;
  for (int nv : g[v]) {
    if (nv == p) continue;
    dfs(nv, v);
  }
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  if (n == 1) {
    cout << "0\n";
    return 0;
  }
  g.resize(n);
  vvi d(n, vi(n, 1e9));
  for (int i = 0; i < n; ++i) d[i][i] = 0;
  for (int i = 0; i < n-1; ++i) {
    int a, b, w;
    cin >> a >> b >> w;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
    d[a][b] = w;
    d[b][a] = w;
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
      d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }
  }
//  for (int i = 0; i < n; ++i) {for (int j = 0; j < n; ++j) cerr << d[i][j] << ' '; cerr << endl;}
  int s; cin >> s; --s;
  int m;
  cin >> m;
  vi p, cp(n);
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    --x;
    if (x != s) {
      p.push_back(x);
      cp[x]++;
    }
  }
  m = p.size();
  if (m == 0) {
    cout << "0\n";
    return 0;
  }
  vi isleaf(n);
  for (int i = 0; i < n; ++i) isleaf[i] = g[i].size() == 1;
  dyn.assign(n, vi(m + 1, 1e9));
  for (int i = 0; i < n; ++i) dyn[i][0] = 0;
  for (int i = 1; i < dyn[0].size(); ++i) {
    for (int j = 0; j < n; ++j) if (g[j].size() == 1) {
      dyn[j][i] = solve(i, d[j], isleaf);
    }
  }
  int res = 1e9;
  if (isleaf[s]) {
    res = dyn[s][m];
  } else {
    for (int v : g[s]) {
      vis.assign(n, 0);
      dfs(v, s);
      int c = 0;
      for (int i = 0; i < n; ++i) {
        c += vis[i] * cp[i];
        vis[i] &= isleaf[i];
      }
      res = min(res, solve(c, d[s], vis, m - c));
    }
  }
  cout << res << endl;
  return 0;
}