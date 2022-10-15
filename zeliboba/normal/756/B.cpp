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
  int n;
  scanf("%d", &n);
  vi t(n);
  for (int i = 0; i < n; ++i) scanf("%d", &t[i]);
  array<int, 3> c = {20, 50, 120};
  array<int, 3> l = {1, 90, 1440};
  vl d(n + 1);
  for (int i = 0; i < n; ++i) {
    d[i+1] = d[i] + c[0];
    for (int j = 1; j < 3; ++j) {
      int it = i;
      while (it > 0 && t[it - 1] > t[i] - l[j]) --it;
      d[i+1] = min(d[i+1], d[it] + c[j]);
    }
  }
  for (int i = 1; i < d.size(); ++i) {
    printf("%lld\n", d[i] - d[i-1]);
  }
  return 0;
}