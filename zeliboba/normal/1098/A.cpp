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
typedef long double ld;
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
  int n;
  cin >> n;
  vvi g(n);
  vi p(n), h(n);
  vl s(n), a(n);
  h[0] = 1;
  for (int i = 1; i < n; ++i) {
    cin >> p[i];
    --p[i];
    g[p[i]].push_back(i);
    h[i] = h[p[i]] + 1;
  }
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    if (h[i] % 2 == 0) {
      a[i] = g[i].empty() ? 0 : 1e18;
      for (int j : g[i]) {
        a[i] = min(a[i], s[j] - s[p[i]]);
      }
      s[i] = s[p[i]] + a[i];
    } else {
      a[i] = s[i];
      if (i) {
        a[i] -= s[p[i]];
      }
    }
//    cerr << i << ' ' << a[i] << ' ' << s[i] << ' ' << h[i] << endl; 
    if (a[i] < 0) fail();
    sum += a[i];
  }
  cout << sum << endl;
  return 0;
}