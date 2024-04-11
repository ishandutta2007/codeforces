#pragma GCC optimize("Ofast,no-stack-protector")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(int n, int k) {
  if (n == 4 && k == 3) {
    cout << -1 << '\n';
    return;
  }
  int mask = n - 1;

  bool flip1 = k == mask;
  if (flip1) {
    --k;
  }
  int a = n / 2 + 1;

  cout << k << ' ' << mask << '\n';
  if (!flip1) {
    if (k != 0) {
      cout << (mask & ~k) << ' ' << 0 << '\n';
    }
  } else {
    cout << 1 << ' ' << a << '\n';
    cout << 0 << ' ' << (mask & ~a) << '\n';
  }

  for (int i = 1; i < n / 2; ++i) {
    int j = mask & ~i;
    if (i == k || j == k) {
      continue;
    }
    if (flip1 && (i == a || j == a)) {
      continue;
    }
    cout << i << ' ' << j << '\n';
  }
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
    int n, k;
    cin >> n >> k;
    solve(n, k);
  }
}