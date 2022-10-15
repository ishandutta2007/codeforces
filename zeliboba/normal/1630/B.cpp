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
    int n, k;
    cin >> n >> k;
    vi a(n), c(n + 1);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      ++c[a[i]];
    }
    int in = (n - k + 1) / 2 + k;
//    cerr << in << endl;
    int r = 0, cnt = 0, x = 1, y = n + 1;
    for (int l = 1; l <= n; ++l) {
      cnt -= c[l - 1];
      while (r <= n && cnt < in) {
        cnt += c[r];
        ++r;
      }
      if (r > n && cnt < in) break;
      if (y - x > r - l) {
        x = l;
        y = r;
      }
    }
    --y;
    cout << x << ' ' << y << '\n';
    int i = 0, bal = 0;
    for (int j = 0; j < n; ++j) {
      if (a[j] >= x && a[j] <= y) ++bal;
      else --bal;
      if (bal > 0 && (k > 1 || j == n - 1)) {
        bal = 0;
        cout << i + 1 << ' ' << j + 1 << '\n';
        --k;
        i = j + 1;
      }
    }
  }
  return 0;
}