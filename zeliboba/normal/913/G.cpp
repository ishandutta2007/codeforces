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

ll dw(ll a, ll b) {
  if (a >= b) return a-b;
  return a;
}

ll mul(ll x, ll y, ll mod) {
  ll res = 0;
  if (x < y) swap(x, y);
  while (y) {
    if (y & 1) res = dw(res + x, mod);
    x = dw(2 * x, mod);
    y /= 2;
  }
  return res;
}

ll mpow(ll x, ll n, ll mod) {
  ll res = 1;
  while (n) {
    if (n & 1) res = mul(res, x, mod) % mod;
    x = mul(x, x, mod);
    n /= 2;
  }
  return res;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    ll a;
    cin >> a;
    ll pw10 = 10, pw5 = 5, pw = 1;
    while (pw10 <= a) {
      pw10 *= 10;
      pw5 *= 5;
      ++pw;
    }
    for (ll t = 1, p5 = 5, p10 = 10; ; ++t, p5 *= 5, p10 *= 10) {
      assert(t < 10);
      ll p2 = (1LL << (t + pw));
      ll rem = p2 - (a % p2) * (p10 % p2) % p2;
      while (rem < p10 && rem % 5 == 0) {
        rem += p2;
      }
      if (rem < p10) {
        ll mod = p5 * pw5;
//        cerr << a << ' ' << t << ' ' << rem << ' ' << mod << endl;
        ll rem5 = (rem + (a << t) % pw5 * p5) % mod;
        assert(rem5 % 5);
        ll k = 0;
        while ((1LL << k) % 5 != rem5 % 5) ++k;
        for (ll i = 2, curp5 = 25; i <= pw + t; ++i, curp5 *= 5) {
//          cerr << i << ' ' << k << endl;
          while (mpow(2, k, curp5) != rem5 % curp5) {
            k += curp5 / 5 / 5 * 4;
          }
        }
        while (k < t + pw) {
          k += mod / 5 * 4;
        }
        cout << k << endl;
        assert(mpow(2, k, p2) == (a * p10 + rem) % p2);
        assert(mpow(2, k, mod) == (a * p10 + rem) % mod);
//        if (k < 128)
        break;
      }
    }
  }
  return 0;
}