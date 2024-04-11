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

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, h;
  cin >> n >> h;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int ma = 0;
  for (int k = 1; k <= n; ++k) {
    sort(a.begin(), a.begin() + k);
    ll s = 0;
    for (int i = k - 1; i >= 0; i -= 2) {
      s += a[i];
    }
    if (s <= h) ma = max(ma, k);
  }
  cout << ma << endl;
  return 0;
}