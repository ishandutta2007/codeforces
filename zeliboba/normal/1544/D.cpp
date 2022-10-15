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
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n;
    cin >> n;
    vi a(n);
    vvi w(n);
    vi e;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
      w[a[i]].push_back(i);
    }
    for (int i = 0; i < n; ++i) if (w[i].empty()) e.push_back(i);
    vi b = a;
    for (int i = 0; i < n; ++i) while (w[i].size() > 1) {
      if (w[i].back() != e.back()) {
        b[w[i].back()] = e.back();
        e.pop_back();
        w[i].pop_back();
      } else {
        swap(w[i].back(), w[i][w[i].size() - 2]);
      }
    }
    assert(e.empty());
    int k = 0;
    for (int i = 0; i < n; ++i) {
      k += a[i] == b[i];
      assert(b[i] != i);
    }
    cout << k << '\n';
    for (int i = 0; i < n; ++i) cout << b[i] + 1 << ' ';
    cout << '\n';
  }
  return 0;
}