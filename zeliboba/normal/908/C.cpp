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
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

double p2(double x) {
  return x*x;
}

int main() {
//  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, r;
  scanf("%d%d", &n, &r);
  vi x(n);
  for (int i = 0; i < n; ++i) cin >> x[i];
  vd y(n, r);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      int d = abs(x[i] - x[j]);
      if (d <= 2 * r) {
        y[i] = max(y[i], y[j] + sqrt(p2(2*r) - p2(d)));
      }
    }
    printf("%.8lf ", y[i]);
  }
  return 0;
}