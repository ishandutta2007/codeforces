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

void f(vii &a, vii& b) {
  sort(a.begin(), a.end());
  b.clear();
  b.assign(1, a[0]);
  for (int i = 1; i < a.size(); ++i) {
    if (a[i].first == a[i - 1].first) b.back().second += a[i].second;
    else b.emplace_back(a[i]);
  }
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T = 1;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    int n;
    cin >> n;
    vii a(n), b;
    for (int i = 0; i < n; ++i) {
      cin >> a[i].first;
      a[i].second = 1;
    }
    f(a, b);
    vii nb;
    for (int t = 0; t < n - 1; ++t) {
      nb.clear();
      for (int i = 0; i < b.size(); ++i) {
        if (i) {
          nb.emplace_back(b[i].first - b[i - 1].first, 1);
        }
        if (b[i].second > 1) nb.emplace_back(0, b[i].second - 1);
      }
      f(nb, b);
    }
    assert(b.size() == 1 && b[0].second == 1);
    cout << b[0].first << '\n';
  }
  return 0;
}