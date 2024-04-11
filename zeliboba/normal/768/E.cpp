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

map<ll, int> w[61];

int f(int x, ll mask) {
  mask &= (1LL << (x + 1)) - 1;
  if (!x) return 0;
  if (w[x].count(mask)) return w[x][mask];
  array<char, 61> g;
  g.fill(0);
  for (int i = 1; i <= x; ++i) if (!(mask & (1LL << i))) {
    g[f(x - i, mask | (1LL << i))] = 1;
  }
  int p = 0;
  for (; p <= x; ++p) {
    if (!g[p]) break;
  }
  w[x][mask] = p;
  return p;
}

int main() {
//  for (int i = 0; i <= 60; ++i) cerr << i << ' ' << f(i, 0) << endl;
  //  std::ios::sync_with_stdio(false);
  int n;
  scanf("%d", &n);
  vi a(n);
  int xr = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    xr ^= f(a[i], 0);
  }
  if (xr) {
    printf("NO\n");
  } else {
    printf("YES\n");
  }
  return 0;
}