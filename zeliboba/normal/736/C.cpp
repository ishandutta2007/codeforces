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
const int mod = 1000000007;

int n, k;
vvi g;
ll d[105][50];
ll sd[105][50];
ll tmp[50];

void dfs(int v, int p) {
//  if (g[v].size() == 0 || g[v].size() == 1 && g[v][0] == p)
    d[v][k+1] = 1;
//  else d[v][1] = 1;
  ll d0 = 1;
  for (int nv : g[v]) {
    if (nv == p) continue;
    dfs(nv, v);
    d0 = d0 * sd[nv][2*k] % mod;
    memset(tmp, 0, sizeof(tmp));
    for (int i = 1; i <= 2*k; ++i) for (int j = 0; j < 2*k; ++j) {
      int x = max(i, j+1);
      if (i + j + 1 <= 2 * k + 1) x = min(i, j + 1);
      tmp[x] = (tmp[x] + d[v][i] * d[nv][j]) % mod;
    }
    memcpy(d[v], tmp, sizeof(tmp));
  }
  sd[v][0] = d[v][0] = d0;
//  for (int i = 0; i <= 2*k; ++i) cerr << v << ' ' << d[v][i] << endl;
  for (int i = 1; i <= 2*k; ++i) sd[v][i] = (sd[v][i-1] + d[v][i]) % mod;
}

int main() {
  cin >> n >> k;
  if (k == 0) {
    cout << 1 << endl;
    return 0;
  }
//  k = min(2*k+1, n + 1);
  g.resize(n);
  for (int i = 0; i < n-1; ++i) {
    int a,b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0, -1);
  cout << sd[0][k] << endl;
  return 0;
}