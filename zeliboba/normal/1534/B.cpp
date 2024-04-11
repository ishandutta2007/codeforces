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
    int n;
    cin >> n;
    vi a(n + 2);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    ll res = 0;
    for (int i = 1; i <= n; ++i) {
      int d = max(0, a[i] - max(a[i - 1], a[i + 1]));
      a[i] -= d;
      res += d;
    }
    for (int i = 0; i <= n; ++i) {
      res += abs(a[i] - a[i + 1]);
    }
    cout << res << endl;
  }
  return 0;
}