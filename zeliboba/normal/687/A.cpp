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
vvi c(2);
vi was;
bool fail = 0;

void dfs(int v, int col) {
  if (was[v]) {
    if (was[v] != 1+col) fail = 1;
    return;
  }
  was[v] = 1+col;
  c[col].push_back(v);
  for (int nv : g[v]) dfs(nv, 1-col);
}

int main() {
  int n, m;
  cin >> n >> m;
  g.resize(n);
  was.assign(n, 0);
  for (int i = 0; i < m; ++i) {
    int a,b;
    scanf("%d%d", &a, &b);
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 0; i < n; ++i) if (!was[i]) {
    dfs(i, 0);
  }
  if (fail) printf("-1\n");
  else {
    for (int i = 0; i < 2; ++i) {
      printf("%d\n", (int)c[i].size());
      for (int v : c[i]) printf("%d ", v + 1);
      printf("\n");
    }
  }
  return 0;
}