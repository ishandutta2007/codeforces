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

ll mpow(ll x, ll n, int mod) {
  ll res = 1;
  while (n) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n /= 2;
  }
  return res;
}

ll inv(ll x, int mod) {
  return mpow(x, mod - 2, mod);
}

pii f(int x, int mod) {
  int c = 0;
  while (x % mod == 0) {
    ++c;
    x /= mod;
  }
  return pii(x % mod, c);
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m, a, Q;
  cin >> n >> m >> a >> Q;
  if (a % Q == 1) {
    for (int i = 0; i < n; ++i) cout << 1 << ' ';
    cout << endl;
    return 0;
  }
  a %= Q;
  assert(__gcd(a, Q) == 1);
  vl pw(2e6, 1);
  int d = 0;
  for (int i = 1; i < pw.size(); ++i) {
    pw[i] = pw[i-1] * a % Q;
    if (pw[i] == 1) {
      d = i;
      break;
    }
  }
  vl c(m + 1, 1);
  vl r(m + 1, 1);
  vi cnt(m + 1, 0);
  for (int i = 1; i <= m; ++i) {
    pii num = f(m - i + 1, d), den = f(i, d);
    cnt[i] = cnt[i-1] + num.second - den.second;
    r[i] = r[i-1] * num.first % d * inv(den.first, d) % d;
    c[i] = cnt[i] ? 0 : r[i];
    assert(cnt[i] >= 0);
  }
  vi res(n);
  ll s = 0;
  for (int i = 0; i < n; ++i) {
    if (i < c.size()) s = (s + c[i]) % d;
    res[i] = mpow(a, s, Q);
  }
  for (int i = n-1; i >= 0; --i) cout << res[i] << ' ';
  cout << endl;
  return 0;
}