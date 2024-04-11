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
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n, x;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cin >> x;
    for (int i = 0; i < n; ++i) a[i] -= x;
    vl s(n + 1);
    for (int i = 0; i < n; ++i) s[i + 1] = s[i] + a[i];
    vi q;
    int res = 0, last = -1;
    for (int i = 0; i < n; ++i) {
      if (i > 0) {
        while (!q.empty() && s[q.back()] <= s[i - 1]) q.pop_back();
        q.push_back(i - 1);
      }
      if (!q.empty()) {
        ll val = s[i + 1];
        int l = -1, r = q.size();
        while (r - l > 1) {
          int x = (l + r) / 2;
          if (s[q[x]] > val) l = x;
          else r = x;
        }
        if (l >= 0 && last < q[l]) {
          ++res;
          last = i;
        }
      }
    }
    cout << n - res << '\n';
  }
  return 0;
}