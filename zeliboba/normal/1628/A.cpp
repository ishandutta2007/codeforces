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
    vvi c(n + 2);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for (int i = n-1; i >= 0; --i) {
      c[a[i]].push_back(i);
    }
    int s = 0;
    vi b;
    while (s < n) {
      int nx = s;
      for (int m = 0; m <= n + 1; ++m) {
        if (c[m].empty()) {
          b.push_back(m);
          break;
        } else {
          nx = max(nx, c[m].back());
        }
      }
      for (int i = s; i <= nx; ++i) c[a[i]].pop_back();
      s = nx + 1;
    }
    cout << b.size() << '\n';
    for (int x : b) cout << x << ' ';
    cout << '\n';
  }
  return 0;
}