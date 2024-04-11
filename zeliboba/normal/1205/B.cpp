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
  int n;
  cin >> n;
  vl a;
  for (int i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    if (x) a.push_back(x);
  }
  n = a.size();
  if (n >= 200) {
    cout << 3 << endl;
    return 0;
  }
  vvi g(n);
  for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (a[i] & a[j]) {
    g[i].push_back(j);
    g[j].push_back(i);
  }
  int mi = 1e9;
  for (int s = 0; s < n; ++s) {
    vi q(1, s), d(n, 1e9);
    d[s] = 0;
    int it = 0;
    while (it < q.size()) {
      int v = q[it];
      ++it;
      for (int nv : g[v]) if (d[nv] > d[v] + 1) {
        d[nv] = d[v] + 1;
        q.push_back(nv);
      }
    }
    for (int i = 0; i < n; ++i) if (d[i] >= 1 && d[i] <= n) {
      int c = 0;
      for (int j = 0; j < n; ++j) if (i != j && (a[i] & a[j])) {
        if (d[i] == d[j]) {
          mi = min(mi, d[i] + d[j] + 1);
        }
        if (d[j] == d[i] - 1) {
          ++c;
        }
      }
      if (c >= 2) {
        mi = min(mi, 2 * d[i]);
      }
    }
  }
  if (mi > n) mi = -1;
  cout << mi << endl;
  return 0;
}