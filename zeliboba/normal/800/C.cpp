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
using namespace std;
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

ll inv (ll a, ll b) {
  ll mod = b;
  ll xa = 1, xb = 0, ya = 0, yb = 1;
  while (a % b != 0) {
    ll t = a / b;
    a -= t * b;
    xa -= t * ya;
    xb -= t * yb;
    swap(a, b);
    swap(xa, ya);
    swap(xb, yb);
  }
  return (ya%mod + mod) % mod;
}

int divmod(int a, int b, int m) {
//  cerr << a << ' ' << b << ' ' << m << endl;
  int d = __gcd(m, b);
  assert(a % d == 0);
  a /= d;
  b /= d;
  m /= d;
  return a * (ll) inv(b, m) % m;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vi bad(m);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    bad[x % m] = 1;
  }
  vi div;
  vvi r;
  for (int d = 1; d <= m; ++d) if (m % d == 0) {
    div.push_back(d);
    r.push_back(vi());
    for (int i = 0; i < m; i += d) if (!bad[i]) {
      if (__gcd(i / d, m / d) == 1) {
//        cerr << d << ' ' << i << endl;
        r.back().push_back(i);
      }
    }
  }
  vi dyn(div.size()), nx(div.size());
  for (int i = dyn.size() - 1; i >= 0; --i) {
    dyn[i] = r[i].size();
    int ma = 0, best = -1;
    for (int j = i + 1; j < div.size(); ++j) if (div[j] % div[i] == 0) {
      if (ma < dyn[j]) {
        ma = dyn[j];
        best = j;
      }
    }
    dyn[i] += ma;
    nx[i] = best;
  }
  ll prod = 1;
  int cur = 0;
  vi res;
  while (cur != -1) {
    for (int rem : r[cur]) {
      res.push_back(divmod(rem, prod, m));
      prod = rem;
    }
    cur = nx[cur];
  }
  printf("%d\n", (int)res.size());
  prod = 1;
  for (int x : res) {
    printf("%d ", x);
    prod = prod * x % m;
    assert(!bad[prod]);
    bad[prod] = 1;
  }
  return 0;
}