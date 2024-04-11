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

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  ll n, m, c1, c2, v, Q;
  cin >> n >> m >> c1 >> c2 >> v;
  vi st(c1), lif(c2);
  for (int i = 0; i < st.size(); ++i) cin >> st[i];
  for (int i = 0; i < lif.size(); ++i) cin >> lif[i];
  cin >> Q;
  for (int test = 0; test < Q; ++test) {
    ll x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2) {
      cout << abs(y1 - y2) << endl;
      continue;
    }
    ll res = 1e18;
    int it = lower_bound(st.begin(), st.end(), y1) - st.begin();
    if (it < st.size()) {
      res = min(res, abs(x1 - x2) + abs(y1 - st[it]) + abs(y2 - st[it]));
    }
    if (it > 0) {
      res = min(res, abs(x1 - x2) + abs(y1 - st[it-1]) + abs(y2 - st[it-1]));
    }
    it = lower_bound(lif.begin(), lif.end(), y1) - lif.begin();
    if (it < lif.size()) {
      res = min(res, (abs(x1 - x2) + v - 1) / v + abs(y1 - lif[it]) + abs(y2 - lif[it]));
    }
    if (it > 0) {
      res = min(res, (abs(x1 - x2) + v - 1) / v + abs(y1 - lif[it-1]) + abs(y2 - lif[it-1]));
    }
    cout << res << endl;
  }
  return 0;
}