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

vvi g;

vi far(int s) {
  vi d(g.size(), 1e9), p(g.size());
  d[s] = 0;
  p[s] = -1;
  vi q(1, s);
  int it = 0;
  while (it < q.size()) {
    int v = q[it];
    for (int nv : g[v]) {
      if (d[nv] > d[v] + 1) {
        d[nv] = d[v] + 1;
        q.push_back(nv);
        p[nv] = v;
      }
    }
    ++it;
  }
  vi res(1, q.back());
  while (res.back() != s) {
    int cur = res.back();
    res.push_back(p[cur]);
  }
  return res;
}

int dfs(int v, int p) {
  int prev = 0;
  for (int nv : g[v]) {
    if (nv == p) continue;
    int res = dfs(nv, v); 
    if (!res || (prev && prev != res)) {
//      cerr << v << ' ' << p << ' ' << nv << endl;
      return 0;
    }
    prev = res;
  }
  return 1 + prev;
}

int main() {
  int n;
  scanf("%d", &n);
  g.resize(n);
  for (int i = 0; i < n-1; ++i) {
    int u,v;
    scanf("%d%d", &u, &v);
    --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vi f1 = far(0);
  vi diam = far(f1[0]);
  int m = diam.size();
//  cerr << m << endl;
  if (m % 2) {
    int s = diam[m/2];
    vi d;
    for (int v : g[s]) {
      d.push_back(dfs(v, s));
//      cerr << v + 1 << ' ' << d.back() << endl;
    }
    bool ok = 1;
    sort(d.begin(), d.end());
    d.resize(unique(d.begin(), d.end()) - d.begin());
    if (d[0] == 0 || d.size() > 2) {
      cout << -1 << endl;
      return 0;
    }
    m = 1;
    for (int x : d) {
      m += x;
    }
    while (m % 2) {
      m = (m + 1) / 2;
    }
    cout << m-1 << endl;
/*    if (dfs(diam[m/2], -1)) {
      while (m % 2) {
        m = (m + 1) / 2;
        cout << m+1 << endl;
      }
    } else {
      cout << -1 << endl;
    }*/
  } else {
    if (dfs(diam[m/2], diam[m/2-1]) && dfs(diam[m/2-1], diam[m/2])) {
      cout << m-1 << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}