#pragma GCC optimize("Ofast,no-stack-protector")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int gcd(int a, int b) {
  while (a && b) {
    if (a >= b) {
      a %= b;
    } else {
      b %= a;
    }
  }
  return a + b;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int g = 0;
  for (int j = 0; j < m; ++j) {
    int x;
    cin >> x;
    g = gcd(x, g);
  }

  ll sum = 0;
  array<ll, 2> delta{0, 0};

  //cerr << "gcd: " << g << '\n';
  for (int r = 0; r < min(g, n); ++r) {
    int sgn = 0;
    int mn = abs(a[r]);
    for (int i = r; i < n; i += g) {
      if (a[i] < 0) {
        sgn ^= 1;
      }
      mn = min(mn, abs(a[i]));
      sum += abs(a[i]);
    }
    delta[sgn] += mn;
  }
  //cerr << delta[0] << ' ' << delta[1] << '\n';
  cout << sum - min(delta[0], delta[1]) * 2 << '\n';
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