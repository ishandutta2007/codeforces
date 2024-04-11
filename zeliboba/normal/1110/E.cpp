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
  vi a(n), b(n), da(n-1), db(n-1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (i) da[i-1] = a[i] - a[i-1];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    if (i) db[i-1] = b[i] - b[i-1];
  }
  sort(da.begin(), da.end());
  sort(db.begin(), db.end());
  if (a[0] != b[0] || a[n-1] != b[n-1] || da != db) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
  }
  return 0;
}