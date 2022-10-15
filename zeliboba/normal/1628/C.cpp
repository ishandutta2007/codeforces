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

const int DEBUG = 0;

int solve(vvi a) {
  int n = a.size();
  int res = 0;
  vvi w(n, vi(n));
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if ((i + j) % 4 == 0 && (i + j < n ? i % 2 == 0 : i % 2 == 1)) {
    res ^= a[i][j];
    if (DEBUG) for (int i1 = i-1; i1 <= i+1; ++i1) for (int j1 = j-1; j1 <= j+1; ++j1) if (abs(i-i1)+abs(j1-j) == 1 && i1 >= 0 && j1 >= 0 && i1<n && j1<n) w[i1][j1]++;
  }
  if (DEBUG) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if ((j + i) % 2 == 1) assert(w[i][j] == 1);
  return res;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T = 1;
  if (DEBUG) for (int n = 2; n <= 100; n+=2) {
    cerr << n << endl;
    vvi a(n, vi(n));
    solve(a);
  }
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    int n;
    cin >> n;
    vvi a(n, vi(n));
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];
    int res = solve(a);
    reverse(a.begin(), a.end());
    res ^= solve(a);
    cout << res << '\n';
  }
  return 0;
}