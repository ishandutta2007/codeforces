#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  ll k;
  cin >> k;
  const string s = "codeforces";
  vector<ll> cnt(s.size(), 1);
  for (int i = 0; i < 1000000; ++i) {
    ll cur = 1;
    for (auto x : cnt) {
      cur *= x;
    }
    if (cur >= k) {
      break;
    }
    cnt[i % cnt.size()]++;
  }
  for (int i = 0; i < (int) s.size(); ++i) {
    cout << string(cnt[i], s[i]);
  }
  cout << '\n';
}