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
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;

bool in(int i, int j) {
  return i >= 0 && j >= 0 && i < n && j < m;
}

vvi f(const vs & v, pii s) {
  vvi d(n, vi(m, 10));
  vii q;
  d[s.first][s.second] = 0;
  for (int d1 = 0; d1 < 4; ++d1) {
    for (int t = 1; t < m + n; ++t) {
      int i = s.first + t * dx[d1];
      int j = s.second + t * dy[d1];
      if (!in(i, j) || v[i][j] == '*') break;
      q.emplace_back(i, j);
      d[i][j] = 0;
    }
  }
  for (pii x : q) {
    for (int d1 = 0; d1 < 4; ++d1) {
      for (int t = 1; t < m + n; ++t) {
        int i = x.first + t * dx[d1];
        int j = x.second + t * dy[d1];
        if (!in(i, j) || v[i][j] == '*') break;
        d[i][j] = min(d[i][j], 1);
      }
    }
  }
  return d;
}

int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> m;
  vs v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  pii v0, e;
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    if (v[i][j] == 'S') v0 = pii(i, j);
    if (v[i][j] == 'T') e = pii(i, j);
  }
  vvi d1 = f(v, v0), d2 = f(v, e);
  bool ok = 0;
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    if (d1[i][j] + d2[i][j] <= 1) ok = 1;
  }
  if (ok) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}