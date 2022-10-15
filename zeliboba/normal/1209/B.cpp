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
  string s;
  cin >> n >> s;
  vi a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }
  const int N = 1e5;
  vvi v(n, vi(N));
  for (int i = 0; i < n; ++i) {
    v[i].assign(v[i].size(), s[i] - '0');
    for (int j = b[i]; j < v[i].size(); j += a[i]) {
      v[i][j] = v[i][j - 1] ^ 1;
      for (int j1 = j + 1; j1 < min(j + a[i], (int)v[i].size()); ++j1) {
        v[i][j1] = v[i][j];
      }
    }
  }
  int ma = 0;
  for (int j = 0; j < N; ++j) {
    int t = 0;
    for (int i = 0; i < n; ++i) t += v[i][j];
    ma = max(ma, t);
  }
  cout << ma << endl;
  return 0;
}