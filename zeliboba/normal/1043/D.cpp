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
  int n, m;
  cin >> n >> m;
  vi nx(n + 1, -1), in(n + 1, 0);
  for (int t = 0; t < m; ++t) {
    vi a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for (int i = 0; i + 1 < n; ++i) {
      if (nx[a[i]] == a[i+1] || nx[a[i]] == -1) {
        nx[a[i]] = a[i+1];
      } else {
        nx[a[i]] = 0;
      }
    }
    nx[a[n-1]] = 0;
  }
  ll res = 0;
  vi was(n + 1);
  for (int i = 1; i <= n; ++i) if (nx[i] > 0) {
//    cerr << i << ' ' << nx[i] << endl;
    in[nx[i]] = i;
  }
  for (int i = 1; i <= n; ++i) if (in[i] == 0) {
    int len = 1;
    int cur = i;
    while (nx[cur] > 0) {
      ++len;
      cur = nx[cur];
    }
    res += len * (ll)(len + 1) / 2;
  }
  cout << res << endl;
  return 0;
}