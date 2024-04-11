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

ll c2(ll x) {
  return x * (x - 1) / 2;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  map<int, int> w;
  map<pii, int> w2;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    w[a]++;
    if (b != a) {
      w[b]++;
      w2[pii(a, b)]++;
    }
  }
  ll res = 0;
  for (auto p : w) {
    res += c2(p.second);
  }
  for (auto p : w2) {
    res -= c2(p.second);
  }
  cout << res << endl;
  return 0;
}