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
  for (int test = 1; test <= T; ++test) {
    int n, k;
    cin >> n >> k;
    vi x(k), y(k);
    vi v(2 * n);
    for (int i = 0; i < k; ++i) {
      cin >> x[i] >> y[i];
      --x[i]; --y[i];
      v[x[i]] = -1;
      v[y[i]] = 1;
    }
    vi w;
    for (int i = 0; i < v.size(); ++i) if (!v[i]) w.push_back(i);
    for (int j = 0; j < n - k; ++j) {
      x.push_back(w[j]);
      y.push_back(w[j + n - k]);
    }
    int res = 0;
    for (int i = 0; i < x.size(); ++i) {
      if (x[i] > y[i]) swap(x[i], y[i]);
    }
    for (int i = 0; i < x.size(); ++i) for (int j = i + 1; j < x.size(); ++j) {
      if ((x[j] - x[i]) * (y[j] - y[i]) > 0 && y[i] > x[j] && y[j] > x[i]) ++res;
    }
    cout << res << '\n';
  }
  return 0;
}