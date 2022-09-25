#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 100100;
vector<int> g[maxn];
bool used[maxn];
int res;

void dfs(int u) {
  used[u] = true;
  for (int v : g[u]) {
    if (used[v]) {
      continue;
    }
    ++res;
    dfs(v);
  }
}

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < k; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < n; ++i) {
    if (!used[i]) {
      dfs(i);
    }
  }
  cout << k - res << '\n';
}