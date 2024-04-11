#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

vector<int> g[100100];

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  int n;
  cin >> n;
  vector<ll> a(n);
  const int B = 62;
  vector<int> cnt(B);
  vector<int> nonz;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] > 0) {
      nonz.push_back(i);
    }
    for (int j = 0; j < B; ++j) {
      if (a[i] & (1ll << j)) {
        if (++cnt[j] >= 3) {
          cout << 3 << '\n';
          return 0;
        }
      }
    }
  }
  for (int i = 0; i < (int) nonz.size(); ++i) {
    for (int j = 0; j < i; ++j) {
      if (a[nonz[i]] & a[nonz[j]]) {
        g[i].push_back(j);
        g[j].push_back(i);
      }
    }
  }
  n = (int) nonz.size();
  int res = n + 1;
  for (int st = 0; st < n; ++st) {
    vector<int> dist(n, -1);
    vector<int> from(n, -1);
    dist[st] = 0;
    vector<int> q{st};
    for (int i = 0; i < (int) q.size(); ++i) {
      int u = q[i];
      for (int v : g[u]) {
        if (dist[v] == -1) {
          dist[v] = dist[u] + 1;
          from[v] = u;
          q.push_back(v);
        } else if (v != from[u]) {
          res = min(res, dist[u] + dist[v] + 1);
        }
      }
    }
  }
  if (res > n) {
    res = -1;
  }
  cout << res << '\n';
}