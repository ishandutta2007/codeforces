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
ll res = 1e18;
int n, m, k;

void run(const vvi & v, vi & it, ll & cur) {
  int need = k - it[3];
  while (it[1] < v[1].size() && it[1] < need) {
    cur += v[1][it[1]];
    ++it[1];
  }
  while (it[2] < v[2].size() && it[2] < need) {
    cur += v[2][it[2]];
    ++it[2];
  }
  if (it[1] < need || it[2] < need) return;
  while (it[0] < m - it[1] - it[2] - it[3]) {
    int best = 4, mi = 2e9;
    for (int i = 0; i < 3; ++i) {
      if (it[i] < v[i].size() && v[i][it[i]] < mi) {
        best = i;
        mi = v[i][it[i]];
      }
    }
    if (best > 2) break;
    cur += v[best][it[best]];
    ++it[best];
  }
  while (it[0] > m - it[1] - it[2] - it[3]) {
    int best = 4, ma = 0;
    for (int i = 0; i < 3; ++i) {
      if (it[i] > 0 && v[i][it[i]-1] > ma && (i == 0 || it[i] > need)) {
        best = i;
        ma = v[i][it[i]-1];
      }
    }
    if (best > 2) break;
    --it[best];
    cur -= v[best][it[best]];
  }
//  cerr << it[0] << ' ' << it[1] << ' ' << it[2] << ' ' << it[3] << endl; 
  if (m == it[0] + it[1] + it[2] + it[3]) res = min(res, cur);
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  vi c(n);
  for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
  vi t(n);
  int a;
  scanf("%d", &a);
  for (int i = 0; i < a; ++i) {
    int x;
    scanf("%d", &x);
    t[x-1] |= 1;
  }
  scanf("%d", &a);
  for (int i = 0; i < a; ++i) {
    int x;
    scanf("%d", &x);
    t[x-1] |= 2;
  }
  vvi v(4);
  for (int i = 0; i < n; ++i) {
    v[t[i]].push_back(c[i]);
  }
  for (int i = 0; i < 4; ++i) {
    sort(v[i].begin(), v[i].end());
//    for (int x : v[i]) cerr << i << ' ' << x << endl;
  }
  vi it(4);
  it[3] = v[3].size();
  ll cur = 0;
  for (int x : v[3]) cur += x;
  run(v, it, cur);
  while (it[3] > 0) {
    --it[3];
    cur -= v[3][it[3]];
    run(v, it, cur);
  }
  if (res < 1e17) {
    printf("%lld\n", res);
  } else {
    printf("-1\n");
  }
  return 0;
}