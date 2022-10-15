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

ll mpow(ll x, ll n) {
  ll res = 1;
  while (n) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n /= 2;
  }
  return res;
}

const int DEBUG = 0;

unordered_map<ll, vi> tovi;

ll mhash(const vi& v) {
  ll s = 0;
  for (int x : v) {
    s = 131 * s + x + 1;
  }
  if (!tovi.count(s)) {
    tovi[s] = v;
  }
  return s;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n = 6;
  if (!DEBUG) cin >> n;
  vvl p(n, vl(n, 50));
  vi pc(1 << n);
  for (int i = 0; i < (int)pc.size(); ++i) pc[i] = __builtin_popcount(i);
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    if (!DEBUG) cin >> p[i][j];
    p[i][j] = p[i][j] * mpow(100, mod - 2) % mod;
  }
  map<ll, int> d;
  d[mhash(vi(1 << n))] = 1;
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    map<ll, int> nd;
    cerr << i << ' ' << d.size() << endl;
    vl prods(1 << n);
    for (int mask = 0; mask < (1 << n); ++mask) {
      ll prod = 1;
      for (int j = 0; j < n; ++j) {
        if (mask & (1 << j)) {
          prod = prod * p[i][j] % mod;
        } else {
          prod = prod * (1 - p[i][j]) % mod;
        }
      }
      prods[mask] = prod;
    }
    for (const auto& it : d) {
      vi v = tovi[it.first];
      for (int mask = 0; mask < (1 << n); ++mask) {
        vi nv = v;
        bool fail = 0;
        for (int nmask = mask; nmask < (1 << n); nmask = (nmask + 1) | mask) {
          nv[nmask]++;
          if (nv[nmask] > pc[nmask]) {
            fail = 1;
            break;
          }
        }
        if (fail) continue;
        for (int j = 0; j < (int)nv.size(); ++j) {
          if (nv[j] + n - 1 - i <= pc[j]) nv[j] = 0;
        }
        ll h = mhash(nv);
        nd[h] = (nd[h] + prods[mask] * it.second) % mod;
      }
    }
    d.swap(nd);
  }
  for (auto& it : d) {
    res = (res + it.second) % mod;
  }
  cout << (res % mod + mod) % mod << endl;
  return 0;
}