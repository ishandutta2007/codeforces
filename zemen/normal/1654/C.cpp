#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    int n;
    cin >> n;
    multiset<ll> a, b;
    ll sum = 0;
    for (int j = 0; j < n; ++j) {
      int x;
      cin >> x;
      a.insert(x);
      sum += x;
    }
    b.insert(sum);
    while (true) {
      if (a.empty() || b.empty()) {
        break;
      }
      if (*a.rbegin() == *b.rbegin()) {
        a.erase(prev(a.end()));
        b.erase(prev(b.end()));
        continue;
      }
      if (b.size() >= a.size()) {
        break;
      }
      ll x = *b.rbegin();
      b.insert(x / 2);
      b.insert(x - x / 2);
      b.erase(prev(b.end()));
    }
    cout << (a.empty() && b.empty() ? "YES" : "NO") << '\n';
  }
}