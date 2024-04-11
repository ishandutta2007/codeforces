#include <stdio.h>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <queue>
#include <array>
#include <bitset>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef long double ld;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//typedef long long int;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  ll n, p, q, r;
  cin >> n >> p >> q >> r;
  vl b = {p, q, r};
  vl a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vvl d(n + 1, vl(4, -4e18));
  d[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    d[i+1] = d[i];
    for (int j = 0; j < 3; ++j) {
      d[i+1][j+1] = max(d[i+1][j+1], d[i+1][j] + b[j] * a[i]);
    }
  }
  cout << d.back().back() << endl;
  return 0;
}