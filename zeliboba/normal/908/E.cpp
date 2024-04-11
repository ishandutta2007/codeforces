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
#include <bitset>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
const int mod = 1000000007;

ll mpow(ll x, ll n) {
  ll res = 1;
  while (n) {
    if (n & 1) res = res *x % mod;
    x = x * x % mod;
    n /= 2;
  }
  return res;
}

vi p, r;

int getp(int v) {
  if (p[v] == v) return v;
  return getp(p[v]);
}

void join(int a, int b) {
  a = getp(a);
  b = getp(b);
  if (a == b) return;
  if (r[a] > r[b]) swap(a, b);
  p[a] = b;
  r[b] += r[a];
}

ll d[1001][1001];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int m, n;
  cin >> m >> n;
  vs s(n);
  p.resize(m);
  for (int i = 0; i < m; ++i) p[i] = i;
  r.assign(m, 1);
  for (int i = 0; i < n; ++i) cin >> s[i];
  for (int a = 0; a < m; ++a) for (int b = a + 1; b < m; ++b) {
    bool ok = 1;
    for (int i = 0; i < n; ++i) if (s[i][a] != s[i][b]) {
      ok = 0; break;
    }
    if (ok) join(a, b);
  }
  vl f(m+1);
  d[0][0] = 1;
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= i; ++j) {
      d[i][j] = (d[i-1][j-1] + d[i-1][j] * j) % mod;
      f[i] = (f[i] + d[i][j]) % mod;
    }
  }
  ll res = 1;
  for (int i = 0; i < m; ++i) if (getp(i) == i) {
    res = res * f[r[i]] % mod;
  }
/*  vl pw(m + 1, 1);
  for (int i = 1; i < pw.size(); ++i) pw[i] = pw[i-1] * 2 % mod;
  vector<bitset<1000>> v(n);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < m; ++j) if (s[j] == '1') v[i].set(j);
  }
  int r = 0;
  for (int j = 0; j < m; ++j) {
    int s = -1;
    for (int i = r; i < n; ++i) if (v[i].test(j)) {
      s = i; break;
    }
    if (s == -1) continue;
    swap(v[s], v[r]);
    for (int l = 0; l < n; ++l) if (l != r && v[l].test(j)) {
      v[l] ^= v[r];
    }
    ++r;
  }
  cerr << r << endl;
  ll res = 1;
  for (int k = 1; k <= m-r; ++k) {
    ll prod = 1;
    for (int i = 1; i <= k; ++i) {
      prod = prod * (pw[m-r] - pw[i-1]) % mod * mpow(pw[k] - pw[i-1], mod-2) % mod;
    }
    cerr << k << ' ' << prod << ' ' << res << endl;
    res = (res + prod) % mod;
  }*/
  cout << (res + mod) % mod << endl;
  return 0;
}