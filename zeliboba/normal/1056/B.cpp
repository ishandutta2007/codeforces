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
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef long double ld;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

ll f(int n, int r, int m) {
  if (r == 0) {
    return n / m;
  }
  return (n - r + m) / m;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  ll n, m;
  cin >> n >> m;
  ll res = 0;
  for (int i = 0; i < m; ++i) for (int j = 0; j < m; ++j) if ((i * i + j * j) % m == 0) {
    res += f(n, i, m) * f(n, j, m);
  }
  cout << res << endl;
  return 0;
}