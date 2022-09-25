#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  int sum = 0;
  ll sum2 = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
    sum2 += a[i] * a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    sum += b[i];
    sum2 += b[i] * b[i];
  }
  const int N = 20010;
  bitset<N> d;
  d[0] = 1;
  for (int i = 0; i < n; ++i) {
    d = (d << a[i]) | (d << b[i]);
  }
  for (int b = sum / 2; b >= 0; --b) {
    if (d[b]) {
      //cerr << b << ' ' << sum - b << '\n';
      int a = sum - b;
      ll res = ll(b) * b + ll(a) * a;
      res += (n - 2) * sum2;
      cout << res << '\n';
      return;
    }
  }
  assert(false);
}

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}