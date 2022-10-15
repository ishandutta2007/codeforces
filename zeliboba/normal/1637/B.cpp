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
  int T = 1;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vvi m(n, vi(n + 1));
    for (int i = 0; i < n; ++i) {
      vi was(n + 1);
      for (int j = i; j < n; ++j) {
        was[min(n, a[j])] = 1;
        for (int l = 0; l < was.size(); ++l) if (!was[l]) {
          m[i][j] = l + 1;
          break;
        }
      }
    }
    vvi d = m;
    ll s = 0;
    for (int len = 1; len <= n; ++len) {
      for (int i = 0; i <= n - len; ++i) {
        int j = i + len - 1;
        for (int p = i; p < j; ++p) {
          d[i][j] = max(d[i][j], m[i][p] + d[p + 1][j]);
        }
        s += d[i][j];
      }
    }
    cout << s << '\n';
  }
  return 0;
}