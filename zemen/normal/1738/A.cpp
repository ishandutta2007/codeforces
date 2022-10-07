#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int ii = 0; ii < tn; ++ii) {
    int n;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
      cin >> t[i];
    }
    vector<int> a, b;
    ll mn = 1e18;
    ll res = 0;
    for (int i = 0; i < n; ++i) {
      ll x;
      cin >> x;
      mn = min(mn, x);
      res += x;
      if (t[i]) {
        a.push_back(x);
      } else {
        b.push_back(x);
      }
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    int k = min(a.size(), b.size());
    a.resize(k);
    b.resize(k);
    for (auto x : a) {
      res += x;
    }
    for (auto x : b) {
      res += x;
    }
    if ((int) a.size() + (int) b.size() == n) {
      res -= mn;
    }
    cout << res << '\n';
  }
}