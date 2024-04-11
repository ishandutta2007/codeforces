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
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  const int MAX = 1e9;
  vvi d(3, vi((n + 3) / 2, MAX));
  d[1][0] = 0;
  for (int i = 0; i < n; ++i) {
    vvi nd(3, vi(d[0].size(), MAX));
    for (int t = 0; t < 3; ++t) for (int j = 0; j < (int)d[t].size(); ++j) if (d[t][j] < MAX) {
//      if (j) cerr << i << ' ' << t << ' ' << j << ' ' << d[t][j] << endl;
      if (t == 0) {
        //assert(i >= 1);
        nd[2][j] = min(nd[2][j], d[t][j] + max(0, a[i] - a[i - 1] + 1));
      } else {
        nd[1][j] = min(nd[1][j], d[t][j]);
        if (t == 1) {
          //assert(i >= 1);
          nd[0][j + 1] = min(nd[0][j + 1], d[t][j] + max(0, i > 0 ? a[i - 1] - a[i] + 1 : 0));
        } else {
          //assert(i >= 2);
          nd[0][j + 1] = min(nd[0][j + 1], d[t][j] + max(0, min(a[i - 1], a[i - 2] - 1) - a[i] + 1));
        }
      }
    }
    d.swap(nd);
  }
  for (int i = 1; i < (int)d[0].size(); ++i) {
    int mi = MAX;
    for (int j = 0; j < 3; ++j) mi = min(mi, d[j][i]);
    cout << mi << ' ';
  }
  cout << endl;
  return 0;
}