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
    int n, k;
    cin >> n >> k;
    if (n <= 4 && k == n - 1) {
      cout << -1 << '\n';
      continue;
    }
    vi p(n / 2);
    for (int i = 0; i < p.size(); ++i) p[i] = n - 1 - i;
    if (k != n - 1) {
      cout << n - 1 << ' ' << k << '\n';
      if (k != 0) cout << 0 << ' ' << n - 1 - k << '\n';
      for (int i = 1; i < p.size(); ++i) if (i != k && p[i] != k) cout << i << ' ' << p[i] << '\n';
    } else {
      cout << n - 1 << ' ' << n - 2 << '\n';
      cout << 1 << ' ' << 3 << '\n';
      cout << 0 << ' ' << n - 4 << '\n';
      for (int i = 2; i < p.size(); ++i) if (i != 3) cout << i << ' ' << p[i] << '\n';
    }
  }
  return 0;
}