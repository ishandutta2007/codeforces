#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  ll a, b;
  cin >> a >> b;
  if (a > b + 1) {
    cout << "NO\n";
    return;
  }
  a += b;
  for (ll x = 2; x * x <= a; ++x) {
    if (a % x == 0) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}