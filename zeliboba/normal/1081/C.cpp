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

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  ll res = m;
  for (int i = 1; i <= k; ++i) {
    res = res * (m - 1) % mod;
  }
  for (int i = 0; i < k; ++i) {
    res = res * (n - 1 - i) % mod * mpow(i + 1, mod - 2) % mod;
  }
  cout << res << endl;
  return 0;
}