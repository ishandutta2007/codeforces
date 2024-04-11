#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  int n;
  cin >> n;
  vector<int> deg(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    ++deg[u];
    ++deg[v];
  }
  vector<int> d1;
  int nbig = 0;
  int u = 0;
  for (int i = 0; i < n; ++i) {
    if (deg[i] > deg[u]) {
      u = i;
    }
    if (deg[i] > 2) {
      ++nbig;
    }
    if (deg[i] == 1) {
      d1.push_back(i);
    }
  }
  if (nbig > 1) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
  cout << (int) d1.size() - (deg[u] == 1) << '\n';
  for (int v : d1) {
    if (v != u) {
      cout << u+1 << ' ' << v+1 << '\n';
    }
  }
}