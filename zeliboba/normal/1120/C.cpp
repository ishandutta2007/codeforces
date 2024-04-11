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
#include <unordered_map>
#include <queue>
#include <array>
#include <bitset>
#include <chrono>
#include <random>
using namespace std;
typedef long double ld;
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
//const int mod = ;

vector<int> z_function (const string& s, int beg) {
  int n = (int) s.length();
  vector<int> z (n);
  for (int i=1, l=0, r=0; i<n-beg; ++i) {
    if (i <= r)
      z[i+beg] = min (r-i+1, z[i-l+beg]);
    while (i+z[i+beg] < n-beg && s[z[i+beg]+beg] == s[i+z[i+beg]+beg])
      ++z[i+beg];
    if (i+z[i+beg]-1 > r)
      l = i,  r = i+z[i+beg]-1;
  }
  return z;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, a, b;
  string s;
  cin >> n >> a >> b >> s;
  vvi z(n);
  for (int i = 0; i < n; ++i) {
    z[i] = z_function(s, i);
  }
  vl d(n, 1e18);
  d[0] = a;
  for (int i = 1; i < n; ++i) {
    d[i] = min(d[i], d[i - 1] + a);
    int ma = 0;
    for (int j = 0; j < i; ++j) {
      ma = max(ma, min(z[j][i], i - j));
    }
    for (int l = 1; l <= ma; ++l) {
      d[i + l - 1] = min(d[i + l - 1], d[i - 1] + b);
    }
//    cerr << i << ' ' << d[i] << ' ' << ma << endl;
  }
  cout << d.back() << endl;
  return 0;
}