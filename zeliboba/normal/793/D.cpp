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

int d[100][100][100];
int g[100][100];

int main() {
  std::ios::sync_with_stdio(false);
  int n, k, m;
  cin >> n >> k >> m;
  //vvi g(n), gw(n);
  for (int i = 0; i < m; ++i) {
    int a,b,c;
    cin >> a >> b >> c;
    if (g[a][b]) g[a][b] = min(g[a][b], c);
    else g[a][b] = c;
    assert(c);
    //g[a].push_back(b);
    //gw[a].push_back(c);
  }
  for (int t = 1; t <= k-1; ++t) {
    for (int i = 1; i <= n; ++i) for (int j = 0; j <= n+1; ++j) if (i != j) {
      d[t][i][j] = 1e9;
      for (int l = min(i, j) + 1; l < max(i, j); ++l) if (g[i][l]) {
        d[t][i][j] = min(d[t][i][j], g[i][l] + min(d[t-1][l][i], d[t-1][l][j]));
      }
    }
  }
  int res = 1e9;
  for (int i = 1; i <= n; ++i) {
    res = min(res, min(d[k-1][i][0], d[k-1][i][n+1]));
  }
  if (res > 1e8) res = -1;
  cout << res << endl;
  return 0;
}