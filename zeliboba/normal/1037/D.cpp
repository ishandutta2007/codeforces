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
vi d;
void dfs(int v, int p, int dist) {
  d[v] = dist;
  for (int nv : g[v]) if (nv != p) {
    dfs(nv, v, dist + 1);
  }
}

void no() {
  cout << "No\n";
  exit(0);
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  g.resize(n);
  d.resize(n);
  for (int i = 0; i < n-1; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0, -1, 0);
  vi p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
  }
  vi firstp(n, n);
  for (int i = 0; i < n; ++i) {
    for (int nv : g[p[i]]) {
      firstp[nv] = min(firstp[nv], i);
    }
//    cerr << d[p[i]] << ' ' << firstp[p[i]] << endl;
  }
  for (int i = 0; i + 1 < n; ++i) if (pii(d[p[i]], firstp[p[i]]) > pii(d[p[i+1]], firstp[p[i+1]])) no();
  cout << "Yes\n";
  return 0;
}