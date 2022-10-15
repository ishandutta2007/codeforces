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
    if (n & 1) res = res *x % mod;
    x = x * x % mod;
    n /= 2;
  }
  return res;
}

ll res[1001][1001];
ll sum[1001][1001];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int k, a, b;
  cin >> k >> a >> b;
  ll p = a * mpow(a + b, mod-2) % mod;
  ll q = b * mpow(a + b, mod-2) % mod;
  ll p1 = mpow(p, mod-2);
  vl pw(k + 2, 1);
  vl pw1(pw.size(), 1);
  for (int i = 1; i < pw.size(); ++i) pw[i] = pw[i-1] * p % mod;
  for (int i = 1; i < pw.size(); ++i) pw1[i] = pw1[i-1] * p1 % mod;
//  vl sum(k + 1);
  for (int i = k; i >= 0; --i) {
    res[k][i] = k;
//  sum[k-i][i] = k * pw[i] % mod;
  }
  ll inv2 = mpow(p - 1, 2LL * (mod - 2));
  for (int s = k-1; s >= 0; --s) {
    for (int c = 0; c <= s; ++c) {
      int t = max(0, k - s - c + 0);
      ll geom = (s + c + t + p - p * (t + s + c)) % mod * pw[t] % mod * inv2 % mod;
      res[s][c] = (sum[s][max(c, 1)] * pw1[c] % mod + geom) * q % mod;
//      for (int i = 0; i < t; ++i) res[s][c] = (res[s][c] + res[s+c+i][c+i]*pw[i]) % mod;
//      cerr << res[s][c] << ' ' << sum[s][c] * pw1[c] % mod << endl;
//      res[s][c] = (res[s][c] + geom) * q % mod;
      sum[s - c][c] = (sum[s - c][c + 1] + res[s][c] * pw[c]) % mod;
//      cerr << s << ' ' << c << ' ' << t << ' ' << (geom+mod)%mod << ' ' << (res[s][c]+mod)%mod << ' ' << sum[s-c][c] << endl;
    }
  }
  cout << (res[0][0] * mpow(1 - q, mod-2) % mod + mod) % mod << endl;
//  cerr << res[0][0] << endl;
  return 0;
}