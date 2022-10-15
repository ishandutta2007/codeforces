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
const int mod = 1000000007;

const int L = 3;
const ll p = 1000003;
std::array<int, L> mods = {1090000001, 1090000027, 1090003003};
std::array<int, L+1> h[1000005];

int main() {
  vl fac(1000005, 1);
  for (int i = 1; i < fac.size(); ++i) fac[i] = fac[i-1] * i % mod;
  int n, m;
  scanf("%d%d", &n, &m);
  vi c(m), x;
  std::array<ll, L+1> pw = {1, 1, 1, 1};
  for (int i = 0; i < n; ++i) {
    int k;
    scanf("%d", &k);
    x.resize(k);
    for (int j = 0; j < k; ++j) {
      scanf("%d", &x[j]);
      --x[j];
      ++c[x[j]];
    }
    for (int j = 0; j < k; ++j) if (c[x[j]]) {
      for (int l = 0; l < L; ++l) {
        h[x[j]][l] = (h[x[j]][l] + pw[l] * c[x[j]]) % mods[l];
      }
      h[x[j]][L] += pw[L] * c[x[j]];
      c[x[j]] = 0;
    }
    for (int j = 0; j < L; ++j) {
      pw[j] = pw[j] * p % mods[j];
    }
    pw[L] *= p;
  }
  sort(h, h + m);
  int cnt = 1;
  ll res = 1;
  for (int i = 1; i < m; ++i) {
    if (h[i] == h[i-1]) {
      ++cnt;
    } else {
      res = res * fac[cnt] % mod;
      cnt = 1;
    }
  }
  res = res * fac[cnt] % mod;
  printf("%lld\n", res);
  return 0;
}