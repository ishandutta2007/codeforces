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

int d[5005][5005];

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m;
  cin >> n >> m;
  string a, b;
  cin >> a >> b;
  int res = 0;
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    d[i + 1][j] = max(d[i + 1][j], d[i][j] - 1);
    d[i][j + 1] = max(d[i][j + 1], d[i][j] - 1);
    if (a[i] == b[j]) {
      d[i + 1][j + 1] = max(d[i + 1][j + 1], d[i][j] + 2);
      res = max(res, d[i + 1][j + 1]);
    }
  }
  cout << res << endl;
  return 0;
}