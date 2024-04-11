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

double p[1 << 6][1 << 6];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < (1 << n); ++i) for (int j = 0; j < (1 << n); ++j) {
    scanf("%lf", &p[i][j]);
    p[i][j] /= 100;
  }
  vvd win(1 << n, vd(n + 1, 1));
  for (int j = 1; j < win[0].size(); ++j) for (int i = 0; i < win.size(); ++i) {
    win[i][j] = 0;
    int B = 1 << (j-1);
    int s = (i ^ B) & ((1 << n) - B);
    for (int k = s; k < s + B; ++k) {
      win[i][j] += win[k][j-1] * p[i][k];
//      if (j == 1 && i == 0) cerr << win[k][j-1] << ' ' << p[i][k] << ' ' << k << endl;
    }
    win[i][j] *= win[i][j-1];
  }
  vvd d(1 << n, vd(n + 1, 0));
  for (int j = 1; j < win[0].size(); ++j) for (int i = 0; i < win.size(); ++i) {
    int B = 1 << (j-1);
    int s = (i ^ B) & ((1 << n) - B);
    double addlose = 0;
    for (int k = s; k < s + B; ++k) {
      addlose = max(addlose, d[k][j-1]);
    }
    d[i][j] = addlose + d[i][j-1] + win[i][j] * B;
//    cerr << j << ' ' << i << ' ' << win[i][j] << ' ' << d[i][j] << endl;
  }
  double res = 0;
  for (int i = 0; i < (1 << n); ++i) {
    res = max(res, d[i].back());
  }
  printf("%.13lf\n", res);
  return 0;
}