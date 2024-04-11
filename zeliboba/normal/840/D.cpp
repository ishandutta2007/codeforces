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

const int M = 3700;
const int N = 300000;
int t[N+1];
int c[N+1];
int a[N+1];
int b[N+1];

const int C = 5 * N / M + 5;
int cc[N + 2][C];

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  vii ts(n + 1);
  for (int i = 0; i < ts.size(); ++i) ts[i].second = i;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    ts[a[i]].first++;
  }
  sort(ts.rbegin(), ts.rend());
  vi inv(n + 1);
  for (int i = 0; i < n; ++i) {
    inv[ts[i].second] = i;
  }
  for (int i = 0; i < n; ++i) b[i] = inv[a[i]];
//  int L = 0, M1 = M;
//  for (int i = 0; i < C; ++i) if (ts[i].first >= M1 / 5) ++L;
  for (int j = 0; j < n; ++j) {
    memcpy(cc[j+1], cc[j], sizeof(cc[j]));
    if (b[j] < C) ++cc[j+1][b[j]];
  }
  int M1 = ts[min(n-1, C - 1)].first * 5;
  for (int qq = 1; qq <= q; ++qq) {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    --l; --r;
    int need = (r - l + 1) / k + 1;
    int ans = n + 1;
    if (r - l <= M1) {
      for (int i = l; i <= r; ++i) {
        if (t[a[i]] != qq) {
          t[a[i]] = qq;
          c[a[i]] = 0;
        }
        ++c[a[i]];
        if (c[a[i]] >= need && a[i] < ans) {
          ans = a[i];
        }
      }
    } else {
      for (int i = 0; i < ts.size() && ts[i].first >= need; ++i) {
        if (cc[r+1][i] - cc[l][i] >= need && ans > ts[i].second) {
          ans = ts[i].second;
        }
      }
    }
    if (ans > n) ans = -1;
    printf("%d\n", ans);
  }
  return 0;
}