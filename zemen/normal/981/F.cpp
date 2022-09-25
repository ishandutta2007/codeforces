#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

bool check(const vector<pair<ll, int>>& va, const vector<pair<ll, int>>& vb, ll L, ll c) {
  //cerr << "check " << c << '\n';

  vector<pair<ll, int>> v;
  vector<pair<ll, int>> vb2 = vb;
  for (auto& p : vb2) {
    p.first -= c;
  }
  merge(va.begin(), va.end(), vb2.begin(), vb2.end(), back_inserter(v));
  vector<ll> ps(v.size() + 1);
  vector<ll> pneg(v.size() + 1);
  for (int i = 0; i < (int) v.size(); ++i) {
    ps[i + 1] = ps[i] + v[i].second;
    pneg[i + 1] = pneg[i] + v[i].second * (v[i].second < 0);
  }
  int j = (int) v.size() - 1;
  ll mx = -1e9;
  //for (auto p : v) {
    //cerr << p.first << ' ' << p.second << '\n';
  //}
  for (int i = (int) v.size() - 1; i >= 0; --i) {
    if (v[i].second == 1 && v[i].first >= 0 && v[i].first < L) {
      j = min(j, i);
      while (j > 0 && v[j - 1].first >= v[i].first - 2 * c) {
        --j;
      }
      int bal = pneg[i] - pneg[j];
      bal += mx - ps[i];
      if (bal > 0) {
        //cerr << "sos " << v[i].first << ' ' << mx - ps[i] << '\n';
        return false;
      }
    }
    mx = max(mx, ps[i]);
  }
  return true;
}

signed main() {
#ifdef LOCAL
  assert(freopen("f.in", "r", stdin));
#endif
  int n;
  ll L;
  cin >> n >> L;
  vector<pair<ll, int>> va, vb;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    for (ll m = 0; m <= 1; ++m) {
      va.emplace_back(a + m * L, 1);
    }
  }
  for (int i = 0; i < n; ++i) {
    int b;
    cin >> b;
    for (ll m = -1; m <= 2; ++m) {
      vb.emplace_back(b + m * L, -1);
    }
  }
  sort(va.begin(), va.end());
  sort(vb.begin(), vb.end());
  ll l = -1, r = L / 2;
  while (l + 1 < r) {
    ll c = (l + r) / 2;
    if (check(va, vb, L, c)) {
      r = c;
    } else {
      l = c;
    }
  }
  cout << r << '\n';
}