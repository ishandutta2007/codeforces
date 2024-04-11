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
    ll s = 0, c = 0;
    vi cnt(3);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for (int i = 1; i + 1 < n; ++i) {
      s += a[i];
      c += a[i] % 2;
      ++cnt[min(2LL, a[i])];
    }
//    cerr << s << ' ' << c << endl;
    if ((cnt[2] == 0 && cnt[1] > 0) || (cnt[2] == 1 && cnt[1] == 0 && c > 0)) cout << -1 << '\n';
    else cout << (s + c) / 2 << '\n';
  }
  return 0;
}