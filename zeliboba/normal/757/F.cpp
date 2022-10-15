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
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<ll, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

vvi g, gw;

const int L = 18;
const int N = 200005;
int up[N][L];
int ord[N];

bool upper (int a, int b) {
  if (ord[b] < ord[a]) return false;
  for (int i = L-1; i >= 0; --i) {
    int nb = up[b][i];
    if (ord[nb] >= ord[a]) b = nb;
  }
  return a == b || a == up[b][0];
}

int lca (int a, int b) {
  if (upper (a, b))  return a;
  if (upper (b, a))  return b;
  for (int i=L-1; i>=0; --i)
    if (! upper (up[a][i], b))
      a = up[a][i];
  return up[a][0];
}

int main() {
  int n, m, s;
  scanf("%d%d%d", &n, &m, &s);
  --s;
  g.resize(n);
  gw.resize(n);
  for (int i = 0; i < m; ++i) {
    int a,b,c;
    scanf("%d%d%d", &a, &b, &c);
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
    gw[a].push_back(c);
    gw[b].push_back(c);
  }
  set<pii> q;
  const ll MAX = 1e18;
  vl d(n, MAX);
  d[s] = 0;
  q.insert(pii(d[s], s));
  while (!q.empty()) {
    int v = q.begin()->second;
    q.erase(q.begin());
//    cerr << v+1 << endl;
    for (int i = 0; i < g[v].size(); ++i) {
      int nv = g[v][i];
      ll nd = d[v] + gw[v][i];
//      cerr << v+1 << ' ' << nv+1 << ' ' << nd << endl;
      if (nd < d[nv]) {
        q.erase(pii(d[nv], nv));
        d[nv] = nd;
        q.insert(pii(d[nv], nv));
      }
    }
  }
  vii ts;
  for (int i = 0; i < L; ++i) up[s][i] = s;
  for (int i = 0; i < n; ++i) {
//    cerr << i+1 << ' ' << d[i] << endl;
    if (d[i] < MAX) {
      ts.push_back(pii(d[i], i));
    }
  }
  sort(ts.begin(), ts.end());
  for (int i = 0; i < ts.size(); ++i) ord[ts[i].second] = i;
  for (int ii = 1; ii < ts.size(); ++ii) {
    int v = ts[ii].second, pr = -1;
    for (int i = 0; i < g[v].size(); ++i) {
      int nv = g[v][i];
      if (d[v] == d[nv] + gw[v][i]) {
        if (pr == -1) {
          pr = nv;
        } else {
          pr = lca(pr, nv);
        }
      }
    }
    up[v][0] = pr;
    for (int i = 1; i < L; ++i) {
      up[v][i] = up[up[v][i-1]][i-1];
    }
  }
  int res = 0;
  vi add(ts.size(), 1);
  for (int ii = ts.size() - 1; ii > 0; --ii) {
    int v = ts[ii].second;
    res = max(res, add[ii]);
    int pr = up[v][0];
    add[ord[pr]] += add[ii];
  }
  cout << res << endl;
  return 0;
}