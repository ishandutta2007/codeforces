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
  ll n, L;
  cin >> n >> L;
  vi c(n);
  for (int i = 0; i < n; ++i) cin >> c[i];
  for (int i = 1; i < n; ++i) c[i] = min(c[i], 2*c[i-1]);
  for (int i = n-2; i >= 0; --i) c[i] = min(c[i], c[i+1]);
  ll res = 1e18;
  ll sum = 0;
  for (int i = n-1; i >= 0; --i) {
    ll t = L / (1 << i);
    sum += t * c[i];
    L %= (1 << i);
    res = min(res, sum + (L ? c[i] : 0));
  }
  cout << res << endl;
  return 0;
}