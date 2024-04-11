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

ll f(vl x) {
  sort(x.begin(), x.end());
  ll res = 0, s = 0;
  for (int i = 0; i < x.size(); ++i) {
    res += i * x[i] - s;
    s += x[i];
  }
  return res;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T = 1;
//  cin >> T;
  for (int test = 1; test <= T; ++test) {
    int n, m;
    cin >> n >> m;
    map<int, vii> w;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
      int c;
      cin >> c;
      w[c].push_back(pii(i, j));
    }
    ll res = 0;
    for (auto v : w) {
      auto a = v.second;
      vl x, y;
      for (auto p : a) {
        x.push_back(p.first);
        y.push_back(p.second);
      }
      res += f(x) + f(y);
    }
    cout << res << endl;
  }
  return 0;
}