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
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<ll, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

vvi g;
vii edges;
int n, m, L, s, t;

ll f() {
  vl d(n, 1e18);
  d[s] = 0;
  set<pii> q;
  q.insert(pii(0, s));
  while (!q.empty()) {
    int v = q.begin()->second;
    q.erase(q.begin());
    for (int e : g[v]) {
      int nv = edges[e].first;
      ll cand = edges[e].second + d[v];
      if (cand < d[nv]) {
        q.erase(pii(d[nv], nv));
        d[nv] = cand;
        q.insert(pii(d[nv], nv));
      }
    }
  }
  return d[t];
}

int main() {
  cin >> n >> m >> L >> s >> t;
  g.resize(n);
  vi bad; 
  for (int i = 0; i < m; ++i) {
    int u,v,w;
    cin >> u >> v >> w;
    if (w == 0) bad.push_back(edges.size());
    g[u].push_back(edges.size());
    edges.push_back(pii(v, max(w, 1)));
    g[v].push_back(edges.size());
    edges.push_back(pii(u, max(w, 1)));
  }
  int l = 1, r = L + 1;
  while (r - l > 1) {
    int x = (l + r) / 2;
    for (int i : bad) {
      edges[i].second = edges[i+1].second = x;
    }
    ll d = f();
//    cerr << x << ' ' << d << endl;
    if (d <= L) {
      l = x;
    } else {
      r = x;
    }
  }
  int base = l;
  l = 0, r = bad.size() + 1;
  while (r - l > 1) {
    int x = (l + r) / 2;
    for (int i = 0; i < x; ++i) {
      edges[bad[i]].second = edges[bad[i]+1].second = base+1;
    }
    for (int i = x; i < bad.size(); ++i) {
      edges[bad[i]].second = edges[bad[i]+1].second = base;
    }
    ll d = f();
    if (d <= L) {
      l = x;
    } else {
      r = x;
    }
  }
  for (int i = 0; i < l; ++i) {
    edges[bad[i]].second = edges[bad[i]+1].second = base+1;
  }
  for (int i = l; i < bad.size(); ++i) {
    edges[bad[i]].second = edges[bad[i]+1].second = base;
  }
//  cerr << base << ' ' << l << ' ' << f() << ' ' << L << endl;
  if (f() != L) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for (int i = 0; i < edges.size(); i += 2) {
      cout << edges[i+1].first << ' ' << edges[i].first << ' ' << edges[i].second << endl;
    }
  }
  return 0;
}