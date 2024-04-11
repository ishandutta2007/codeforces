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
//const int mod = ;

int main() {
  //std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m;
  scanf("%d%d", &n, &m);
  vi a(n), b(n);
  bool fail = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] <= 1) fail = 1;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
    if (b[i] <= 1) fail = 1;
  }
  if (fail) {
    printf("-1\n");
    return 0;
  }
  double res = m;
  for (int i = n-1; i >= 0; --i) {
    int from = i, to = (i + 1) % n;
    res += res / (b[to] - 1);
    res += res / (a[from] - 1);
  }
  printf("%.15lf\n", res - m);
  return 0;
}