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
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, k;
  cin >> n >> k;
  vvi v(n, vi(k));
  vi c(k);
  vi was(1 << k);
  for (int i = 0; i < n; ++i) {
    int mask = 0;
    for (int j = 0; j < k; ++j) {
      cin >> v[i][j];
      c[j] += v[i][j];
      mask |= v[i][j] << j;
    }
    was[mask] = 1;
  }
  for (int i = 0; i < was.size(); ++i) if (was[i]) for (int j = 0; j < was.size(); ++j) if (was[j]) {
    if ((i & j) == 0) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
/*  for (int i = 0; i < k; ++i) if (c[i] == n) {
    cout << "NO\n";
    return 0;
  }
  c.assign(k, 0);
  vvi a;
  for (int i = 0; i < v.size(); ++i) {
    int s = 0;
    for (int j = 0; j < k; ++j) {
      s += v[i][j];
    }
    assert(s >= 2);
    if (s == 2) a.push_back(v[i]);
  }*/
  return 0;
}