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
    int n;
    cin >> n;
    vl w(n);
    for (int i = 0; i < n; ++i) cin >> w[i];
    vvi g(n);
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a; --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    ll s = 0;
    vl ts;
    for (int i = 0; i < n; ++i) {
      s += w[i];
      for (int j = 1; j < g[i].size(); ++j) {
        s += w[i];
        ts.push_back(w[i]);
      }
    }
    sort(ts.begin(), ts.end());
    assert(ts.size() == n - 2);
    vl res(n - 1, s);
    for (int i = 0; i < ts.size(); ++i) {
      s -= ts[i];
      res[n - 2 - i - 1] = s;
    }
    for (int i = 0; i < res.size(); ++i) cout << res[i] << ' ';
    cout << '\n';
  }
  return 0;
}