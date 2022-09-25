#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 100100;
vector<pair<int, int>> v[2];

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  int n, s;
  cin >> n >> s;
  ll res = 0;
  ll c0 = 0, c1 = 0;
  for (int i = 0; i < n; ++i) {
    int cnt, a, b;
    cin >> cnt >> a >> b;
    res += max(a, b) * ll(cnt);
    if (a > b) {
      c0 += cnt;
      v[0].emplace_back(a - b, cnt);
    } else {
      c1 += cnt;
      v[1].emplace_back(b - a, cnt);
    }
  }
  sort(v[0].begin(), v[0].end());
  sort(v[1].begin(), v[1].end());
  ll need = (c0 + c1 + s - 1) / s;
  ll extra = need * s - c0 - c1;
  assert(extra >= 0);
  ll low = c0 / s * s;
  ll upp = (c0 + s - 1) / s * s;
  if (c0 + extra >= upp) {
    cout << res << '\n';
    return 0;
  }
  ll cost1 = 0, cost2 = 0;
  ll rem1 = c0 - low, rem2 = upp - c0 - extra;
  for (int i = 0; rem1 > 0; ++i) {
    ll c = v[0][i].first;
    ll cnt = v[0][i].second;
    cnt = min(cnt, rem1);
    cost1 += cnt * c;
    rem1 -= cnt;
  }
  for (int i = 0; rem2 > 0; ++i) {
    ll c = v[1][i].first;
    ll cnt = v[1][i].second;
    cnt = min(cnt, rem2);
    cost2 += cnt * c;
    rem2 -= cnt;
  }
  cout << res - min(cost1, cost2) << '\n';
}