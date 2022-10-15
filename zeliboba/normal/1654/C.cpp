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
  int T = 1;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    int n;
    cin >> n;
    multiset<ll> w, d;
    ll s = 0;
    for (int i = 0; i < n; ++i) {
      ll x;
      cin >> x;
      s += x;
      w.insert(x);
    }
    d.insert(s);
    bool ok = 1;
    while (!w.empty()) {
      if (d.empty() || d.size() > w.size()) {
        ok = 0; break;
      }
      auto itw = w.end(); --itw;
      ll maxw = *itw;
      auto it = d.end(); --it;
      ll x = *it;
      if (maxw > x) {
        ok = 0; break;
      }
      d.erase(it);
      if (w.find(x) != w.end()) {
        w.erase(w.find(x));
        continue;
      } else {
        assert(x > 1);
        d.insert(x / 2);
        d.insert(x - x / 2);
      }
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}