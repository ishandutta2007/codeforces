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

ll solve(ll x, ll l, ll r) {
  if (l > r) return 0;
  if (x <= 1) {
    return x;
  }
  ll len = 1;
  ll x1 = x / 2;
  while (x1 > 1) {
    len = 2 * len + 1;
    x1 /= 2;
  }
//  cerr << x << ' ' << l << ' ' << r << ' ' << len << endl;
  if (l == 1 && r == 2 * len + 1) return x;
  int res = x % 2 && l <= len + 1 && r >= len + 1;
  return res + solve(x / 2, l, min(r, len)) + solve(x / 2, max(l, len + 2) - len - 1, r - len - 1);
}

int main() {
  std::ios::sync_with_stdio(false);
  ll n, l, r;
  cin >> n >> l >> r;
  cout << solve(n, l, r) << endl;
  return 0;
}