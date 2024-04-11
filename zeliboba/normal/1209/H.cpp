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
#include <unordered_map>
#include <queue>
#include <array>
#include <bitset>
#include <chrono>
#include <random>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<ld> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  //std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, L;
  scanf("%d%d", &n, &L);
  vi x0(n), y0(n);
  vector<double> v0(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%lf", &x0[i], &y0[i], &v0[i]);
  }
  vd l, v;
  if (x0[0] > 0) {
    l.push_back(x0[0]);
    v.push_back(0);
  }
  for (int i = 0; i < n; ++i) {
    l.push_back(y0[i] - x0[i]);
    v.push_back(v0[i]);
    if (i + 1 < n && y0[i] < x0[i + 1]) {
      l.push_back(x0[i + 1] - y0[i]);
      v.push_back(0);
    }
    if (i + 1 == n && y0[i] < L) {
      l.push_back(L - y0[i]);
      v.push_back(0);
    }
  }
  vd x(v.size(), 2), t(v.size());
  set<pair<double, int>> w;
  double bal = 0, res = 0;
  const double eps = 1e-10;
  for (int i = 0; i < v.size(); ++i) {
    w.insert(make_pair(v[i], i));
    t[i] = l[i] / (v[i] + x[i]);
    bal += t[i] * (1 - x[i]);
    res += t[i];
    while (bal < -eps) {
      assert(!w.empty());
      auto it = w.end();
      --it;
      int j = it->second;
      bal -= t[j] * (1 - x[j]);
      res -= t[j];
      if (v[j] > eps && bal + l[j] / v[j] < eps) {
        x[j] = 0;
      } else {
        x[j] = max((ld)0., min((ld)2., (l[j] + bal * v[j]) / (l[j] - bal)));
      }
      if (x[j] < eps) {
        w.erase(it);
      }
      t[j] = l[j] / (v[j] + x[j]);
      bal += t[j] * (1 - x[j]);
      res += t[j];
    }
  }
  printf("%.15lf\n", (double)res);
  return 0;
}