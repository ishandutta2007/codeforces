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
  int n, m;
  cin >> n >> m;
  vi a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  int l = -1, r = m;
  while (r - l > 1) {
    int x = (l + r) / 2;
    int mi = 0;
    bool fail = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] < mi) {
        if (mi - a[i] > x) fail = true;
      } else {
        if (mi + m - a[i] > x) {
          mi = a[i];
        }
      }
    }
    if (fail) l = x;
    else r = x;
  }
  cout << r << endl;
  return 0;
}