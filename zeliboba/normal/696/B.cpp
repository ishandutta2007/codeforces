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
#include <array>
#include <bitset>
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
vi sz;
vd d;

void dfs(int v) {
  sz[v] = 1;
  for (int nv : g[v]) {
    dfs(nv);
    sz[v] += sz[nv];
  }
}

void dfs1(int v) {
  for (int nv : g[v]) {
    d[nv] = d[v] + 1 + (sz[v] - 1 - sz[nv]) / 2.;
    dfs1(nv);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  g.resize(n);
  d.assign(n, 0);
  sz.assign(n, 0);
  for (int i = 1; i < n; ++i) {
    int a;
    scanf("%d", &a);
    --a;
    g[a].push_back(i);
  }
  dfs(0);
  d[0] = 1;
  dfs1(0);
  for (int i = 0; i < n; ++i) {
    printf("%.9lf ", d[i]);
  }
  return 0;
}