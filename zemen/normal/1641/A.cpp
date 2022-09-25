#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int n, x;
  cin >> n >> x;
  multiset<ll> s;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    s.insert(a);
  }
  int res = 0;
  while (!s.empty()) {
    ll y = *s.begin() * x;
    s.erase(s.begin());
    auto it = s.find(y);
    if (it != s.end()) {
      s.erase(it);
    } else {
      ++res;
    }
  }
  cout << res << '\n';
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