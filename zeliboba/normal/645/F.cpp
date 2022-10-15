#include <cstdio>
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
//const int N = 10001;
const int N = 1000001;

ll mpow(ll x, ll n) {
  ll res = 1;
  while (n) {
    if (n & 1) res = res * x % mod;
    n /= 2;
    x = x * x % mod;
  }
  return res;
}

vl fac(N, 1);
vl invfac(N, 1);

ll c(int k, int n) {
  if (k < 0 || k > n) return 0;
  return fac[n] * invfac[n-k] % mod * invfac[k] % mod;
}

int main() {
  for (int i = 2; i < fac.size(); ++i) fac[i] = fac[i-1] * i % mod;
  invfac.back() = mpow(fac.back(), mod-2);
  for (int i = N - 2; i > 0; --i) invfac[i] = invfac[i+1] * (i+1) % mod;
//  for (int i = 1; i < N; ++i) assert(fac[i]*invfac[i] % mod == 1);
  vvi d(N);
  vl mul(N, 1);
//  vi mu(N, 1);
  for (int i = 1; i < N; ++i) {
    for (int j = i; j < N; j += i) {
      d[j].push_back(i);
    }
    if (i > 1) {
//      assert(d[i].size() >= 2);
      int p = d[i][1];
//      assert(d[p].size() == 2);
      int nx = i / p;
      while (nx % p == 0) nx /= p;
      mul[i] = mul[nx] * (ll)(i / nx - i / nx / p) % mod;
    }
/*    if (i > 1) {
      assert(d[i].size() >= 2);
      int p = d[i][1];
      assert(d[p].size() == 2);
      if (i / p % p == 0) mu[i] = 0;
      else mu[i] = -mu[i/p];
    }*/
  }
  int n, k, q;
  scanf("%d%d%d", &n, &k, &q);
  vi bin(300000);
  for (int i = 0; i < bin.size(); ++i) bin[i] = c(k, i);
  vi a(n);
  vi cnt(N);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    for (auto x : d[a[i]]) ++cnt[x];
  }
  ll res = 0;
  for (int i = 1; i < N; ++i) {
    res = (res + mul[i]*bin[cnt[i]]) % mod;
//    if (cnt[i]) cerr << i << ' ' << mul[i] << ' ' << cnt[i] << ' ' << c(k, cnt[i]) << ' ' << res << endl;
  }
  for (int t = 0; t < q; ++t) {
    int b;
    scanf("%d", &b);
    for (int x : d[b]) {
      res = (res - mul[x]*bin[cnt[x]]) % mod;
      ++cnt[x];
      res = (res + mul[x]*bin[cnt[x]]) % mod;
    }
    printf("%d\n", (int)((res % mod + mod) % mod));
  }
  return 0;
}