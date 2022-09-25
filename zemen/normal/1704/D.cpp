#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int ii = 0; ii < tn; ++ii) {
    int n, m;
    cin >> n >> m;
    vector<ll> sum(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        ll x;
        cin >> x;
        sum[i] += x * j;
      }
    }
    int pos = max_element(sum.begin(), sum.end()) - sum.begin();
    ll val = *min_element(sum.begin(), sum.end());
    cout << pos + 1 << ' ' << sum[pos] - val << '\n';
  }
}