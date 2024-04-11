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
typedef long double ld;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m;
  cin >> n >> m;
  vi c(m + 5);
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    c[a]++;
  }
  vi d(9, -1);
  d[0] = 0;
  for (int i = 1; i <= m; ++i) {
    vi nd(9, -1);
    for (int j = 0; j < 9; ++j) if (d[j] >= 0) {
      int j0 = j % 3, j1 = j / 3;
      for (int nj : {j1, j1 + 3, j1 + 6}) {
        int j2 = nj / 3;
        if (j0 + j1 + j2 <= c[i] && j1 + j2 <= c[i+1] && j2 <= c[i+2]) {
          nd[nj] = max(nd[nj], d[j] + j2 + (c[i] - j0 - j1 - j2) / 3);
        }
      }
    }
    d.swap(nd);
  }
  int res = 0;
  for (int x : d) res = max(res, x);
  cout << res << endl;
  return 0;
}