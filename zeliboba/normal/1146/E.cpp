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
  int n, m;
  cin >> n >> m;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vi b = a;
  vi s(m), x(m);
  for (int i = 0; i < m; ++i) {
    string t;
    cin >> t >> x[i];
    if (t == ">") s[i] = 1;
    else s[i] = -1;
  }
  const int N = 1e5 + 5;
  vi mul(2 * N + 1, 1);
  int mi = N - 1;
  for (int i = m - 1; i >= 0; --i) {
    int l = -mi + 1, r = mi - 1;
    if (s[i] == -1) { // <
      r = min(r, x[i] - 1);
    } else { // >
      l = max(l, x[i] + 1);    
    }
//    cerr << l << ' ' << r << ' ' << mi << endl;
    mi = min(mi, abs(x[i]) + (s[i] * x[i] > 0));
    if (l <= r) {
      mul[N + l] *= -1;
      mul[N + r + 1] *= -1;
    }
  }
  vi res(2 * N + 1, 1);
  for (int i = 1; i < (int)res.size(); ++i) {
    res[i] = res[i - 1] * mul[i];
  }
  for (int i = 0; i < (int)b.size(); ++i) {
    b[i] *= res[N + b[i]];
  }
  for (int i = 0; i < n; ++i) cout << b[i] << ' ';
  cout << endl;
  return 0;
}