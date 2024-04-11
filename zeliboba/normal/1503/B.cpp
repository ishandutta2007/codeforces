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
  vvi v(n, vi(n, 0));
  vector<vii> rem(3);
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    rem[(i + j) % 2 + 1].emplace_back(i + 1, j + 1);
  }
  for (int t = 0; t < n * n; ++t) {
    int c;
    cin >> c;
    if (c != 1 && !rem[1].empty()) {
      cout << 1 << ' ' << rem[1].back().first << ' ' << rem[1].back().second << endl;
      rem[1].pop_back();
    } else if (c != 2 && !rem[2].empty()) {
      cout << 2 << ' ' << rem[2].back().first << ' ' << rem[2].back().second << endl;
      rem[2].pop_back();
    } else {
      for (int t = 1; t <= 2; ++t) if (!rem[t].empty()) {
        int b = c == t ? 3 : t;
        cout << b << ' ' << rem[t].back().first << ' ' << rem[t].back().second << endl;
        rem[t].pop_back();
        break;
      }
    }
  }
  return 0;
}