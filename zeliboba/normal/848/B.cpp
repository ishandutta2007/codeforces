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

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, w, h;
  cin >> n >> w >> h;
  vector<array<int, 3>> x, y;
  for (int i = 0; i < n; ++i) {
    int g, p, t;
    cin >> g >> p >> t;
    if (g == 1) {
      x.push_back({p - t, p, i});
    } else {
      y.push_back({p - t, p, i});
    }
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  int itx = 0, ity = 0;
  vii res(n);
  while (itx < x.size() || ity < y.size()) {
    vii vx, vy;
    int mi = 0;
    if (ity >= y.size() || (itx < x.size() && x[itx][0] <= y[ity][0])) {
      mi = x[itx][0];
    } else {
      mi = y[ity][0];
    }
    while (itx < x.size() && x[itx][0] == mi) {
      vx.emplace_back(x[itx][1], x[itx][2]);
      ++itx;
    }
    while (ity < y.size() && y[ity][0] == mi) {
      vy.emplace_back(y[ity][1], y[ity][2]);
      ++ity;
    }
    vii p;
    for (int i = 0; i < vy.size(); ++i) p.emplace_back(w, vy[i].first);
    for (int i = (int)vx.size() - 1; i >= 0; --i) p.emplace_back(vx[i].first, h);
    int it = 0;
    for (int i = (int)vx.size() - 1; i >= 0; --i) {
      res[vx[i].second] = p[it];
      ++it;
    }
    for (int i = 0; i < vy.size(); ++i) {
      res[vy[i].second] = p[it];
      ++it;
    }
//    cerr << mi << ' ' << vx.size() << ' ' << vy.size() << ' ' << p.size() << ' ' << it << endl;
  }
  for (int i = 0; i < n; ++i) {
    cout << res[i].first << ' ' << res[i].second << endl;
  }
  return 0;
}