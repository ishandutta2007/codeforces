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
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n, m;
    cin >> n >> m;
    vs s(n, string(m, '0'));
    for (int i = 0; i < m; i += 2) s[0][i] = '1';
    for (int i = 0; i < n; i += 2) s[i][0] = '1';
    for (int i = 2; i < m; i += 2) s[n-1][i] = '1';
    for (int i = 2; i + 2 < n; i += 2) s[i][m-1] = '1';
    for (int i = 0; i < n; ++i) cout << s[i] << '\n';
    cout << '\n';
  }
  return 0;
}