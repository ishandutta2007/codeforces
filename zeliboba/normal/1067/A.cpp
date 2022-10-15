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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
const int mod = 998244353;

int dw(int x) {
  if (x < mod) return x;
  return x - mod;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
  }
  const int M = 200;
  vvi d(2, vi(M)), s(2, vi(M + 1));
  if (a[0] < 0) d[0].assign(M, 1);
  else d[0][a[0]] = 1;
  for (int i = 1; i < n; ++i) {
    vvi nd(2, vi(M));
    for (int j = 0; j < 2; ++j) for (int t = 0; t < M; ++t) {
      s[j][t + 1] = dw(s[j][t] + d[j][t]);
    }
    for (int j = 0; j < M; ++j) if (a[i] < 0 || a[i] == j) {
      nd[0][j] = dw(s[0][j] + s[1][j]);
      nd[1][j] = (mod + (ll)d[0][j] + s[1].back() - s[1][j]) % mod;
    }
    d.swap(nd);
  }
  ll res = 0;
  for (ll x : d[1]) res += x;
  cout << (res % mod + mod) % mod << endl;
  return 0;
}