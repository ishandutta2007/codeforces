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

vl sur;
const int B = 500;
ll bin[B][B];
vl pw2, invpw2;
vi d[100005];
int sz[100005];
int n, k;

vi mul(const vi& a, const vi& b) {
  vi res(min(k + 1, (int)(a.size() + b.size()) - 1));
  for (int i = 0; i < a.size(); ++i) for (int j = 0; j < b.size(); ++j) {
    if (i + j > k) break;
    res[i+j] = (res[i+j] + a[i]*(ll)b[j]) % mod;
  }
  return res;
}

vvi g;
ll res = 0;

void dfs(int v, int p) {
  d[v].assign(1, 1);
  sz[v] = 1;
  vi sum(k + 1);
  for (int nv : g[v]) if (nv != p) {
    dfs(nv, v);
    sz[v] += sz[nv];
    d[v] = mul(d[v], d[nv]);
    for (int i = 0; i < d[nv].size(); ++i) sum[i] = (sum[i] + d[nv][i]) % mod;
  }
  for (int i = 1; i < d[v].size(); ++i) {
    res = (res + (d[v][i] - sum[i]) * (ll)sur[i]) % mod;
//    cerr << "dw: " << i << ' ' << v << ' ' << d[v][i] * pw2[n] % mod << ' ' << sum[i] * pw2[n] % mod << ' ' << sur[i] << endl;
  }
  if (d[v].size() <= k) d[v].push_back(0);
  if (p != -1) for (int i = d[v].size() - 2; i >= 0; --i) {
    if (i != 0) res = (res + d[v][i] * (ll)(1 - invpw2[n - sz[v]]) % mod * sur[i + 1]) % mod;
    else res = (res + (1 - invpw2[sz[v]]) * (ll)(1 - invpw2[n - sz[v]]) % mod * sur[i + 1]) % mod;
//    cerr << "up: " << i+1 << " v: " << v << " d: " << d[v][i] * pw2[n] % mod << " sur: " << sur[i+1] << " sz: " << sz[v] << " res: " << res * pw2[n] % mod << endl; //" inv: " << invpw2[n - sz[v]] << endl;
    if (i != 0) d[v][i + 1] = (d[v][i + 1] + d[v][i]) % mod;
    else d[v][i + 1] = (d[v][i + 1] + d[v][i] * (ll)(1 - invpw2[sz[v]])) % mod;
  }
//  cerr << "d " << v << ": ";
  for (int i = 0; i < d[v].size(); ++i) {
    if (d[v][i] < 0) d[v][i] += mod;
//    cerr << d[v][i] * pw2[n] % mod << ' '; cerr << endl;
  }
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  for (int i = 0; i < B; ++i) {
    bin[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      bin[i][j] = (bin[i-1][j-1] + bin[i-1][j]) % mod;
    }
  }
  cin >> n >> k;
  pw2.assign(n + 1, 1);
  invpw2.assign(n + 1, 1);
  for (int i = 1; i < pw2.size(); ++i) {
    pw2[i] = pw2[i-1] * 2 % mod;
    invpw2[i] = inv(pw2[i]);
  }
  g.resize(n);
  for (int i = 0; i < n-1; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  sur.assign(k + 1, 0);
  for (int m = 1; m < sur.size(); ++m) {
    for (int i = 0; i <= m; ++i) {
      int zn = i % 2 ? -1 : 1;
      sur[m] = (sur[m] + zn * mpow(m - i, k) * bin[m][i]) % mod;
    }
    sur[m] = (sur[m] + mod) % mod;
  }
  dfs(0, -1);
  res = res * pw2[n] % mod;
  cout << (res + mod) % mod << endl;
  return 0;
}