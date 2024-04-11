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

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vvi v(n, vi(n));
  int t = 0;
  for (int i = 0; i < n; i += 2) for (int j = 0; j < n; j += 2) {
    v[i][j] = t;
    v[i + 1][j] = t + 1;
    v[i][j + 1] = t + 2;
    v[i + 1][j + 1] = t + 3;
    t += 4;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cout << v[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}