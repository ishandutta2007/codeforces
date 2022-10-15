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
//const int mod = ;

int d[5005][5005];

int main() {
//  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  scanf("%d", &n);
  vi a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    d[i][i] = a[i];
  }
  for (int l = 1; l < n; ++l) for (int i = 0; i + l < n; ++i) {
    int j = i + l;
    d[i][j] = d[i+1][j] ^ d[i][j-1];
  }
  for (int l = 1; l < n; ++l) for (int i = 0; i + l < n; ++i) {
    int j = i + l;
    d[i][j] = max(d[i][j], max(d[i][j-1], d[i+1][j]));
  }
  int q;
  scanf("%d", &q);
  for (int t = 0; t < q; ++t) {
    int l, r;
    scanf("%d%d", &l, &r);
    --l; --r;
    printf("%d\n", d[l][r]);
  }
  return 0;
}