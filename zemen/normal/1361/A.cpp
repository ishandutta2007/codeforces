#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 500500;
vector<int> g[maxn];

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<pair<int, int>> ord(n);
  for (int i = 0; i < n; ++i) {
    cin >> ord[i].first;
    ord[i].second = i;
  }
  sort(ord.begin(), ord.end());
  vector<int> cur(n, 0);
  for (auto x : ord) {
    set<int> used;
    for (int v : g[x.second]) {
      used.insert(cur[v]);
    }
    int res = 1;
    while (used.count(res)) {
      ++res;
    }
    if (res != x.first) {
      cout << -1 << '\n';
      return 0;
    }
    cur[x.second] = res;
  }
  for (auto x : ord) {
    cout << x.second + 1 << ' ';
  }
  cout << '\n';
}