#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 1e5 + 100;
vector<int> g[maxn];
int a[maxn];

int dfs(int u) {
  int c = g[u].empty();
  for (int v : g[u]) {
    c += dfs(v);
  }
  a[c]++;
  return c;
}

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  int n;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int p;
    cin >> p;
    --p;
    g[p].push_back(i);
  }
  dfs(0);
  int cnt = 0, p = 0;
  for (int i = 1; i <= n; ++i) {
    while (cnt < i) {
      cnt += a[p++];
    }
    cout << p-1 << ' ';
  }
  cout << '\n';
}