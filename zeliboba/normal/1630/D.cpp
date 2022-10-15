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
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

ll solve(vi a, int d) {
  ll s = 0;
  for (int i = 0; i < d; ++i) {
    int c = 0, mi = 1.1e9;
    ll sum = 0;
    for (int j = i; j < a.size(); j += d) {
      if (a[j] < 0) ++c;
      mi = min(mi, abs(a[j]));
      sum += abs(a[j]);
    }
    if (c % 2 == 0) s += sum;
    else s += sum - 2 * mi;
  }
  return s;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T = 1;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    int d = b[0];
    for (int i = 0; i < m; ++i) d = __gcd(d, b[i]);
    ll res = solve(a, d);
    for (int i = 0; i < d; ++i) a[i] *= -1;
    res = max(res, solve(a, d));
    cout << res << '\n';
  }
  return 0;
}