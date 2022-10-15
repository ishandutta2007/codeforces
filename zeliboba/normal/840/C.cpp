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

ll inv(ll x) {
  return mpow(x, mod - 2);
}

vl mul(const vl& x, const vl& y) {
  vl res(x.size() + y.size() - 1);
  for (int i = 0; i < x.size(); ++i) for (int j = 0; j < y.size(); ++j) {
    res[i+j] = (res[i+j] + x[i] * y[j]) % mod;
  }
  return res;
}

vl fac(500, 1);
vl invfac(fac.size(), 1);

int main() {
  for (int i = 2; i < fac.size(); ++i) {
    fac[i] = fac[i-1] * i % mod;
    invfac[i] = inv(fac[i]);
  }
  vi erat(100000, 1);
  for (int i = 2; i * i < erat.size(); ++i) if (erat[i]) {
    for (int j = i * i; j < erat.size(); j += i) erat[j] = 0;
  }
  vi P;
  for (int i = 2; i < erat.size(); ++i) if (erat[i]) P.push_back(i);
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    //a[i] = i + 1;
    int prod = 1;
    for (int d : P) {
      if (d * d > a[i]) break;
      int c = 0;      
      while (a[i] % d == 0) {
        a[i] /= d;
        ++c;
      }
      if (c % 2) prod *= d;
    }
    a[i] *= prod;
  }
  sort(a.begin(), a.end());
  vi k(1, 1);
  for (int i = 1; i < a.size(); ++i) {
    if (a[i] == a[i-1]) ++k.back();
    else k.push_back(1);
  }
  vl p(1, 1);
  for (int m : k) {
    vl q(m + 1);
    for (int i = 1; i <= m; ++i) {
      q[i] = ((m-i) % 2 == 1 ? -1 : 1) * invfac[i] * invfac[i-1] % mod * fac[m-1] % mod * invfac[m-i] % mod;
    }
    p = mul(p, q);
  }
  ll s = 0;
  for (int i = 0; i < p.size(); ++i) {
    s = (s + p[i] * fac[i]) % mod;
  }
  for (int x : k) s = s * fac[x] % mod;
  cout << (s + mod) % mod << endl;
  return 0;
}