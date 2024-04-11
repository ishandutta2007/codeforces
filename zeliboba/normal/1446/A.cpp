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
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    ll n, s;
    cin >> n >> s;
    ll s0 = s;
    vii w(n);
    for (int i = 0; i < n; ++i) {
      cin >> w[i].first;
      w[i].second = i + 1;
    }
    sort(w.rbegin(), w.rend());
    vi v;
    for (auto p : w) {
      if (p.first <= s) {
        s -= p.first;
        v.push_back(p.second);
      }
    }
    if (2 * s > s0) {
      cout << -1 << '\n';
      continue;
    }
    cout << v.size() << '\n';
    for (auto x : v) cout << x << ' ';
    cout << '\n';
  }
  return 0;
}