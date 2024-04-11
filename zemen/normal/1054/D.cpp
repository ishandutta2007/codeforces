#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

ll c2(ll x) {
  return x * (x - 1) / 2;
}

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  int n, k;
  cin >> n >> k;
  map<int, int> cnt;
  cnt[0]++;
  int x = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    x ^= a;
    if (x & 1) {
      x ^= (1 << k) - 1;
    }
    cnt[x]++;
  }
  ll res = 0;
  for (auto p : cnt) {
    res += c2(p.second / 2);
    res += c2(p.second - p.second / 2);
  }
  res = c2(n + 1) - res;
  cout << res << '\n';
}