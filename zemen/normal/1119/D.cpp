#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<ll> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  sort(s.begin(), s.end());
  vector<ll> d(n);
  for (int i = 0; i < n - 1; ++i) {
    d[i] = s[i + 1] - s[i];
  }
  d[n - 1] = 2e18;
  sort(d.begin(), d.end());
  reverse(d.begin(), d.end());

  int q;
  cin >> q;
  vector<pair<ll, int>> qs;
  for (int i = 0; i < q; ++i) {
    ll l, r;
    cin >> l >> r;
    qs.emplace_back(r - l + 1, i);
  }
  sort(qs.begin(), qs.end());
  vector<ll> ans(q);

  ll res = 0, x = 0;
  for (auto p : qs) {
    while (!d.empty() && d.back() < p.first) {
      res += (ll) d.size() * (d.back() - x);
      x = d.back();
      d.pop_back();
    }
    res += (ll) d.size() * (p.first - x);
    x = p.first;
    //cerr << x << ' ' << res << '\n';
    ans[p.second] = res;
  }
  for (int i = 0; i < q; ++i) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}