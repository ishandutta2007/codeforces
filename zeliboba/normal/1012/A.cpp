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
  int n;
  cin >> n;
  vl a(2*n);
  for (int i = 0; i < a.size(); ++i) cin >> a[i];
  sort(a.begin(), a.end());
  ll res = (a[n - 1] - a[0]) * (a.back() - a[n]);
  for (int i = 1; i < n; ++i) {
    res = min(res, (a.back() - a[0]) * (a[i + n - 1] - a[i]));
  }
  cout << res << endl;
  return 0;
}