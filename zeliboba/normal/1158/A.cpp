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

void fail() {
  cout << -1 << endl;
  exit(0);
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m;
  cin >> n >> m;
  vl a(n), b(m);
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    res += m * a[i];
  }
  for (int i = 0; i < m; ++i) cin >> b[i];
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  if (a[0] > b.back()) fail();
  int it = 0, rem = m;
  for (ll x : b) {
    while ((it < a.size() && a[it] > x) || rem == 0 || (rem == 1 && x != a[it])) {
      ++it;
      rem = m;
    }
    if (it >= a.size()) fail();
    --rem;
    res += x - a[it];
  }
  cout << res << endl;
  return 0;
}