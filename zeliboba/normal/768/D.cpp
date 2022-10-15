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
typedef long double ld;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

const ld eps = 1e-7;

int main() {
  //  std::ios::sync_with_stdio(false);
  int k, q;
  scanf("%d%d", &k, &q);
  vd d(k + 1);
  d[k] = 1;
  vd res(10000, 0);
  for (int t = 1; t < res.size(); ++t) {
    for (int i = 1; i < d.size(); ++i) {
      double good = (double)i / k;
      d[i-1] += d[i] * good;
      d[i] *= (1 - good);
    }
    res[t] = d[0];
  }
  for (int test = 0; test < q; ++test) {
    int p;
    scanf("%d", &p);
    if (k == 1) {
      printf("1\n");
      continue;
    }
    for (int i = 0; i < res.size(); ++i) {
      if (res[i] >= (p - eps) / 2000.) {
        printf("%d\n", i);
        break;
      }
    }
/*    cerr << q << ' ' << log(q) << ' ' << lgk << endl;
    ld q = 1 - pow(p / (ld)2000., 1. / (ld)k);
    cout << (ll)ceil(log(q) / lgk) << endl;*/
  }
  return 0;
}