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
const ll inv2 = (mod + 1) / 2;

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T = 1;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    ll n, m, k;
    cin >> n >> m >> k;
    vl d(2), nd;
    d[1] = k % mod;
    for (int t = 2; t <= n; ++t) {
      nd.assign(t + 1, 0);
      nd[t] = t * k % mod;
      for (int i = 1; i < t; ++i) nd[i] = (d[i - 1] + d[i]) * inv2 % mod;
      d.swap(nd);
    }
    cout << d[m] % mod << '\n';
  }
  return 0;
}