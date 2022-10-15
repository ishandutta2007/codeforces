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
    int a, b;
    cin >> a >> b;
    int n = a + b;
    vi w(n + 1);
    for (int x = 0; x < 2; ++x) {
      vi y = {a, b};
      vi z = {n / 2, n / 2};
      if (n % 2) z[x]++;
      for (int c = 0; c <= min(y[0], z[0]); ++c) if (y[0] - c <= z[1]) {
        w[z[0] - c + y[0] - c] = 1;
      }
    }
    int m = 0;
    for (int i = 0; i <= n; ++i) if (w[i]) ++m;
    cout << m << '\n';
    for (int i = 0; i <= n; ++i) if (w[i]) cout << i << ' ';
    cout << '\n';
  }
  return 0;
}