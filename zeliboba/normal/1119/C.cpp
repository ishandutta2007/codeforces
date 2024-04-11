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
  vvi a(n, vi(m));
  vvi b = a;
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> b[i][j];
  for (int i = 0; i + 1 < n; ++i) for (int j = 0; j + 1 < m; ++j) if (a[i][j] != b[i][j]) {
    for (int x = 0; x < 2; ++x) for (int y = 0; y < 2; ++y) {
      a[i+x][j+y] ^= 1;
    }
  }
  if (a == b) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return 0;
}