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

void f(vi& v) {
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  //std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m;
  scanf("%d%d", &n, &m);
  vvi a(n, vi(m));
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) scanf("%d", &a[i][j]);
  vvi r(n, vi(m)), c(m, vi(n));
  for (int i = 0; i < n; ++i) {
    r[i] = a[i];
    f(r[i]);
  }
  for (int j = 0; j < m; ++j) {
    for (int i = 0; i < n; ++i) c[j][i] = a[i][j];
    f(c[j]);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int posr = lower_bound(r[i].begin(), r[i].end(), a[i][j]) - r[i].begin();
      int posc = lower_bound(c[j].begin(), c[j].end(), a[i][j]) - c[j].begin();
      printf("%d ", max(posc, posr) + (int)max(r[i].size() - posr, c[j].size() - posc));
    }
    printf("\n");
  }
  return 0;
}