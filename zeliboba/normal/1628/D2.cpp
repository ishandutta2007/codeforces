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
const int mod = 1e9 + 7;
const ll inv2 = (mod + 1) / 2;

ll mpow(ll x, ll n) {
  ll res = 1;
  while (n) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n /= 2;
  }
  return res;
}

vl fac(1.1e6, 1);
vl invfac(fac.size(), 1);

ll bin(int n, int k) {
  return fac[n] * invfac[k] % mod * invfac[n - k] % mod;
}

ll n, m, k;

ll f(ll i) {
  if (i <= 0) return 0;
  return k * (2 * i - 1) % mod;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  for (int i = 2; i < fac.size(); ++i) fac[i] = fac[i - 1] * i % mod;
  invfac.back() = mpow(fac.back(), mod - 2);
  for (int i = fac.size() - 2; i > 0; --i) invfac[i] = invfac[i + 1] * (i + 1) % mod;
  int T = 1;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    cin >> n >> m >> k;
/*    vl d(2), nd;
    d[1] = k % mod;
    for (int t = 2; t <= n; ++t) {
      nd.assign(t + 1, 0);
      nd[t] = t * k % mod;
      for (int i = 1; i < t; ++i) nd[i] = (d[i - 1] + d[i]) * inv2 % mod;
      d.swap(nd);
    }*/
    ll res = 0;
    for (int i = 0; i <= n - 1; ++i) {
      res = (res + bin(n - 1, i) * f(m - i)) % mod;
    }
    cout << res * mpow(inv2, n - 1) % mod << '\n';
  }
  return 0;
}