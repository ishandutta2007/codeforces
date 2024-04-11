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
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
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

const int N = 5005;
ll d[N][26];
ll sum[N];
vl fac(N, 1);
vl invfac(N, 1);

int main() {
  for (int i = 1; i < fac.size(); ++i) {
    fac[i] = fac[i-1] * i % mod;
    invfac[i] = mpow(fac[i], mod-2);
  }
  int n;
  string s;
  cin >> n >> s;
  sum[0] = 1;
  for (int i = 0; i < n; ++i) {
    int t = s[i] - 'a';
    for (int k = 0; k <= i; ++k) {
      ll nd = sum[k] - d[k][t];
      sum[k+1] = (sum[k+1] - d[k+1][t] + nd) % mod;
      d[k+1][t] = nd;
    }
  }
  ll res = 0;
  for (int k = 1; k <= n; ++k) {
//    cerr << k << ' ' << sum[k] << endl;
    res = (res + sum[k] * fac[n-1] % mod * invfac[k-1] % mod * invfac[n-k]) % mod;
  }
  cout << (res % mod + mod) % mod << endl;
  return 0;
}