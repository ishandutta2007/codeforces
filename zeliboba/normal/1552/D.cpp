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
  for (int test = 1; test <= T; ++test) {
    int n;
    cin >> n;
    vi a(n);
    bool ok = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      ok |= a[i] == 0;
    }
    for (int mask = 0; mask < (1 << n); ++mask) {
      vi v, rem;
      for (int i = 0; i < n; ++i) {
        if (mask & (1 << i)) {
          v.push_back(a[i]);
        } else {
          rem.push_back(a[i]);
        }
      }
      sort(rem.begin(), rem.end());
      for (int m1 = 0; m1 < (1 << v.size()); ++m1) {
        int s = 0;
        for (int i = 0; i < v.size(); ++i) {
          if (m1 & (1 << i)) s += v[i];
          else s -= v[i];
        }
        if (binary_search(rem.begin(), rem.end(), s)) ok = 1;
      }
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}