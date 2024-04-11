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

ll p2(ll x) {
  return x * x;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T = 1;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    int n;
    cin >> n;
    vl a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    vl s(n + 1);
    ll add = 0; 
    for (int i = 0; i < n; ++i) {
      s[i + 1] = s[i] + a[i] + b[i];
      add += (n - 1) * (p2(a[i]) + p2(b[i]));
    }
    vl d(100 * n + 1, 1e18);
    d[0] = 0;
    for (int i = 0; i < n; ++i) {
      vl nd(d.size(), 1e18);
      for (ll x = 0; x < d.size() && x <= s[i]; ++x) {
        ll y = s[i] - x;
        nd[x + a[i]] = min(nd[x + a[i]], d[x] + a[i] * x + b[i] * y);
        nd[x + b[i]] = min(nd[x + b[i]], d[x] + b[i] * x + a[i] * y);
      }
      d.swap(nd);
    }
    ll mi = d[0];
    for (int i = 0; i < d.size(); ++i) mi = min(mi, d[i]);
    cout << add + 2 * mi << '\n';
  }
  return 0;
}