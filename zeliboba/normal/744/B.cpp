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
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

const int DEBUG = 0;
const int M = 10;

int main() {
  int n;
  scanf("%d", &n);
  vvi A(n, vi(n));
  for (int i = 0; i < n; ++i) for (int j= 0; j < n; ++j) if (i != j) A[i][j] = rand() % 100000;
  vi v[2][M];
  for (int b = 0; b < M; ++b) {
    int B = (1 << b);
    for (int t = 0; t < 2; ++t) {
      vi w;
      for (int s = t * B; s < n; s += 2*B) {
        for (int i = 0; i < B && s + i < n; ++i) {
          w.push_back(s + i);
        }
      }
      vi ans(n, 1.1e9);
      if (!w.empty()) {
        printf("%d\n", (int)w.size());
        for (int x : w) printf("%d ", x + 1);
        printf("\n");
        fflush(stdout);
        if (DEBUG) {
          for (int i = 0; i < n; ++i) for (int x : w) ans[i] = min(ans[i], A[i][x]);
        } else for (int i = 0; i < n; ++i) scanf("%d", &ans[i]);
      }
      v[t][b] = ans;
    }
  }
  printf("-1\n");
  vi res(n, 1.1e9);
  for (int i = 0; i < n; ++i) {
    for (int b = 0; b < M; ++b) {
      int t = (i & (1 << b)) ? 0 : 1;
      res[i] = min(res[i], v[t][b][i]);
//      cerr << b << ' ' << t << ' ' << v[t][b][i] << endl;
    }
    printf("%d ", res[i]);
    int mi = 1.1e9;
    if (DEBUG) {
      for (int j = 0; j < n; ++j) if (i != j) mi = min(mi, A[i][j]);
//      cerr << mi << endl;
      assert(mi == res[i]);
    }
  }
  printf("\n");
  fflush(stdout);
  return 0;
}