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
const int mod = 998244353;

vvi g;
vl d0, d1;

void dfs(int v) {
  for (int nv : g[v]) {
    dfs(nv);
  }
  if (g[v].empty()) {
    d0[v] = d1[v] = 1;
  } else {
    ll prod01 = 1, prod0 = 1;
    for (int nv : g[v]) {
      prod01 = prod01 * (d0[nv] + d1[nv]) % mod;
      prod0 = prod0 * d0[nv] % mod;
    }
    vl l(g[v].size() + 1, 1), r(g[v].size() + 1, 1);
    for (int i = 0; i < (int)g[v].size(); ++i) {
      int nv = g[v][i];
      l[i + 1] = l[i] * d0[nv] % mod;
    }
    for (int i = (int)g[v].size() - 1; i >= 0; --i) {
      int nv = g[v][i];
      r[i] = r[i + 1] * d0[nv] % mod;
    }
    ll s = 0;
    for (int i = 0; i < (int)g[v].size(); ++i) {
      int nv = g[v][i];
      s = (s + d1[nv] * l[i] % mod * r[i + 1]) % mod;
    }
    d1[v] = (prod01 - prod0) % mod;
    d0[v] = (prod01 - s) % mod;
  }
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  g.resize(n);
  d0.assign(n, 0);
  d1.assign(n, 0);
  for (int i = 0; i < n - 1; ++i) {
    int p;
    cin >> p;
    g[p - 1].push_back(i + 1);
  }
  dfs(0);
  cout << (d0[0] % mod + mod) % mod << endl;
  return 0;
}