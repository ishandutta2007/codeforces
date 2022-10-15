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

ll f(const array<ll, 3>& a, const array<ll, 3>& b) {
  return a[1] + b[1] + min(a[0], b[0]);
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<array<ll, 3>> v(n);
  ll s1 = 0;
  for (int i = 0; i < n; ++i) {
    cin >> v[i][0] >> v[i][1];
    v[i][2] = i;
    v[i][0] -= v[i][1];
    s1 += v[i][1];
  }
  vl res(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    ll val = f(v[a], v[b]);
    res[a] -= val;
    res[b] -= val;
  }
  sort(v.begin(), v.end());
  ll s0 = 0;
  for (int i = 0; i < n; ++i) {
    res[v[i][2]] += (n - 1) * v[i][1] + (s1 - v[i][1]) + s0 + (n - i - 1) * v[i][0];
    s0 += v[i][0];
  }
  for (int i = 0; i < n; ++i) {
    cout << res[i] << ' ';
  }
  cout << endl;
  return 0;
}