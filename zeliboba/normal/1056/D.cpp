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
  vvi g(n);
  for (int i = 0; i < n - 1; ++i) {
    int p;
    cin >> p;
    g[p-1].push_back(i + 1);
  }
  vi d(n);
  for (int i = n - 1; i >= 0; --i) {
    if (g[i].size() == 0) d[i] = 1;
    else {
      for (int j : g[i]) d[i] += d[j];
    }
  }
  sort(d.begin(), d.end());
  for (int i = 0; i < n; ++i) {
    cout << d[i] << ' ';
  }
  cout << endl;
  return 0;
}