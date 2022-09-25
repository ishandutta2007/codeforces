#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 1005;
vector<int> g[maxn];
vector<char> used;

int dfs(int u, int prev = -1) {
  if (used[u]) {
    return u;
  }
  for (int v : g[u]) {
    if (v == prev) {
      continue;
    }
    int x = dfs(v, u);
    if (x != -1) {
      return x;
    }
  }
  return -1;
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    g[i].clear();
  }
  used.assign(n, false);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int tmp;
  cin >> tmp;
  vector<int> x(tmp);
  for (int i = 0; i < tmp; ++i) {
    cin >> x[i];
    --x[i];
    used[x[i]] = true;
  }
  cin >> tmp;
  vector<int> y(tmp);
  for (int i = 0; i < tmp; ++i) {
    cin >> y[i];
    --y[i];
  }
  cout << "B " << y[0]+1 << endl;
  int u;
  cin >> u;
  --u;
  u = dfs(u);
  cout << "A " << u+1 << endl;
  int v;
  cin >> v;
  --v;
  bool ok = find(y.begin(), y.end(), v) != y.end();
  if (!ok) {
    u = -2;
  }
  cout << "C " << u+1 << endl;
}

signed main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
}