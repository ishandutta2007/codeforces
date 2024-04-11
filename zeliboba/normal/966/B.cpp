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
  int n;
  vi x(2);
  cin >> n >> x[0] >> x[1];
  vii a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }
  sort(a.begin(), a.end());
  vvi res(2);
  for (int i = 0; i < n && res[0].empty(); ++i) {
    for (int j = 0; j < 2 && res[0].empty(); ++j) {
      int k = (x[j] + a[i].first - 1) / a[i].first;
      int rem = n - i - k;
      if (rem <= 0 || a[n - rem].first * (ll)rem < x[1-j]) continue;
      for (int t = 0; t < k; ++t) {
        res[j].push_back(a[i + t].second);
      }
      for (int t = 0; t < rem; ++t) {
        res[1-j].push_back(a[n - t - 1].second);
      }
    }
  }
  if (res[0].empty()) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
    cout << res[0].size() << ' ' << res[1].size() << endl;
    for (int j = 0; j < 2; ++j) {
      for (int x : res[j]) cout << x << ' '; cout << endl;
    }
  }
  return 0;
}