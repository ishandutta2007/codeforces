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
#include <queue>
#include <array>
#include <bitset>
#include <chrono>
#include <random>
using namespace std;
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
//typedef long long int;

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  ll n, t;
  cin >> n >> t;
  vl a(n), x(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
    --x[i];
    if (x[i] < i || (i && x[i] < x[i-1]) || (i && x[i-1] >= i && x[i] == i && (i + 1 < n && a[i+1] == a[i] + 1)) || (i && x[i-1] < x[i] && x[i-1] != i-1)) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  vl b(n);
  for (int i = 0; i < n; ++i) {
    if (x[i] == i) {
      b[i] = a[i] + t;
      if (i && x[i-1] >= i) ++b[i];
    } else {
      b[i] = a[i + 1] + t;
    }
    cout << b[i] << ' ';
  }
  cout << endl;
  return 0;
}