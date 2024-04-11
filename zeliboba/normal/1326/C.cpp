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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
const int mod = 998244353;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, k;
  cin >> n >> k;
  vi p(n);
  vi x;
  ll s = 0, c = 1;
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    if (p[i] >= n - k + 1) {
      x.push_back(i);
      s += p[i];
    }
  }
//  c = c * (x[0] + 1) % mod;
//  c = c * (n - x.back()) % mod;
  for (int i = 0; i + 1 < x.size(); ++i) {
    ll l = x[i + 1] - x[i];
    c = l * c % mod;
  }
  cout << s << ' ' << c << endl;
  return 0;
}