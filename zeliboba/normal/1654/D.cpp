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

vi erat(1e6);
vector<vector<array<int, 3>>> g;
unordered_map<int, int> bal, mi;//, ma;
ll prod = 0;

vii f(int x) {
  vii res;
  while (x > 1) {
    int p = erat[x], k = 0;
    while (x % p == 0) {
      x /= p;
      ++k;
    }
    res.emplace_back(p, k);
  }
  return res;
}

void dfs(int v, int p, ll val) {
  prod = (prod + val) % mod;
  for (auto x : g[v]) {
    int nv = x[0];
    if (nv == p) continue;
    vii mul = f(x[2]), den = f(x[1]);
    ll nval = val;
    for (auto p : mul) {
      bal[p.first] += p.second;
//      ma[p.first] = max(ma[p.first], bal[p.first]);
      nval = nval * mpow(p.first, p.second) % mod;
    }
    for (auto p : den) {
      bal[p.first] -= p.second;
      mi[p.first] = min(mi[p.first], bal[p.first]);
      nval = nval * mpow(p.first, mod - 1 - p.second) % mod;
    }
    dfs(nv, v, nval);
    for (auto p : mul) {
      bal[p.first] -= p.second;
    }
    for (auto p : den) {
      bal[p.first] += p.second;
    }
  }
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  for (int i = 1; i < erat.size(); ++i) erat[i] = i;
  for (int i = 2; i * i < erat.size(); ++i) if (erat[i] == i) {
    for (int j = i * i; j < erat.size(); j += i) erat[j] = i;
  }
  int T = 1;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    int n;
    cin >> n;
    g.clear();
    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
      int a, b, x, y;
      cin >> a >> b >> x >> y;
      --a; --b;
      int d = __gcd(x, y);
      x /= d; y /= d;
      g[a].push_back({b, x, y});
      g[b].push_back({a, y, x});
    }
    prod = 0;
    bal.clear();
    mi.clear();
//    ma.clear();
    dfs(0, -1, 1);
    for (auto p : mi) {
      assert(p.second <= 0);
      prod = prod * mpow(p.first, -p.second) % mod;
    }
    cout << prod << '\n';
  }
  return 0;
}