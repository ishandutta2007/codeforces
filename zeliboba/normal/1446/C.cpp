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

int f(const vi& a, int l, int r, int b) {
  if (l >= r || b == 0) return 0;
  int i = l;
  for (; i < r && (a[i] & b) == 0; ++i) {}
  int fl = f(a, l, i, b / 2); 
  int fr = f(a, i, r, b / 2); 
  return min(fl + max(0, r - i - 1), fr + max(0, i - l - 1));
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n = 200000;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = i;
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  cout << f(a, 0, n, 1 << 30) << endl;
  return 0;
}