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
  int m = 1e9;
  vs s;
  for (int k = 1; k * k <= n; ++k) {
    int r = n - k * k;
    if (r % 2 == 0) {
      r /= 2;
      int nm = k + (r + k - 1) / k;
      if (nm < m) {
        m = nm;
        s.clear();
        string tmp(m, 'o');
        int full = r % k ? r % k : k;
        for (int i = 0; i < full; ++i) s.push_back(tmp);
        tmp[m - 1] = '.';
        for (int i = full; i < k; ++i) {
          s.push_back(tmp);
        }
        for (int i = k; i < m; ++i) tmp[i] = '.';
        for (int i = k; i < m; ++i) {
          if (i + 1 < m || r % k == 0) s.push_back(tmp);
          else {
            s.push_back(tmp);
            for (int j = r % k; j < m; ++j) s.back()[j] = '.';
          }
        }
        reverse(s.begin(), s.end());
      }
    }
  }
  if (m > n) cout << -1 << endl;
  else {
    cout << s.size() << endl;
    for (auto v : s) cout << v << endl;
  }
  return 0;
}