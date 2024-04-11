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
  for (int tt = 0; tt < T; ++tt) {
    int n, m;
    cin >> n >> m;
    vs s(n);
    string col(2, '.');
    bool fail = 0;
    for (int i = 0; i < n; ++i) {
      cin >> s[i];
      for (int j = 0; j < m; ++j) if (s[i][j] != '.') {
        int t = (i + j) % 2;
        if (col[t] != '.' && col[t] != s[i][j]) {
          fail = 1;
        }
        col[t] = s[i][j];
      }
    }
    if (col[0] != '.' && col[0] == col[1] && n + m > 1) fail = 1;
    if (fail) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (int t = 0; t < 2; ++t) if (col[t] == '.') {
        if (col[1 - t] != '.') {
          col[t] = col[1 - t] == 'W' ? 'R' : 'W';
        } else {
          col[t] = 'W';
        }
      }
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) s[i][j] = col[(i + j) % 2];
        cout << s[i] << '\n';
      }
    }
  }
  return 0;
}