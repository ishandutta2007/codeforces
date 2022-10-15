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

int main() {
  int n,k,s,t;
  scanf("%d%d%d%d", &n, &k, &s, &t);
  vi v(n), c(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &c[i], &v[i]);
  }
  vi x(k);
  for (int i = 0; i < k; ++i) scanf("%d", &x[i]);
  x.push_back(0);
  x.push_back(s);
  sort(x.begin(), x.end());
  int l = 0, r = 1000000001;
  while (r - l > 1) {
    int m = (l + r) / 2;
    ll mint = 0;
    for (int i = 0; i + 1 < x.size(); ++i) {
      if (m < x[i+1] - x[i]) {
        mint = 1e10;
        break;
      } else {
        int d = x[i+1] - x[i];
        int rem = m - d;
        mint += max(d, 2 * d - rem);
      }
    }
    if (mint > t) {
      l = m;
    } else {
      r = m;
    }
  }
  bool ok = 0;
  int res = 2e9;
  for (int i = 0; i < n; ++i) if (v[i] >= r) {
    res = min(res, c[i]);
    ok = 1;
  }
  if (!ok) res = -1;
  printf("%d\n", res);
  return 0;
}