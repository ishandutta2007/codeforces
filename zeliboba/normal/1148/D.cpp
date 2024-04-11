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
  int n;
  cin >> n;
  vector<array<int, 3>> v1, v2;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    if (a < b) v1.push_back({a, b, i + 1});
    else v2.push_back({b, a, i + 1});
  }
  vi res;
  if (v1.size() > v2.size()) {
    sort(v1.rbegin(), v1.rend());
    for (auto x : v1) res.push_back(x[2]);
  } else {
    sort(v2.begin(), v2.end());
    for (auto x : v2) res.push_back(x[2]);
  }
  cout << res.size() << endl;
  for (int x : res) cout << x << ' ';
  cout << endl;
  return 0;
}