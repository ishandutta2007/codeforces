#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

bool check(const vector<ll>& a, int k, ll mask) {
  int n = (int) a.size();
  vector<bool> d(n + 1);
  d[0] = true;
  for (int it = 0; it < k; ++it) {
    vector<bool> nd(n + 1);
    for (int i = 0; i < n; ++i) {
      if (!d[i]) {
        continue;
      }
      ll s = 0;
      for (int j = i; j < n; ++j) {
        s += a[j];
        if ((s & mask) != mask) {
          continue;
        }
        nd[j + 1] = true;
      }
    }
    d = nd;
  }
  return d[n];
}

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  ll res = 0;
  for (int b = 62; b >= 0; --b) {
    res ^= 1ll << b;
    if (!check(a, k, res)) {
      res ^= 1ll << b;
    }
  }
  cout << res << '\n';
}