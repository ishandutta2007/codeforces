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
const int mod = 998244353;

ll mpow(ll x, ll n) {
  ll res = 1;
  while (n) {
    if (n % 2) res = res * x % mod;
    x = x * x % mod;
    n /= 2;
  }
  return res;
}

vl fac(1e6, 1);
vl invfac(fac.size(), 1);

ll bin(int n, int k) {
  return fac[n] * invfac[k] % mod * invfac[n - k] % mod;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  for (int i = 2; i < fac.size(); ++i) fac[i] = fac[i - 1] * i % mod;
  invfac.back() = mpow(fac.back(), mod - 2);
  for (int i = fac.size() - 2; i > 1; --i) invfac[i] = invfac[i + 1] * (i + 1) % mod;
  int T;
  cin >> T;
  for (int test = 0; test < T; ++test) {
    int n;
    string s;
    cin >> n >> s;
    s += '0';
    int c = 0, emp = 0, len = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '0') {
        ++emp;
        c += len / 2;
        len = 0;
      } else {
        ++len;
      }
    }
    cout << bin(c + emp - 1, c) << '\n';
  }
  return 0;
}