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
typedef long double ld;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

void imp() {
  cout << "Impossible\n";
  exit(0);
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vi a(n);
  vvi c(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    c[n - a[i]].push_back(i);
  }
  vi b(n);
  int col = 0;
  for (int i = 0; i < n; ++i) {
    int s = n - a[i];
    if (c[s].size() % s) {
      imp();
    }
    col += c[s].size() / s;
  }
//  if (col > n) imp();
  cout << "Possible\n";
  int it = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < c[i].size(); ++j) {
      b[c[i][j]] = it + j / i;
    }
    it += c[i].size() / i;
  }
  for (int i = 0; i < n; ++i) {
    cout << b[i] + 1 << ' ';
  }
  return 0;
}