#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void go() {
  int n; cin >> n;
  ll mx = -1, mn = (1ll << 60);
  ll mx_v = 0, mn_v = 0;
  ll mx_range = 0, _ = 0;
  for (int i = 1; i <= n; ++i) {
    ll l, r, c; cin >> l >> r >> c;
    if (l < mn || l == mn && mn_v > c) {
      mn = l;
      mn_v = c;
    }
    if (r > mx || r == mx && mx_v > c) {
      mx = r;
      mx_v = c;
    }
    if (r - l + 1 > mx_range || r - l + 1 == mx_range && _ > c) {
      mx_range = r - l + 1;
      _ = c;
    }
    ll v1 = mx_v + mn_v;
    if (mx_range == mx - mn + 1) {
      v1 = min(v1, _);
    }
    cout << v1 << '\n';
  }
}

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    go();
  }
}