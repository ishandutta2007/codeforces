#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<ll> a(k);
  for (int i = 0; i < k; ++i) {
    cin >> a[i];
  }
  bool ok = false;
  for (int it = 0; it < 2; ++it) {
    ll cnt = 0;
    bool large = false;
    for (auto x : a) {
      if (x / n > 1) {
        cnt += x / n;
        if (x / n > 2) {
          large = true;
        }
      }
    }
    if (cnt >= m && (large || m % 2 == 0)) {
      ok = true;
    }
    swap(n, m);
  }
  cout << (ok ? "Yes" : "No") << '\n';
}

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}