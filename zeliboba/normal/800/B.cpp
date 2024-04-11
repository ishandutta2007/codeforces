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
typedef double ld;

ld p2(ld x) {
  return x*x;
}

ld dist(pii a, pii b) {
  return sqrt(p2(a.first-b.first)+p2(a.second-b.second));
}

int main() {
  int n;
  cin >> n;
  vii x(n);
  for (int i = 0; i < n; ++i) cin >> x[i].first >> x[i].second;
  ld D = 1e10;
  for (int i = 0; i < n; ++i) {
    pii a = x[i], b = x[(i + 1) % n], c = x[(i + 2) % n];
    ld la = dist(b, c);
    ld lb = dist(a, c);
    ld lc = dist(a, b);
    ld p = (la+lb+lc)/2;
    ld S = abs((c.second - a.second) * (ll)(b.first - a.first) - (b.second - a.second) * (ll)(c.first - a.first)) / 2.;//sqrt(p*(p-la)*(p-lb)*(p-lc));
    D = min(D, S / lb);
    D = min(D, S / la);
    D = min(D, S / lc);
  }
  printf("%.10lf\n", (double)D);
  return 0;
}