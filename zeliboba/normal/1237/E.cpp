#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vi ok(n + 1);
  vvi d(25, vi(2));
  d[1][1] = ok[1] = 1;
  for (int h = 2; h < d.size(); ++h) {
    for (int t = 0; t < 2; ++t) {
      d[h][t] = 1 + d[h - 1][0] + d[h - 1][1 - t];
      if (d[h][t] < ok.size()) ok[d[h][t]] = 1;
    }
  }
  cout << ok[n] << endl;
  return 0;
}