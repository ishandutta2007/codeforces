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

const int B = 19;
int d[300001][B];
int last[B][B];
int was[B];

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, q;
  cin >> n >> q;
  vi a(n);
  for (int i = 0; i < B; ++i) for (int j = 0; j < B; ++j) last[i][j] = n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int j = 0; j < B; ++j) d[n][j] = n;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < B; ++j) {
      d[i][j] = n;
      was[j] = 0;
    }
    for (int j = 0; j < B; ++j) {
      if (a[i] & (1 << j)) {
        d[i][j] = i;
        was[j] = 1;
        for (int j1 = 0; j1 < B; ++j1) {
          d[i][j1] = min(d[i][j1], last[j][j1]);
        }
      }
    }
    for (int t = 0; t < B; ++t) {
      int mi = n, ind = 0;
      for (int j = 0; j < B; ++j) if (!was[j] && d[i][j] < mi) {
        mi = d[i][j];
        ind = j;
      }
      if (mi == n) break;
      was[ind] = 1;
      for (int j = 0; j < B; ++j) {
        d[i][j] = min(d[i][j], d[d[i][ind]][j]);
      }
    }
    for (int j = 0; j < B; ++j) if (a[i] & (1 << j)) {
      for (int j1 = j + 1; j1 < B; ++j1) if (a[i] & (1 << j1)) {
        last[j][j1] = last[j1][j] = i;
      }
    }
  }
  for (int t = 0; t < q; ++t) {
    int l, r;
    cin >> l >> r;
    --l; --r;
    int res = n;
    for (int j = 0; j < B; ++j) if (a[r] & (1 << j)) {
      res = min(res, d[l][j]);
    }
    cout << (res <= r ? "Shi" : "Fou") << '\n';
  }
  return 0;
}