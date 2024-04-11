#include <algorithm>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

typedef long long llint;

const int MAXV = 1e6 + 123;
const int MAXLOG = 20;

int depth[MAXV];
int uplink[MAXLOG][MAXV];

int lca(int a, int b) {
  if (depth[a] > depth[b]) swap(a, b);
  int delta = depth[b] - depth[a];
  REP(bit, MAXLOG) if (delta&(1<<bit)) b = uplink[bit][b];
  if (a == b) return a;
  for (int bit = MAXLOG - 1; bit >= 0; --bit) {
    int A = uplink[bit][a];
    int B = uplink[bit][b];
    if (A != B) a = A, b = B;
  }
  return uplink[0][a];
}

int main(void)
{
  int n_oper; scanf("%d", &n_oper);
  memset(uplink, -1, sizeof uplink);
  depth[0] = 0;
  REP(i, 3) { uplink[0][i+1] = 0; depth[i+1] = 1; }
  REP(i, n_oper) {
    int leaf; scanf("%d", &leaf); --leaf;
    int c1 = 4 + 2*i;
    int c2 = 5 + 2*i;
    depth[c1] = depth[c2] = depth[leaf] + 1;
    uplink[0][c1] = uplink[0][c2] = leaf;
  }
  int n_v = 4 + 2*n_oper;
  for (int l = 1; l < MAXLOG; ++l) REP(i, n_v) {
      int& v = uplink[l][i]; v = i;
      if (v != -1) v = uplink[l-1][v];
      if (v != -1) v = uplink[l-1][v];
  }

  int diam = 2;
  int a = 1, b = 2;

  auto dist = [](int a, int b) {
    return depth[a] + depth[b] - 2*depth[lca(a, b)];
  };

  auto upd = [&dist, &a, &b, &diam](int x) {
    int val;
    val = dist(a, x);
    if (val > diam) b = x, diam = val;
    val = dist(b, x);
    if (val > diam) a = x, diam = val;
  };

  REP(i, n_oper) {
    upd(4 + 2*i);
    upd(5 + 2*i);
    printf("%d\n", diam);
  }

  return 0;
}