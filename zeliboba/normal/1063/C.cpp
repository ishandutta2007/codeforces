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
//typedef long long int;

bool ask(int x, int y) {
  cout << x << ' ' << y << endl;
  fflush(stdout);
  string s;
  cin >> s;
  return s[0] == 'b';
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  const int MAX = 1e9;
  bool left = ask(0, 0);
  ll l = 1, r = 2 * MAX;
  for (int i = 1; i < n; ++i) {
    int m = (l + r) / 2;
    int x = m, y = 0;
    if (m > MAX) {
      x = MAX; y = m - MAX;
    }
    if (ask(x, y) == left) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  cerr << l << ' ' << r << endl;
  assert(l <= r);
  if (l < MAX) {
    cout << l << ' ' << 0 << ' ' << l << ' ' << 1 << endl;
  } else if (l == MAX) {
    cout << MAX << ' ' << 0 << ' ' << MAX - 1 << ' ' << 1 << endl;
  } else {
    cout << MAX - 1 << ' ' << l - MAX << ' ' << MAX << ' ' << l - MAX << endl;
  }
  return 0;
}