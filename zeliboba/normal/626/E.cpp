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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<string> vs;

vi a;
vl s;
int n;
pll calc(int i, int m) {
  return pll(s.back() - s[n-m]+s[i+1]-s[i-m], 2*m+1);
}

bool les(const pll & a, const pll & b) {
  return a.first*b.second < a.second*b.first;
}

int main() {
  scanf("%d", &n);
  a.assign(n, 0);
  s.assign(n+1, 0);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; ++i) {
    s[i+1] = s[i] + a[i];
  }
  pll ma(0, 1);
  int pos = 0;
  for (int i = 1; i + 1 < a.size(); ++i) {
    int l = 1, r = min(i, n - i - 1);
    pll vl = calc(i, l);
    pll vr = calc(i, r);
    while (r - l > 10) {
      int d = r-l;
      int l1 = l + d/4;
      int r1 = r - d/4;
      pll vl1 = calc(i, l1);
      pll vr1 = calc(i, r1);
      if (les(vl1, vr1)) {
        l = l1;
      } else {
        r = r1;
      }
    }
    for (int j = l + 1; j <= r; ++j) {
      pll v = calc(i, j);
      if (les(vl, v)) vl = v;
    }
    vl.first -= vl.second*(ll)a[i];
    if (les(ma, vl)) {
      ma = vl;
      pos = i;
    }
  }
  vi res;
  int m = ma.second/2;
  for (int i = pos - m; i <= pos; ++i) res.push_back(a[i]);
  for (int i = n-m; i < n; ++i) res.push_back(a[i]);
  printf("%d\n", (int)res.size());
  for (auto x : res) printf("%d ", x);
  return 0;
}