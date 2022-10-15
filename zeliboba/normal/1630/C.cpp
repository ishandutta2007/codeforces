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
  int T = 1;
  for (int test = 1; test <= T; ++test) {
    int n;
    cin >> n;
    vi a(n), r(n + 1);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      r[a[i]] = i;
    }
    vi bad(n), add(n + 1);
    int res = 0;
    for (int i = 0; i < n; ++i) {
      if (r[a[i]] > i + 1) {
        int ma = r[a[i]];
        res += ma - i - 1;
        int l = i;
        while (1) {
          int nxma = ma;
          for (int j = l + 1; j < ma; ++j) nxma = max(nxma, r[a[j]]);
          if (nxma == ma) {
            i = ma;
            break;
          }
          res += nxma - ma - 1;
          l = ma;
          ma = nxma;
        }
      }
    }
    cout << res << endl;
  }
  return 0;
}