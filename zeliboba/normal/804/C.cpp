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

vvi c, g;
vi ans, used;

void dfs(int v, int p) {
  if (p == -1) {
    for (int i = 0; i < c[v].size(); ++i) ans[c[v][i]] = i;
  } else {
    for (int i = 0; i < c[v].size(); ++i) {
      if (ans[c[v][i]] != -1) used[ans[c[v][i]]] = 1;
    }
    int it = 0;
    for (int i = 0; i < c[v].size(); ++i) {
      if (ans[c[v][i]] == -1) {
        while (used[it]) ++it;
        ans[c[v][i]] = it;
        used[it] = 1;
        ++it;
      }
    }
    for (int i = 0; i < c[v].size(); ++i) {
      used[ans[c[v][i]]] = 0;
    }
  }
  for (int nv : g[v]) if (nv != p) dfs(nv, v);
}

int main() {
  std::ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  c.resize(n);
  g.resize(n);
  int res = 0;
  for (int i = 0; i < n; ++i) {
    int s;
    cin >> s;
    res = max(res, s);
    c[i].resize(s);
    for (int j = 0; j < s; ++j) {
      cin >> c[i][j];
      --c[i][j];
    }
    sort(c[i].begin(), c[i].end());
  }
  for (int i = 0; i < n-1; ++i) {
    int a,b;
    cin >> a >> b;
    --a;
    --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  cout << max(1, res) << endl;
  used.assign(res, 0);
  ans.assign(m, -1);
  dfs(0, -1);
  for (int i = 0; i < m; ++i) cout << max(ans[i], 0) + 1 << ' ';
  return 0;
}