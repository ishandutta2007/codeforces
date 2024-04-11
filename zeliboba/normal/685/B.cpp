#include <cstdio>
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

vvi g;
vi pr, sz, f;

void dfs(int v) {
  sz[v] = 1;
  f[v] = v;
  int ma = 0, best = -1;
  for (int nv : g[v]) {
    dfs(nv);
    sz[v] += sz[nv];
    if (sz[nv] > ma) {
      ma = sz[nv];
      best = nv;
    }
  }
  if (g[v].empty()) return;
  int t = f[best];
  while (sz[t]*2 < sz[v]) t = pr[t];
  f[v] = t;
}

int main() {
  int n, Q;
  scanf("%d%d", &n, &Q);
  g.resize(n);
  pr.assign(n, 0);
  sz.assign(n, 0);
  f.assign(n, 0);
  for (int i = 1; i < n; ++i) {
    int p;
    scanf("%d", &p);
    --p;
    g[p].push_back(i);
    pr[i] = p;
  }
  dfs(0);
  for (int i = 0; i < Q; ++i) {
    int x;
    scanf("%d", &x);
    --x;
    printf("%d\n", f[x] + 1);
  }
  return 0;
}