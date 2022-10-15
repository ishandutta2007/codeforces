#include <cstdio>
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

const ll i2 = (mod + 1) / 2;

array<int, 4> mul(const array<int, 4> & a, const array<int, 4> & b) {
  array<int, 4> c;
  c[0] = (a[0]*(ll)b[0] + a[1]*(ll)b[2]) % mod;
  c[1] = (a[0]*(ll)b[1] + a[1]*(ll)b[3]) % mod;
  c[2] = (a[2]*(ll)b[0] + a[3]*(ll)b[2]) % mod;
  c[3] = (a[2]*(ll)b[1] + a[3]*(ll)b[3]) % mod;
  return c;
}

array<int, 4> mpow(array<int, 4> x, ll n) {
  array<int, 4> res = {1, 0, 0, 1};
  while (n) {
    if (n & 1) res = mul(res, x);
    x = mul(x, x);
    n /= 2;
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  vl a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  array<int, 4> A = {0, 1, 2, 1};
  ll den = 2;
  for (int i = 0; i < n; ++i) {
    A = mpow(A, a[i]);
    den = mpow(den, a[i]);
  }
  cout << A[0]*i2%mod << "/" << den*i2%mod << endl;
  return 0;
}