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
  vi a(n), pr(n, -1), nx(n, n), mi(n, n);
  map<int, vi> w;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (!w[a[i]].empty()) {
      pr[i] = w[a[i]].back();
      mi[i] = w[a[i]][0];
      nx[w[a[i]].back()] = i;
    }
    w[a[i]].push_back(i);
  }
  int res = n - 1;
  if (w.size() == n) res = 0;
  for (int l = 0; l < n; ++l) {
    for (int r = n - 1; r >= l; --r) {
      res = min(res, r - l + 1);
      if (nx[r] < n || mi[r] < l) break;
    }
    if (pr[l] != -1) break;
  }
  cout << res << endl;
  return 0;
}