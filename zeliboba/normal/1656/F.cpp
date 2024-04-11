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
    ll n;
    cin >> n;
    vl a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    vl s(n + 1);
    for (int i = 0; i < n; ++i) s[i + 1] = s[i] + a[i];
    if (s[n] + a[0] * (n - 2) > 0 || s[n] + a.back() * (n - 2) < 0) {
      cout << "INF\n";
      continue;
    }
    ll res = -2e18;
    for (int i = 0; i < n; ++i) {
      ll t = -a[i];
      ll cur = 0;
      if (i) {
        cur = (a.back() + t) * s[i] + a.back() * t * i;
        cur += (a[0] + t) * (s[n] - s[i]) + a[0] * t * (n - i);
        cur -= a[0] * a.back() + (a[0] + a.back()) * t;
      } else {
        cur = a[0] * t * (n - 1);
      }
//    cerr << test << ' ' << t << ' ' << cur << endl;
      res = max(res, cur);
    }
    /*ll res = a[0] * a.back();
    for (int i = 1; i < n - 1; ++i) {
      if (a[i] > 0) res += a[i] * a[0];
      else res += a[i] * a.back();
    }*/
    cout << res << '\n';
  }
  return 0;
}