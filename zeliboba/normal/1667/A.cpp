#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
//const int mod = ;

ll f(const vl& a) {
  if (a.empty()) return 0;
  int n = a.size();
  ll s = 0;
  vl k(n);
  s = k[0] = 1;
  for (int i = 1; i < n; ++i) {
    k[i] = k[i - 1] * a[i - 1] / a[i] + 1;
    s += k[i];
  }
  return s;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T = 1;
//  cin >> T;
  for (int test = 1; test <= T; ++test) {
    int n;
    cin >> n;
    vl a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    ll res = 4e18;
    for (int j = 0; j < n; ++j) {
      vl c, d;
      for (int i = j + 1; i < n; ++i) c.push_back(a[i]);
      for (int i = j - 1; i >= 0; --i) d.push_back(a[i]);
      res = min(res, f(c) + f(d));
    }
    cout << res << endl;
  }
  return 0;
}