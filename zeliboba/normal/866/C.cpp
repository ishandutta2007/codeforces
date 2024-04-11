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

double calc(int i, int t, const vvd & d, const vi & a, const vi & b, const vd & p, int r) {
  double sum = p[i] * (a[i] + (t + a[i] <= r ? d[i+1][t+a[i]] : d[0][0])) + (1 - p[i]) * (b[i] + (t + b[i] <= r ? d[i+1][t+b[i]] : d[0][0]));
  return min(sum, d[0][0]);
}

int main() {
  //std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, R;
  scanf("%d%d", &n, &R);
  vi a(n), b(n);
  vd p(n);
  int sum = 0, sumb = 0;
  double prod = 1;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d%d%d", &a[i], &b[i], &x);
    p[i] = x / 100.;
    sum += a[i];
    sumb += b[i];
    prod *= p[i];
  }
  double l = sum, r = sumb / prod;
  for (int tt = 0; tt < 100; ++tt) {
    double x = (l + r) / 2;
    vvd d(n + 1, vd(R + 1, 1e18));
    d[0][0] = x;
    d[n].assign(R + 1, 0);
    for (int i = n - 1; i > 0; --i) {
      for (int j = 0; j < d[i].size(); ++j) d[i][j] = calc(i, j, d, a, b, p, R);
    }
//    cerr << l << ' ' << r << ' ' << x << ' ' << calc(0, 0, d, a, b, p, R) << endl;
    if (d[0][0] > calc(0, 0, d, a, b, p, R)) {
      r = x;
    } else {
      l = x;
    }
  }
  printf("%.10lf\n", (l + r) / 2);
  return 0;
}