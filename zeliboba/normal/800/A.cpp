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

int main() {
  int n, p;
  scanf("%d%d", &n, &p);
  vi a(n), b(n);
  ll s = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a[i], &b[i]);
    s += a[i];
  }
  if (s <= p) {
    printf("-1\n");
    return 0;
  }
  double l = 0, r = 1e12;
  for (int t = 0; t < 70; ++t) {
    double x = (l + r) / 2;
    double need = 0;
    for (int i = 0; i < n; ++i) need += max(0., a[i] * x - b[i]);
    if (need <= p * x) {
      l = x;
    } else {
      r = x;
    }
  }
  printf("%.10lf\n", (l + r) / 2);
  return 0;
}