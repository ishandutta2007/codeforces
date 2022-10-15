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
  int n;
  cin >> n;
  vl a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  ll t = 0, r = 0;
  for (int i = 0; i < n; ++i) {
    ll add = 0;
    if (a[i] % 2 && a[i] >= 3) {
      add += 1;
      a[i] -= 3;
    }
    ll c1 = min(r, a[i] / 2);
    add += c1;
    r -= c1;
    a[i] -= 2 * c1;
    ll c2 = min(3 * t, a[i] / 2);
    add += c2;
    a[i] -= 2 * c2;
    r += (3 * t - c2) % 3;
    t = (3 * t - c2) / 3;
    add += a[i] / 3;
    r += a[i] % 3;
    t += add;
  }
  cout << t << endl;
  return 0;
}