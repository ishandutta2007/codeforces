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
const int mod = 1000000007;

vvi g;
vi to, was;
vl d;
ll res = 1;

void dfs(int v) {
  d[v] = 1;
  for (int nv : g[v]) {
    dfs(nv);
    d[v] += d[nv];
  }
  to[v] = -1;
  g[v].clear();
  d[v] %= mod;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  g.resize(2 * n);
  to.assign(2 * n, -1);
  was.assign(2 * n, -1);
  d.assign(2 * n, 0);
  for (int i = 0; i < n; ++i) {
    int a,b;
    cin >> a >> b;
    --a; --b;
    g[b].push_back(a);
    to[a] = b;
  }
  for (int i = 0; i < 2 * n; ++i) if (!g[i].empty() && to[i] == -1) {
    dfs(i);
    res = res * d[i] % mod;
//    cerr << res << endl;
  }
  for (int i = 0; i < 2 * n; ++i) if (to[i] >= 0 && was[i] == -1) {
    int cur = i;
    while (was[cur] == -1) {
      was[cur] = i;
      cur = to[cur];
    }
    if (was[cur] == i && to[cur] != cur) res = res * 2 % mod;
  }
  cout << res << endl;
  return 0;
}