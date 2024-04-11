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
const int mod = 998244353;

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vl x(n + 1, -1), y(n + 1, -1), s(n + 1), pos(n + 1), len(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> x[i] >> y[i] >> s[i];
    len[i] = x[i] - x[i - 1];
  }
  for (int i = 1; i <= n; ++i) pos[i] = lower_bound(x.begin(), x.end(), y[i]) - x.begin() - 1;
  vl d(n + 1);
  for (int i = 1; i <= n; ++i) {
    d[i] = (d[i - 1] + (len[i] - 1) - (d[pos[i]] + y[i] - x[pos[i]] - 1) + d[i - 1] + len[i]) % mod;
  }
  ll res = 0;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == 0) res = (res + len[i]) % mod;
    else {
      res = (res + (len[i] - 1) - (d[pos[i]] + y[i] - x[pos[i]] - 1) + d[i - 1] + len[i]) % mod;
    }
  }
  cout << (res % mod + mod) % mod << endl;
  return 0;
}