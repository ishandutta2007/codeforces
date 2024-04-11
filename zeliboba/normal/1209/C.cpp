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
    string s;
    cin >> n >> s;
    vi v(n);
    for (int i = 0; i < n; ++i) v[i] = s[i] - '0';
    vi x(n);
    bool ok = 0;
    for (int d = 0; d < 10; ++d) {
      x.assign(n, 1);
      for (int j = 0; j < n; ++j) if (v[j] > d) {
        x[j] = 2;
      }
      for (int j = n - 1; j >= 0; --j) if (v[j] < d) {
        for (int i = j - 1; i >= 0; --i) if (v[i] == d) {
          x[i] = 2;
        }
        break;
      }
      int last = -1;
      ok = 1;
      for (int xx = 1; xx <= 2; ++xx) for (int i = 0; i < n; ++i) if (x[i] == xx) {
        if (v[i] < last) {
          ok = 0; break;
        }
        last = v[i];
      }
      if (ok) {
        for (int i = 0; i < n; ++i) s[i] = x[i] + '0';
        cout << s << '\n';
        break;
      }
    }
    if (!ok) cout << "-\n";
  }
  return 0;
}