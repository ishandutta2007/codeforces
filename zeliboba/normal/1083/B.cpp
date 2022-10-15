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
  ll n, k;
  string s, t;
  cin >> n >> k >> s >> t;
  if (k == 1) {
    cout << n << endl;
    return 0;
  }
  int l = n;
  for (int i = 0; i < n; ++i) {
    if (s[i] != t[i]) break;
    --l;
  }
  vl ss(n + 1);
  for (int i = n - l + 1; i < n; ++i) {
    if (s[i] == 'a') {
      for (int j = 0; j < min(35LL, n - i); ++j) {
        ss[n - i - j] += 1LL << max(0, j - 1);
      }
    }
  }
  for (int i = n - l + 1; i < n; ++i) {
    if (t[i] == 'b') {
      for (int j = 0; j < min(35LL, n - i); ++j) {
        ss[n - i - j] += 1LL << max(0, j - 1);
      }
    }
  }
  ll res = n - l + 2 * l;
  k -= 2;
  for (int i = n; i >= 1 && k > 0; --i) {
    res += i * min(k, ss[i]);
    k -= ss[i];
  }
  cout << res << endl;
  return 0;
}