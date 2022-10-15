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

vl fac(1.1e6, 1);
vl invfac(fac.size(), 1);
vl phi(fac.size(), 1);
vl erat(fac.size(), 1);

int eval(const vi& a) {
  int c = a[0] == a.back();
  for (int i = 0; i + 1 < a.size(); ++i) c += a[i] == a[i+1];
  return c;
}

void stupid(vi a) {
  sort(a.begin(), a.end());
  set<vi> w;
  ll c0 = 0, c1 = 0;
  do {
    c0 += eval(a);
    bool was = 0;
    vi b = a;
    for (int i = 0; i < a.size(); ++i) {
      int t = b[0];
      b.erase(b.begin());
      b.push_back(t);
      if (w.count(b)) was = 1;
    }
    if (!was) {
      w.insert(a);
      c1 += eval(a);
    }
  } while (next_permutation(a.begin(), a.end()));
  cerr << c0 << ' ' << c1 << ' ' << w.size() << ' ' << c1 * mpow(w.size(), mod - 2) % mod << endl;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  for (int i = 2; i < fac.size(); ++i) fac[i] = fac[i - 1] * i % mod;
  invfac.back() = mpow(fac.back(), mod - 2);
  for (int i = fac.size() - 2; i > 0; --i) invfac[i] = invfac[i + 1] * (i + 1) % mod;
  for (int i = 0; i < erat.size(); ++i) erat[i] = i;
  for (int i = 2; i * i < erat.size(); ++i) if (erat[i] == i) {
    for (int j = i * i; j < erat.size(); j += i) erat[j] = i;
  }
  for (int i = 2; i < phi.size(); ++i) {
    int p = erat[i];
    phi[i] = p - 1;
    int x = i / p;
    while (x % p == 0) {
      x /= p;
      phi[i] *= p;
    }
    phi[i] *= phi[x];
  }
  int T = 1;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    int n;
    cin >> n;
    vi a(n), c(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
      ++c[a[i]];
    }
//    stupid(a);
    vi cc(n + 1);
    for (int i = 0; i < n; ++i) cc[c[i]]++;
    if (cc[n] == 1) {
      cout << 1 << '\n';
      continue;
    }
    vii x;
    for (int i = 0; i < cc.size(); ++i) if (cc[i]) x.emplace_back(i, cc[i]);
    ll s = 0, cnt = 0;
    vii v;
    for (int d = 1; d <= n; ++d) if (n % d == 0) {
      v.clear();
      bool ok = 1;
      for (auto p : x) {
        if (p.first % d) ok = 0;
        else v.emplace_back(p.first / d, p.second);
      }
      if (!ok) continue;
      ll prod = 1;//fac[n / d];
      for (auto p : v) {
        prod = prod * mpow(invfac[p.first], p.second) % mod;
      }
      ll sum = 0;
      for (auto p : v) if (p.first >= 2) {
        sum = (sum + n * prod % mod * fac[p.first] % mod * invfac[p.first - 2] % mod * p.second % mod * fac[n / d - 2]) % mod;
      }
//      cerr << d << ' ' << phi[d] << ' ' << sum << endl;
//      s = (s + prod * phi[d]) % mod;
      s = (s + sum * phi[d]) % mod;
      cnt = (cnt + fac[n / d] * prod % mod * phi[d]) % mod;
    }
    cout << (mod + n - s * mpow(cnt, mod - 2) % mod) % mod << '\n';
  }
  return 0;
}