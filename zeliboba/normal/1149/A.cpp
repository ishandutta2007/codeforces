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
  vi c(3), a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    ++c[a[i]];
  }
  vi b;
  if (c[2] == 0) {
    b = a;
  } else {
    b.push_back(2);
    --c[2];
    if (c[1] > 0) {
      b.push_back(1);
      --c[1];
    }
    for (int t = 2; t >= 1; --t) while (c[t]) {
      b.push_back(t);
      --c[t];
    }
  }
  for (int x : b) cout << x << ' ';
  cout << endl;
  return 0;
}