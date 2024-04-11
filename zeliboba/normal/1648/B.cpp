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
    int n, c;
    cin >> n >> c;
    vi a(c + 1);
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      a[x] = 1;
    }
    vi s(a.size() + 1);
    for (int i = 0; i < a.size(); ++i) {
      s[i + 1] = s[i] + a[i];
    }
    bool ok = 1;
    for (int i = 1; i <= c; ++i) if (!a[i]) {
      for (int x = 1; x <= c / i; ++x) if (a[x]) {
        int l = x * i, r = min(c + 1, (i + 1) * x);
        if (s[l] != s[r]) {
          ok = 0; break;
        }
      }
    }
    if (ok) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}