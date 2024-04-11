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

vvi g;
vi used, x;
bool fail = false;

void dfs(int v, int p, int col) {
  if (used[v] || x[v]) {
    if (x[v]) fail = 1;
    return;
  }
  x[v] = col;
  for (int nv : g[v]) {
    if (nv == p) continue;
    dfs(nv, v, 3 - col);
  }
}

void dfs2(int v, int p, int col) {
  x[v] = col;
  for (int nv : g[v]) {
    if (nv == p || used[nv]) continue;
    dfs2(nv, v, col + 1);
  }
}

int main() {
//std::ios::sync_with_stdio(false);
  int n, m;
  scanf("%d%d", &n, &m);
  g.resize(n);
  used.assign(n, 0);
  x.assign(n, 0);
  vi e1(m), e2(m);
  for (int i = 0; i < m; ++i) {
    int a,b;
    scanf("%d%d", &a, &b);
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
    e1[i] = a;
    e2[i] = b;
  }
  for (int i = 0; i < n; ++i) sort(g[i].begin(), g[i].end());
  for (int e = 0; e < m; ++e) {
    int a = e1[e], b = e2[e];
    if (a > b) swap(a, b);
    if (g[a].size() != g[b].size() || used[b] || used[a]) continue;
    int c = 0, ib = 0;
    for (int ia = 0; ia < g[a].size(); ++ia) {
      while (ib < g[b].size() && g[b][ib] < g[a][ia]) ++ib;
      if (ib >= g[b].size()) break;
      if (g[a][ia] == g[b][ib]) {
        ++c;
        ++ib;
      }
    }
    if (c + 1 == g[a].size()) {
      used[b] = 1 + a;
    }
  }
  int s0 = 0;
  for (int i = 0; i < n; ++i) if (!used[i]) {
    int c = 0;
    for (int nv : g[i]) if (!used[nv]) ++c;
    if (c > 2) fail = 1;
    if (c == 1) s0 = i;
  }
  dfs(0, -1, 1);
  if (fail) {
    printf("NO\n");
  } else {
    x.assign(n, 1);
    dfs2(s0, -1, 1);
    for (int i = 0; i < n; ++i) {
      if (used[i]) x[i] = x[used[i]-1];
    }
    printf("YES\n");
    for (int i = 0; i < n; ++i) printf("%d ", x[i] + 1);
  }
  return 0;
}