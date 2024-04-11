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
#include <chrono>
#include <random>
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

vi p, r;

int getp(int v) {
  if (p[v] == v) return v;
  return p[v] = getp(p[v]);
}

bool join(int a, int b) {
  a = getp(a);
  b = getp(b);
  if (a == b) return false;
  if (r[a] > r[b]) swap(a, b);
  p[a] = b;
  r[b] += r[a];
  return true;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vl a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<array<ll, 3>> ts(m);
  for (int i = 0; i < m; ++i) {
    cin >> ts[i][1] >> ts[i][2];
    --ts[i][1]; --ts[i][2];
    ts[i][0] = a[ts[i][1]] ^ a[ts[i][2]];
  }
  ll rem = mpow(2, k), res = 0;
  sort(ts.begin(), ts.end());
  p.resize(n);
  r.assign(n, 1);
  for (int i = 0; i < n; ++i) p[i] = i;
  for (int t = 0; t < ts.size(); ++t) {
    if (t && ts[t][0] == ts[t-1][0]) continue;
    --rem;
    int comp = n;
    for (int t1 = t; t1 < ts.size() && ts[t1][0] == ts[t][0]; ++t1) {
      if (join(ts[t1][1], ts[t1][2])) --comp;
    }
    res = (res + mpow(2, comp)) % mod;
    for (int t1 = t; t1 < ts.size() && ts[t1][0] == ts[t][0]; ++t1) {
      r[ts[t1][1]] = r[ts[t1][2]] = 1;
      p[ts[t1][1]] = ts[t1][1];
      p[ts[t1][2]] = ts[t1][2];
    }
  }
  res = (res + rem * mpow(2, n)) % mod;
  cout << (res + mod) % mod << endl;
  return 0;
}