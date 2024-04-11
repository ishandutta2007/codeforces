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

int ask(vi a, vi b) {
  cout << a.size() << ' ' << b.size();
  for (int x : a) cout << ' ' << x + 1;
  for (int x : b) cout << ' ' << x + 1;
  cout << endl;
  int d;
  cin >> d;
  return d;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n;
    cin >> n;
    int res = 0;
    for (int B = 1; B <= (1 << 7); B *= 2) {
      vi a, b;
      for (int i = 0; i < n; ++i) {
        if (i & B) a.push_back(i);
        else b.push_back(i);
      }
      if (a.empty() || b.empty()) continue;
      res = max(res, ask(a, b));
    }
    cout << "-1 " << res << endl;
  }
  return 0;
}