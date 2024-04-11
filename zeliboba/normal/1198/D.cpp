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
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

int d[51][51][51][51];
int a[50][50];

int solve(int lx, int rx, int ly, int ry) {
  if (lx >= rx || ly >= ry) return 0;
  if (d[lx][rx][ly][ry] >= 0) return d[lx][rx][ly][ry];
  int res = max(rx - lx, ry - ly);
  if (max(rx - lx, ry - ly) == 1) {
    res = a[lx][ly];  
  } else if (rx - lx < ry - ly) {
    for (int i = ly + 1; i < ry; ++i) {
      res = min(res, solve(lx, rx, ly, i) + solve(lx, rx, i, ry));
    }
  } else {
    for (int i = lx + 1; i < rx; ++i) {
      res = min(res, solve(lx, i, ly, ry) + solve(i, rx, ly, ry));
    }
  }
  d[lx][rx][ly][ry] = res;
  return res;
}

const int DEBUG = 0;

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n = 50;
  if (!DEBUG) cin >> n;
  vs s(n);
  for (int i = 0; i < n; ++i) {
    if (!DEBUG) {
      cin >> s[i];
      for (int j = 0; j < n; ++j) {
        if (s[i][j] == '#') a[i][j] = 1;
      }
    } else {
      for (int j = 0; j < n; ++j) a[i][j] = rand() % 100 / 99;
    }
  }
  memset(d, -1, sizeof(d));
  cout << solve(0, n, 0, n) << endl;
  return 0;
}