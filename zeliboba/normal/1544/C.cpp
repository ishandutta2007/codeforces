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
    vi a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    int l = -1, r = n + 2;
    vi x = a, y = b;
    while (r - l > 1) {
      int m = (l + r) / 2;
      x = a;
      y = b;
      x.resize(n + m);
      y.resize(n + m);
      for (int i = n; i < x.size(); ++i) {
        x[i] = 100;
        y[i] = 0;
      }
      sort(x.begin(), x.end());
      sort(y.begin(), y.end());
      int sx = 0, sy = 0;
      for (int i = x.size() / 4; i < x.size(); ++i) {
        sx += x[i];
        sy += y[i];
      }
      if (sx >= sy) r = m;
      else l = m;
    }
    cout << r << '\n';
  }
  return 0;
}