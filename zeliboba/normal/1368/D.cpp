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
//const int mod = ;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vl a(n);
  vi c(20);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    for (int j = 0; j < c.size(); ++j) if (a[i] & (1 << j)) ++c[j];
  }
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    ll x = 0;
    for (int j = 0; j < c.size(); ++j) if (c[j]) {
      --c[j];
      x |= 1 << j;
    }
    res += x * x;
  }
  cout << res << endl;
  return 0;
}