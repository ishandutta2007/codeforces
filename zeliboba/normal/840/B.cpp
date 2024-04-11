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

vvi g, gi;
vi d;
vi was;
int c0, c1, last;
vi res;

void dfs0(int v) {
  if (was[v]) return;
  was[v] = 1;
  if (d[v] == 1) ++c1;
  if (d[v] == -1) {
    ++c0;
    last = v;
  }
  for (int nv : g[v]) {
    dfs0(nv);
  }
}

bool dfs(int v) {
  if (was[v] == 2) return false;
  was[v] = 2;
  int c = 0;
  for (int i = 0; i < g[v].size(); ++i) {
    int nv = g[v][i];
    if (dfs(nv)) {
      ++c;
      res.push_back(gi[v][i]);
    }
  }
  if (d[v] == 1 || v == last) ++c;
  return c % 2;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m;
  cin >> n >> m;
  g.resize(n);
  gi.resize(n);
  d.resize(n);
  was.assign(n, 0);
  for (int i = 0; i < n; ++i) cin >> d[i];
  for (int i = 0; i < m; ++i) {
    int u,v;
    cin >> u >> v;
    --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
    gi[u].push_back(i+1);
    gi[v].push_back(i+1);
  }
  for (int i = 0; i < n; ++i) if (!was[i]) {
    c0 = 0, c1 = 0;
    dfs0(i);
    if (c1 % 2 && c0 == 0) {
      cout << -1 << endl;
      return 0;
    }
    if (c1 % 2 == 0) last = -1;
    dfs(i);
  }
  cout << res.size() << endl;
  for (int x : res) cout << x << ' ';
  cout << endl;
  return 0;
}