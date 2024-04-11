#pragma GCC optimize("Ofast,no-stack-protector")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    int n, m;
    cin >> n >> m;
    if (n > m || (n % 2 == 0 && m % 2 != 0)) {
      cout << "No\n";
      continue;
    }
    cout << "Yes\n";
    if (n % 2 == 0) {
      for (int i = 0; i < n - 2; ++i) {
        cout << 1 << ' ';
      }
      m -= n - 2;
      cout << m / 2 << ' ' << m / 2 << '\n';
    } else {
      for (int i = 0; i < n - 1; ++i) {
        cout << 1 << ' ';
      }
      m -= n - 1;
      cout << m << '\n';
    }
  }
}