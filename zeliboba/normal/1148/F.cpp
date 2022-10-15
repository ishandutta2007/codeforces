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

void solve(vl a, const vl& m) {
  int n = a.size();
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += a[i];
  }
  if (sum < 0) {
    for (int i = 0; i < n; ++i) a[i] *= -1;
  }
  ll s = 0;
  vi zn(n, 1);
  for (int b = 0; b < 62; ++b) {
    ll B = (1LL << b);
    ll filter = (1LL << 62) - 2 * B;
    ll sum = 0;
    for (int i = 0; i < n; ++i) if (!(m[i] & filter)) {
      ll mul = zn[i];
      if (m[i] & B) mul *= -1;
      sum += mul * a[i];
    }
    if (sum < 0) {
      s += B;
      for (int i = 0; i < n; ++i) if (m[i] & B) {
        zn[i] *= -1;
      }
    }
  }
  cout << s << endl;
  sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += zn[i] * a[i];
  }
  assert(s >= 1 && sum < 0);
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  if (0)for (int n = 1; n <= 100; ++n) for (int t = 0; t < 10000; ++t) {
    vl a(n), m(n);
    const int N = 1000000000;
    ll s = 0;
    for (int i = 0; i < n; ++i) {
      a[i] = rand() % (2 * N) - N;
      m[i] = rand() % ((1LL << 9) - 1) + 1;
      s += a[i];
    }
    if (s == 0) continue;
    solve(a, m);
  }
  int n;
  cin >> n;
  vl a(n), m(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> m[i];
  }
  solve(a, m);
  return 0;
}