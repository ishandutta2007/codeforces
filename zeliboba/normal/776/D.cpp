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

vvi g, gw;
vi was;
bool ok = 1;

void dfs(int v, int c) {
  if (was[v] != -1) {
    if (was[v] != c) ok = 0;
    return;
  }
  was[v] = c;
  for (int i = 0; i < g[v].size(); ++i) {
    dfs(g[v][i], (c + gw[v][i]) % 2);
  }
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vi r(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &r[i]);
    r[i] = 1 - r[i];
  }
  vvi e(n);
  for (int i = 0; i < m; ++i) {
    int x;
    scanf("%d", &x);
    for (int j = 0; j < x; ++j) {
      int t; scanf("%d", &t);
      --t;
      e[t].push_back(i);
    }
  }
  g.resize(m);
  gw.resize(m);
  was.assign(m, -1);
  for (int i = 0; i < n; ++i) {
    g[e[i][0]].push_back(e[i][1]);
    g[e[i][1]].push_back(e[i][0]);
    gw[e[i][0]].push_back(r[i]);
    gw[e[i][1]].push_back(r[i]);
  }
  for (int i = 0; i < m; ++i) if (was[i] == -1) dfs(i, 0);
  if (ok) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}