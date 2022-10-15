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
//const int mod = ;

double d[2][101][1001];

inline void upd(double& a, double b) {
  a = min(a, b);
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  //std::ios::sync_with_stdio(false); std::cin.tie(0);
  vd pw(105, 1);
  for (int i = 1; i < (int)pw.size(); ++i) {
    pw[i] = pw[i-1] / 0.9;
  }
  int TT;
  scanf("%d", &TT);
  for (int test = 1; test <= TT; ++test) {
    int n;
    double C, T;
    scanf("%d%lf%lf", &n, &C, &T);
    vii a(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &a[i].first, &a[i].second);
    }
    sort(a.rbegin(), a.rend());
    int tt = 0;
    const double MAX = 1e18;
    for (int i = 0; i <= n; ++i) for (int j = 0; j <= 10 * n; ++j) {
      d[tt][i][j] = MAX;
    }
    d[tt][0][0] = 0;
    for (int i = 0; i < n; ++i) {
      tt = 1-tt;
      memcpy(d[tt], d[1-tt], sizeof(d[tt]));
      for (int k = 0; k < n; ++k) for (int s = 0; s <= 10 * k; ++s) {
        upd(d[tt][k + 1][s + a[i].second], d[1-tt][k][s] + a[i].first * pw[k + 1]);
      }
    }
    int res = 0;
//    const double eps = 1e-10;
    for (int k = 1; k <= n; ++k) for (int s = 1; s <= 10 * k; ++s) {
      double D = d[tt][k][s];
      double T1 = T - 10 * k;
      if (T1 <= 0) continue;
//      if (D < MAX) cerr << k << ' ' << s << ' ' << T1 << ' ' << D << endl;
      if (D <= T1) {
        res = max(res, s);
        continue;
      }
      double t = (sqrt(C * D) - 1) / C;
//      if (D < MAX) cerr << t << ' ' << t + D / (1 + t * C) << endl;
      if (t >= 0 && t <= T1 && t + D / (1 + t * C) <= T1) {
        res = max(res, s);
        continue;
      }
    }
    printf("%d\n", res);
  }
  return 0;
}