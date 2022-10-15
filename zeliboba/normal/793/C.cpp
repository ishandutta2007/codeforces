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
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<string> vs;
//typedef long long int;

void upd(pll & x, pll y) {
  if (x.first * y.second < y.first * x.second)
    x = y;
}

void updmi(pll & x, pll y) {
  if (x.first * y.second > y.first * x.second)
    x = y;
}

int main() {
//std::ios::sync_with_stdio(false);
  int n;
  scanf("%d", &n);
  array<int, 2> mi, ma;
  scanf("%d%d%d%d", &mi[0], &mi[1], &ma[0], &ma[1]);
  vector<array<int, 2>> r(n), v(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d%d", &r[i][0], &r[i][1], &v[i][0], &v[i][1]);
  }
  bool ok = 1;
  pll tmi(0, 1);
  pll tma(1e9, 1);
  for (int i = 0; i < n; ++i) for (int j = 0; j < 2; ++j) {
    if (r[i][j] >= ma[j]) {
      if (v[i][j] >= 0) {
        ok = 0;
      } else {
        upd(tmi, pll(-ma[j] + r[i][j], -v[i][j]));
      }
    }
    if (r[i][j] <= mi[j]) {
      if (v[i][j] <= 0) {
        ok = 0;
      } else {
        upd(tmi, pll(mi[j] - r[i][j], v[i][j]));
      }
    }
    if (v[i][j] < 0) {
      updmi(tma, pll(-mi[j] + r[i][j], -v[i][j]));
    }
    if (v[i][j] > 0) {
      updmi(tma, pll(ma[j] - r[i][j], v[i][j]));
    }
  }
  /*
//  cerr << t.first << ' ' << t.second << ' ' << ok << endl;
  for (int i = 0; i < n; ++i) for (int j = 0; j < 2; ++j) {
    ll s = r[i][j] * tmi.second + v[i][j] * tmi.first;
//    cerr << i << ' ' << j << ' ' << s << ' ' << mi[j] * t.second << ' ' << ma[j] * t.second << endl;
    if (s < mi[j] * tmi.second || s > ma[j] * tmi.second) {
//      cerr << "!\n";
      ok = 0;
    }
  }*/
  if (!ok || tmi.first * tma.second >= tmi.second * tma.first) {
    printf("-1\n");
  } else {
    printf("%.10lf\n", tmi.first / (double)tmi.second + 1e-9);
  }
  return 0;
}