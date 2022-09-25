#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

bool solve() {
  int k;
  cin >> k;
  vector<ll> c(k);
  ll sum = 0;
  for (int i = 0; i < k; ++i) {
    cin >> c[i];
    sum += c[i];
  }
  if (sum == 1) {
    return true;
  }
  ll csum = 2;
  vector<ll> v{1, 1};
  while (csum < sum) {
    ll x = v.back() + v[v.size() - 2];
    v.push_back(x);
    csum += x;
  }
  if (csum != sum) {
    return false;
  }
  int last = -1;
  reverse(v.begin(), v.end());
  for (auto x : v) {
    int mx = -1;
    for (int i = 0; i < k; ++i) {
      if (i == last) {
        continue;
      }
      if (mx == -1 || c[i] > c[mx]) {
        mx = i;
      }
    }
    if (mx == -1 || c[mx] < x) {
      return false;
    }
    c[mx] -= x;
    last = mx;
  }
  return true;
}

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int ii = 0; ii < tn; ++ii) {
    cout << (solve() ? "YES" : "NO") << '\n';
  }
}