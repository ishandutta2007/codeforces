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

int d[100][100];
vii b[100][100];
const int DEBUG = 0;

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n = 80, k = 10;
  if (!DEBUG) cin >> n >> k;
  const int MAX = 2e9;
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    if (!DEBUG) cin >> d[i][j];
    else d[i][j] = rand() % 100000000;
  }
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    b[i][j] = vii(4, pii(MAX, 0));
    for (int m = 0; m < n; ++m) if (m != i && m != j) {
      pii x(d[i][m] + d[m][j], m);
      for (int t = 0; t < (int)b[i][j].size(); ++t) {
        if (x <= b[i][j][t]) swap(x, b[i][j][t]);
      }
    }
  }
  ll res = 1e18;
  vi used(n);
  used[0] = 1;
  array<int, 6> v;
  for (int i1 = 0; i1 < n; ++i1) {
    for (int i2 = 0; i2 < n; ++i2) {
      for (int i3 = 0; i3 < n; ++i3) {
        for (int i4 = 0; i4 < n; ++i4) {
          v = {0, i1, i2, i3, i4, 0};
          for (int i = 0; i < k / 2; ++i) used[v[i]] = 1;
          v[k / 2] = 0;
          ll cand = 0;
          for (int t = 0; t < k / 2; ++t) {
            int x = v[t], y = v[t + 1];
            int val = MAX;
            for (pii p : b[x][y]) if (!used[p.second]) {
              val = p.first;
              break;
            }
            cand += val;
          }
          res = min(res, cand);
          for (int i = 0; i < k / 2; ++i) used[v[i]] = 0;
        }
      }
    }
  }
  cout << res << endl;
  return 0;
}