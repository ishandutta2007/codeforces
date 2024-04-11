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
  vii a(n);
  vl b(n);
  ll s = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    s += a[i].first;
    a[i].second = i + 1;
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    s -= b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  vl pos, d;
  vector<array<ll, 3>> res;
  bool fail = s != 0;
  for (int i = 0; i < n && !fail; ++i) {
    ll curd = b[i] - a[i].first;
    while (curd < 0 && !d.empty()) {
      ll mi = min(abs(curd), d.back());
      res.push_back({pos.back(), a[i].second, mi});
      d.back() -= mi;
      curd += mi;
      if (d.back() == 0) {
        d.pop_back();
        pos.pop_back();
      }
    }
    if (curd < 0) fail = 1;
    if (curd == 0) continue;
    if (curd > 0) {
      pos.push_back(a[i].second);
      d.push_back(curd);
    }
  }
  if (fail) {
    cout << "NO\n";
  } else {
    cout << "YES\n" << res.size() << endl;
    for (auto x : res) {
      cout << x[0] << ' ' << x[1] << ' ' << x[2] << '\n';
    }
  }
  return 0;
}