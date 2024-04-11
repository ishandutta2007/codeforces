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
const int mod = 1e9 + 7;

ll mpow(ll x, ll n) {
  x %= mod;
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

vl primes(ll n) {
  vl p;
  for (ll x = 2; x * x <= n; ++x) if (n % x == 0) {
    p.push_back(x);
    while (n % x == 0) n /= x;
  }
  if (n > 1) p.push_back(n);
  return p;
}

inline int dw(int x) {
  if (x < mod) return x;
  return x - mod;
} 

ll f(ll n, ll k) {
  vl p = primes(n);
  unordered_map<ll, int> ind;
  vl divs;
  for (ll i = 1; i * i <= n; ++i) if (n % i == 0) {
    divs.push_back(i);
    if (i * i != n) divs.push_back(n / i);
  }
  sort(divs.begin(), divs.end());
  for (int i = 0; i < divs.size(); ++i) {
    ind[divs[i]] = i;
  }
//  cerr << num << ' ' << den << endl;
  vi d(divs.size());
  d[ind[n]] = 1;
  vector<vii> nx(p.size());
  vi sz(divs.size(), 1);
  for (int i = 0; i < p.size(); ++i) {
    for (int j = divs.size() - 1; j >= 0; --j) if (divs[j] % p[i] == 0) {
      nx[i].emplace_back(j, ind[divs[j] / p[i]]);
    }
  }
  for (int i = 0; i < p.size(); ++i) {
    for (int j = 0; j < divs.size(); ++j) if (divs[j] % p[i] == 0) {
      int nj = ind[divs[j] / p[i]];
      sz[j] += sz[nj];
    }
  }
  vi invsz(sz.size());
  for (int i = 0; i < sz.size(); ++i) {
    invsz[i] = inv(sz[i]);
  }
  ll num = 0, den = 0;
  for (int t = 1; t <= k; ++t) {
    for (int i = 0; i < d.size(); ++i) {
      d[i] = d[i] * (ll)invsz[i] % mod;
    }
    for (int i = 0; i < p.size(); ++i) {
      for (auto it : nx[i]) {
        d[it.second] = dw(d[it.second] + d[it.first]);
      }
    }
  }
  for (int i = 0; i < d.size(); ++i) {
//    cerr << "d: " << divs[i] << ' ' << d[i] << ' ' << sz[i] << endl;
    den = (den + d[i]) % mod;
    num = (num + divs[i] % mod * d[i]) % mod;
  }
/*  ll num = n % mod, den = 1;
  ll mul = 1;
  for (int l = 1; l <= min(k, 60LL); ++l) {
    mul = mul * (k - l + 1) % mod * inv(l) % mod;
    vl nd = d;
    for (int i = 0; i < p.size(); ++i) {
      for (auto it : nx[i]) {
        nd[it.second] = (nd[it.second] + nd[it.first]) % mod;
      }
    }
    for (int i = 0; i < d.size(); ++i) {
      d[i] = (nd[i] - d[i] + mod) % mod;
//      cerr << "d: " << divs[i] << ' ' << d[i] << endl;
      den = (den + d[i] * mul) % mod;
      num = (num + divs[i] % mod * d[i] * mul % mod) % mod;
    }
//    cerr << l << ' ' << mul << ' ' << num << ' ' << den << endl;
  }*/
  ll res = num * inv(den) % mod;
  return (res % mod + mod) % mod;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  ll n, k;
  cin >> n >> k;
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
//  cerr << f(n, k) << endl;
  vl p = primes(n);
  ll res = 1;
  for (ll x : p) {
    ll xpw = 1;
    while (n % x == 0) {
      xpw *= x;
      n /= x;
    }
    res = res * f(xpw, k) % mod;
  }
  cout << res << endl;
  return 0;
}