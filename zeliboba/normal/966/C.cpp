#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
//const int mod = ;

void solve(const vl & b) {
  vvl v(62);
  for (int i = 0; i < b.size(); ++i) {
    for (int j = 61; j >= 0; --j) if (b[i] & (1LL << j)) {
      v[j].push_back(b[i]);
      break;
    }
  }
  vl res;
  bool fail = 0;
  for (int j = v.size() - 1; !fail && j >= 0; --j) if (!v[j].empty()) {
    vl nres;
    int it = 0;
    ll xr = 0;
    for (ll add : v[j]) {
      while (it < res.size() && (xr ^ add) <= xr) {
        nres.push_back(res[it]);
        xr ^= nres.back();
        ++it;
      }
      if ((xr ^ add) <= xr) {
        fail = 1; break;
      } else {
        nres.push_back(add);
        xr ^= nres.back();
      }
    }
    while (it < res.size()) {
      nres.push_back(res[it]);
      ++it;
    }
    res.swap(nres);
  }
  if (fail) cout << "No\n";
  else {
    cout << "Yes\n";
    ll xr = 0;
    for (ll x : res) {
      cout << x << ' ';
      assert(xr < (xr ^ x));
      xr ^= x;
    }
    cout << endl;
  }
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  if (0) for (int n = 1; n <= 60; ++n) for (int test = 0; test < 10000; ++test) {
    vl b(n);
    for (int i = 0; i < n; ++i) b[i] = rand() % 1000000000000000000LL + 1;
    solve(b);
  }
  int n;
  cin >> n;
  vl b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  solve(b);
  return 0;
}