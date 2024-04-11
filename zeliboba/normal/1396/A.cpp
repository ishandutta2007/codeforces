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
  vl a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  if (n == 1) {
    cout << "1 1\n" << -a[0] << '\n';
    cout << "1 1\n" << 0 << '\n';
    cout << "1 1\n" << 0 << '\n';
  } else {
    vl b(n), c(n);
    for (int i = 0; i < n; ++i) {
      b[i] = -n * a[i];
      c[i] = (n - 1) * a[i];
    }
    cout << "1 " << n << '\n';
    for (int i = 0; i < n; ++i) cout << b[i] << ' ';
    cout << '\n';
    cout << "1 " << n-1 << '\n';
    for (int i = 0; i < n - 1; ++i) cout << c[i] << ' ';
    cout << '\n';
    cout << "2 " << n << '\n';
    for (int i = 0; i < n - 2; ++i) cout << 0 << ' ';
    cout << c[n-1] << '\n';
  }
  return 0;
}