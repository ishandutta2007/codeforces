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
const int mod = 1000000007;

ll mpow(ll x, ll n) {
  ll res = 1;
  while (n) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n /= 2;
  }
  return res;
}

vl fac(500000, 1);
vl invfac(fac.size(), 1);

ll bin(int k, ll n) {
  if (k == -1 && n == -1) return 1;
  if (k < 0 || k > n) return 0;
  return fac[n] * invfac[k] % mod * invfac[n-k] % mod;
}

int main() {
  std::ios::sync_with_stdio(false);
  for (int i = 2; i < fac.size(); ++i) {
    fac[i] = fac[i-1] * i % mod;
  }
  invfac.back() = mpow(fac.back(), mod - 2);
  for (int i = fac.size() - 2; i > 0; --i) {
    invfac[i] = invfac[i+1] * (i + 1) % mod;
  }
  int a, b, h;
  cin >> a >> b >> h;
  ll p = 0, q = 0;
  for (int l = 1; l <= a + b; ++l) {
    int l1 = (l + 1) / 2, l2 = l / 2;
    q = (q + bin(l1 - 1, a - 1) * bin(l2 - 1, b - 1) + bin(l2 - 1, a - 1) * bin(l1 - 1, b - 1)) % mod;
    p = (p + bin(l1 - 1, a - 1) * bin(l2 - 1, b - 1 - h * (ll)l2) + bin(l2 - 1, a - 1) * bin(l1 - 1, b - 1 - h * (ll)l1)) % mod;
  }
  //cerr << p << ' ' << q << endl;
  cout << p * mpow(q, mod - 2) % mod << endl;
  return 0;
}