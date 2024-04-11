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
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    int n;
    cin >> n;
    vl a(n);
    vi c(2);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (a[i] < 2) c[a[i]] = 1;
    }
    sort(a.begin(), a.end());
    bool neig = 0;
    for (int i = 0; i + 1 < n; ++i) if (a[i] + 1 == a[i + 1]) neig = 1;
    if (c[1] == 0 || !neig) cout << "YES\n";
    else cout << "NO\n";
  }
  return 0;
}