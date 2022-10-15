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
    string s;
    cin >> s;
    int n = s.size();
    vi d(4, 1e9);
    d[0] = 0;
    for (int i = 0; i < n; ++i) {
      vi nd(4, 1e9);
      for (int x = 0; x < 2; ++x) for (int j = 0; j < 4; ++j) {
        int nx = j / 2 + 2 * x;
        if (!x && j % 2 == 0 && i >= 2 && s[i] == s[i - 2]) continue;
        if (!x && j / 2 == 0 && i >= 1 && s[i] == s[i - 1]) continue;
        nd[nx] = min(nd[nx], d[j] + x);
      }
      d.swap(nd);
    }
    int res = 1e9;
    for (int x : d) res = min(res, x);
    cout << res << '\n';
  }
  return 0;
}