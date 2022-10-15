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
const int mod = 1e9 + 7;

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    ll n;
    cin >> n;
    vl a(n);
    vl c(60);
    vl pw(c.size(), 1);
    for (int i = 1; i < pw.size(); ++i) pw[i] = pw[i - 1] * 2 % mod;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      for (int j = 0; j < c.size(); ++j) if (a[i] & (1LL << j)) ++c[j];
    }
    ll res = 0;
    for (int i = 0; i < n; ++i) {
      ll s1 = 0, s2 = 0;
      for (int j = 0; j < c.size(); ++j) {
        if (a[i] & (1LL << j)) {
          s1 = (s1 + c[j] * pw[j]) % mod;
          s2 = (s2 + n * pw[j]) % mod;
        } else {
          s2 = (s2 + c[j] * pw[j]) % mod;
        }
      }
//      cerr << s1 << ' ' << s2 << endl;
      res = (res + s1 * s2) % mod;
    }
    cout << res << '\n';
  }
  return 0;
}