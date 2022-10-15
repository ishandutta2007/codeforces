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
const short mod = 31607;

ll mpow(ll x, ll n) {
  ll res = 1;
  while (n) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n /= 2;
  }
  return res;
}

int a[22][22];
const int DEBUG = 0;

void invconv(vector<short> & x) {
  for (int b = 1; b < x.size(); b *= 2) {
    for (int s = b; s < x.size(); s += 2 * b) for (int i = s; i < s + b; ++i) {
      x[i] = (x[i] - x[i^b]) % mod;
    }
  }
}

int n = 21;

void out(vi v) {
  for (int i : v) cerr << i << ' ';
  cerr << endl;
}

int solve() {
  int M = 1 << (n + 2);
  vector<short> v(M, 1), v1(M);
  for (int i = 0; i < n; ++i) {
    int mul = 1;
    for (int j = 0; j < n; ++j) mul = mul * a[i][j] % mod;
    for (int mask = 0; mask < M; ++mask) v[mask] = v[mask] * mul % mod;
    v1 = v;
    for (int j = 0; j < n; ++j) {
      int d1 = (i + j == (n - 1)) ? (1 << n) : 0;
      int d2 = (i == j) ? (1 << (n + 1)) : 0;
      int B = (1 << j) | (d1) | (d2);
      int inv = mpow(a[i][j], mod - 2);
      for (int mask = B; mask < M; mask = ((mask + 1) | B)) {
        v[mask] = v[mask] * inv % mod;
      }
    }
    for (int mask = 0; mask < M; ++mask) v[mask] = (v[mask] - v1[mask]) % mod;
  }
  invconv(v);
  int res = 1 - v[(1 << (n + 2)) - 1];
  return (res % mod + mod) % mod;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  if (!DEBUG) cin >> n;
  ll den = mpow(10000, mod - 2);
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    if (!DEBUG) cin >> a[i][j];
    else a[i][j] = rand() % 10000;
    a[i][j] = a[i][j] * den % mod;
  }
//  cout << stupid() << ' ' << solve() << endl;
  cout << solve() << endl;
  return 0;
}