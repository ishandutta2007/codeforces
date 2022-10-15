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
const int mod = 998244353;

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
  return mpow(x, mod-2);
}

ll c2(ll n) {
  return n * (n - 1) / 2 % mod;
}

int d[2001][2001];

void solve(int a, int b, int n) {
  ll p = a * inv(b) % mod;
  ll q = (mod + 1 - p) % mod;
  vl pwp(n+1, 1), pwq(n+1, 1);
  for (int i = 1; i < pwp.size(); ++i) {
    pwp[i] = pwp[i-1] * p % mod;
    pwq[i] = pwq[i-1] * q % mod;
  }
  vl cond(n + 1), f(n + 1);
  f[0] = f[1] = 0;
  cond[0] = cond[1] = 1;
  d[0][0] = 1;
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i <= k; ++i) {
      d[k+1][i] = (d[k+1][i] + d[k][i] * pwp[i]) % mod;
      d[k+1][i+1] = (d[k+1][i+1] + d[k][i] * pwq[k-i]) % mod;
    }
  }
  for (int i = 2; i < cond.size(); ++i) {
    cond[i] = 1;
    for (int j = 1; j < i; ++j) {
      cond[i] = (cond[i] - cond[j] * d[i][j]) % mod;
    }
    cond[i] = (cond[i] + mod) % mod;
    assert(cond[i] != 1);
  }
  for (int i = 2; i < f.size(); ++i) {
    f[i] = cond[i] * c2(i) % mod;
    for (int j = 1; j < i; ++j) {
      f[i] = (f[i] + cond[j] * d[i][j] % mod * (c2(j) + f[j] + f[i-j] + j * (i - j) % mod)) % mod;
    }
    f[i] = f[i] * inv(mod + 1 - cond[i]) % mod;
    f[i] = (f[i] + mod) % mod;
//    cerr << i << ' ' << cond[i] << ' ' << f[i] << endl;
  }
  cout << (f[n] + mod) % mod << endl;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  ll n, a, b;
  cin >> n >> a >> b;
  solve(a, b, n);
  return 0;
}