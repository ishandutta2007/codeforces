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
  ll n, r1, r2, r3, D;
  cin >> n >> r1 >> r2 >> r3 >> D;
  vl a(n), c1(n), c2(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    c1[i] = a[i] * r1 + r3;
    c2[i] = min(a[i] * r1 + 2 * r1, r2 + r1);
  }
  vector<array<ll, 2>> d(n + 1);
  d[0][1] = 1e18;
  for (int i = 0; i < n; ++i) {
    d[i + 1].fill(1e18);
    ll add = (i == n-1 ? 0 : D);
    for (int pr = 0; pr < 2; ++pr) {
      d[i + 1][0] = min(d[i + 1][0], d[i][pr] + c1[i] + add);
    }
    d[i + 1][1] = min(d[i + 1][1], d[i][0] + c2[i] + 2 * D + add);
    d[i + 1][0] = min(d[i + 1][0], d[i][1] + c2[i] + add);
//    cerr << c1[i] << ' ' << c2[i] << ' ' << d[i+1][0] << ' ' << d[i + 1][1] << endl;
  }
  ll res = min(d[n][0], d[n][1]);
//  cerr << res << endl;
  ll sum = min(c1[n - 1], c2[n - 1] + 2 * D);
  for (int i = n - 2; i >= 0; --i) {
    sum += min(c1[i], c2[i]) + 2 * D;
    res = min(res, sum + min(d[i][0], d[i][1]));
//    cerr << res << endl;
  }
  cout << res << endl;
  return 0;
}