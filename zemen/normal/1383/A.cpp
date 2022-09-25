#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

vector<vector<pair<int, int>>> g(20);
vector<char> used(20);

int calc(int u) {
  used[u] = 1;
  int res = 1;
  for (auto& [v, dir] : g[u]) {
    (void) dir;
    if (!used[v]) {
      res += calc(v);
    }
  }
  used[u] = 2;
  return res;
}

void solve() {
  int n;
  string a, b;
  cin >> n >> a >> b;
  for (int i = 0; i < 20; ++i) {
    g[i].clear();
    used[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] == b[i]) {
      continue;
    }
    g[a[i] - 'a'].emplace_back(b[i] - 'a', 1);
    g[b[i] - 'a'].emplace_back(a[i] - 'a', -1);
    if (b[i] < a[i]) {
      cout << -1 << '\n';
      return;
    }
  }
  int res = 0;
  for (int i = 0; i < 20; ++i) {
    if (!used[i] && !g[i].empty()) {
      res += calc(i) - 1;
    }
  }
  cout << res << '\n';
}

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}