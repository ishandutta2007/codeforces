#pragma GCC optimize("Ofast,no-stack-protector")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

vector<vector<int>> g;
vector<int> l, r;

pair<int, int> dfs(int u) {
  int cnt = 0, mx = 0;
  for (int v : g[u]) {
    auto [vcnt, vmx] = dfs(v);
    cnt += vcnt;
    mx = min(mx + vmx, r[u]);
  }
  if (mx < l[u]) {
    ++cnt;
    mx = r[u];
  }
  return {cnt, mx};
}

void solve() {
  int n;
  cin >> n;
  g.assign(n, {});
  for (int i = 1; i < n; ++i) {
    int p;
    cin >> p;
    --p;
    g[p].push_back(i);
  }
  l.resize(n);
  r.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
  }
  auto res = dfs(0);
  cout << res.first << '\n';
}

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}