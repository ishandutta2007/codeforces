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
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

vvd mul(const vvd& a, const vvd& b) {
  int n = a.size();
  vvd res(n, vd(n));
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    for (int l = 0; l < n; ++l) {
      res[i][j] += a[i][l] * b[l][j];
    }
  }
  return res;
}

vvd mpow(vvd x, ll n) {
  vvd res(x.size(), vd(x.size()));
  for (int i = 0; i < res.size(); ++i) res[i][i] = 1;
  while (n) {
    if (n & 1) res = mul(res, x);
    x = mul(x, x);
    n /= 2;
  }
  return res;
}

int main() {
  int n, x;
  cin >> n >> x;
  vd p(x + 1);
  for (int i = 0; i < p.size(); ++i) {
    scanf("%lf", &p[i]);
    //p[i] = 1. / (x + 1);
  }
  vvd a(128, vd(128));
  for (int i = 0; i < 128; ++i) for (int t = 0; t <= x; ++t) {
    a[i^t][i] += p[t];
  }
  a = mpow(a, n);
  printf("%.10lf\n", 1 - a[0][0]);
  return 0;
}