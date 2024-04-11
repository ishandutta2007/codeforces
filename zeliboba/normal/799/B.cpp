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
//std::ios::sync_with_stdio(false);
  int n;
  scanf("%d", &n);
  vi p(n), a(n), b(n);
  set<pii> w[2][3];
  for (int i = 0; i < n; ++i) scanf("%d", &p[i]);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    --a[i];
    w[0][a[i]].insert(pii(p[i], i));
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
    --b[i];
    w[1][b[i]].insert(pii(p[i], i));
  }
  int m;
  scanf("%d", &m);
  vi c(m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &c[i]);
    --c[i];
    int best = n, mi = 2e9;
    if (!w[0][c[i]].empty()) {
      int x = w[0][c[i]].begin()->second;
      if (mi > p[x]) {
        mi = p[x];
        best = x;
      }
    }
    if (!w[1][c[i]].empty()) {
      int x = w[1][c[i]].begin()->second;
      if (mi > p[x]) {
        mi = p[x];
        best = x;
      }
    }
    if (best >= n) {
      printf("-1 ");
      continue;
    }
    printf("%d ", p[best]);
    w[0][a[best]].erase(pii(p[best], best));
    w[1][b[best]].erase(pii(p[best], best));
  }
  return 0;
}