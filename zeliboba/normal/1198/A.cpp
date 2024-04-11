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
  m *= 8;
  m /= n;
  m = min(m, 30);
  vi a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  vii v(1, pii(a[0], 1));
  for (int i = 1; i < n; ++i) {
    if (a[i] == v.back().first) ++v.back().second;
    else v.emplace_back(a[i], 1);
  }
  int k = min((int)v.size(), 1 << m);
  vi s(v.size() + 1);
  for (int i = 0; i < (int)v.size(); ++i) {
    s[i + 1] = s[i] + v[i].second;
  }
  int res = n;
  for (int i = 0; i + k <= (int)v.size(); ++i) {
    res = min(res, s[i] + (s.back() - s[i + k]));
  }
  cout << res << endl;
  return 0;
}