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
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

vvi g;
int p[18][200005];
int c[18][200005];
ll w[18][200005];
int add[200005];
int res[200005];

int dfs(int v, int p) {
  int sum = 0;
  for (int nv : g[v]) {
    if (nv == p) continue;
    sum += dfs(nv, v);
  }
  res[v] = sum;
  return sum + add[v];
}

int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  g.resize(n);
  vi a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 1; i < n; ++i) {
    cin >> p[0][i] >> w[0][i];
    --p[0][i];
    g[p[0][i]].push_back(i);
    c[0][i] = 1;
  }
  for (int b = 1; b < 18; ++b) {
    for (int i = 0; i < n; ++i) {
      p[b][i] = p[b-1][p[b-1][i]];
      w[b][i] = w[b-1][i] + w[b-1][p[b-1][i]];
      c[b][i] = c[b-1][i] + c[b-1][p[b-1][i]];
    }
  }
  for (int i = 0; i < n; ++i) {
    int cnt = 0, cur = i;
    add[i] += 1;
    for (int b = 17; b >= 0; --b) {
      if (a[i] >= w[b][cur]) {
        a[i] -= w[b][cur];
        cnt += c[b][cur];
        cur = p[b][cur];
      }
    }
    add[cur] -= 1;
//    cout << cnt << ' ';
  }
  dfs(0, -1);
  for (int i = 0; i < n; ++i) cout << res[i] << ' ';
  return 0;
}