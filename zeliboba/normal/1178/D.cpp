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

vi erat(1e6, 1);

vii f(int n) {
  vii e;
  for (int i = 0; i < n; ++i) e.emplace_back(i, (i + 1) % n);
  for (int i = 0; i < n / 2 && !erat[e.size()]; ++i) {
    e.emplace_back(i, i + n / 2);  
  }
//  cerr << n << ' ' << e.size() << endl;
  assert(erat[e.size()]);
  return e;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  erat[0] = erat[1] = 0;
  for (int i = 2; i * i < erat.size(); ++i) if (erat[i]) {
    for (int j = i * i; j < erat.size(); j += i) erat[j] = 0;
  }
  for (int n = 3; n <= 1000; ++n) {
    f(n);
  }
  int n;
  cin >> n;
  vii e = f(n);
  cout << e.size() << endl;
  for (pii p : e) {
    cout << p.first + 1 << ' ' << p.second + 1 << '\n';
  }
  return 0;
}