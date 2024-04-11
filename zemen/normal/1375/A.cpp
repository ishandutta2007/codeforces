#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] = abs(a[i]);
  }
  int cp = 0, cn = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (a[i + 1] - a[i] >= 0) {
      ++cp;
    }
    if (a[i + 1] - a[i] <= 0) {
      ++cn;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (min(cp, cn) >= n / 2) {
      break;
    }
    if (i > 0) {
      if (a[i] - a[i - 1] >= 0) {
        --cp;
      }
      if (a[i] - a[i - 1] <= 0) {
        --cn;
      }
      if (-a[i] - a[i - 1] >= 0) {
        ++cp;
      }
      if (-a[i] - a[i - 1] <= 0) {
        ++cn;
      }
    }
    if (i + 1 < n) {
      if (a[i + 1] - a[i] >= 0) {
        --cp;
      }
      if (a[i + 1] - a[i] <= 0) {
        --cn;
      }
      if (a[i + 1] - -a[i] >= 0) {
        ++cp;
      }
      if (a[i + 1] - -a[i] <= 0) {
        ++cn;
      }
    }
    a[i] *= -1;
  }
  assert(min(cp, cn) >= n / 2);
  for (int x : a) {
    cout << x << ' ';
  }
  cout << '\n';
}

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}