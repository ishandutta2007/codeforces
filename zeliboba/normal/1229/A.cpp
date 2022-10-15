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
typedef pair<ll, ll> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vii v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first;
  }
  ll s = 0;
  for (int i = 0; i < n; ++i) {
    cin >> v[i].second;
    s += v[i].second;
  }
  sort(v.rbegin(), v.rend());
  vi in(n, 1);
  for (int i = 0; i < n; ++i) {
    bool best = 1;
    for (int j = 0; j < n; ++j) if (in[j] && j != i && (v[i].first & v[j].first) == v[i].first) {
      best = 0; break;
    }
    if (!best) {
      continue;
    }
    in[i] = 0;
    s -= v[i].second;
  }
  cout << s << endl;
  return 0;
}