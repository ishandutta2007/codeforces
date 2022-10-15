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
  ll n, m, t1, t2, k;
  cin >> n >> m >> t1 >> t2 >> k;
  vl a(n), b(m);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < m; ++i) cin >> b[i];
  const ll MAX = 1e18;
  ll res = 0;
  if (n <= k || m <= k) {
    res = MAX;
  }
  for (int i = 0; i <= k; ++i) {
    ll t = a[i] + t1;
    int it = lower_bound(b.begin(), b.end(), t) - b.begin();
    if (it + k - i >= (ll)b.size()) res = MAX;
    else res = max(res, b[it + k - i] + t2);
  }
  if (res == MAX) res = -1;
  cout << res << endl;
  return 0;
}