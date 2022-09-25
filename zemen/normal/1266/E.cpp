#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> us(n);
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    res += a[i];
  }
  int q;
  cin >> q;
  unordered_map<ll, int> m;
  for (int i = 0; i < q; ++i) {
    int s, t, u;
    cin >> s >> t >> u;
    ll key = ll(t) * n + ll(s - 1);
    if (m.count(key)) {
      int x = m[key];
      if (--us[x] < a[x]) {
        ++res;
      }
    }
    m.erase(key);
    if (u != 0) {
      --u;
      if (++us[u] <= a[u]) {
        --res;
      }
      m[key] = u;
    }
    cout << res << '\n';
  }
}