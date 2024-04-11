#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m, l;
  cin >> n >> m >> l;
  vector<ll> a(n);
  ll A = 0, B = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    a[i] = x;
    if (a[i] > l) {
      ++A;
    }
    if (i > 0 && min(a[i], a[i - 1]) > l) {
      ++B;
    }
  }
  for (int i = 0; i < m; ++i) {
    int t;
    cin >> t;
    if (t == 0) {
      cout << A - B << '\n';
    } else {
      int x, y;
      cin >> x >> y;
      --x;
      A -= a[x] > l;
      if (x > 0) {
        B -= min(a[x], a[x - 1]) > l;
      }
      if (x + 1 < n) {
        B -= min(a[x], a[x + 1]) > l;
      }
      a[x] += y;
      A += a[x] > l;
      if (x > 0) {
        B += min(a[x], a[x - 1]) > l;
      }
      if (x + 1 < n) {
        B += min(a[x], a[x + 1]) > l;
      }
    }
  }
}