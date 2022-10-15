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
typedef pair<ll, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

vi a;
vvi gr;
ll res = 0;
vl path, pathup, d1;

void dfs0(int v, int p) {
  path[v] = 0;
  vl ts;
  for (int i = 0; i < gr[v].size(); ++i) {
    int nv = gr[v][i];
    if (nv == p) continue;
    dfs0(nv, v);
    path[v] = max(path[v], path[nv]);
    ts.push_back(path[nv]);
  }
  path[v] += a[v];
  sort(ts.rbegin(), ts.rend());
  d1[v] = a[v];
  if (ts.size() >= 1) d1[v] += ts[0];
  if (ts.size() >= 2) d1[v] += ts[1];
  for (int i = 0; i < gr[v].size(); ++i) {
    int nv = gr[v][i];
    if (nv == p) continue;
    d1[v] = max(d1[v], d1[nv]);
  }
}

void dfs1(int v, int p) {
  vii ts(1, pii(pathup[v], p));
  for (int i = 0; i < gr[v].size(); ++i) {
    int nv = gr[v][i];
    if (nv == p) continue;
    ts.push_back(pii(path[nv], nv));
  }
  sort(ts.rbegin(), ts.rend());
  for (int i = 0; i < gr[v].size(); ++i) {
    int nv = gr[v][i];
    if (nv == p) continue;
    pathup[nv] = a[v];
    int cnt = 0;
    for (int j = 0; j < ts.size() && cnt < 1; ++j) if (ts[j].second != nv) {
      ++cnt;
      pathup[nv] += ts[j].first;
    }
    dfs1(nv, v);
  }
}

void dfs2(int v, int p, ll ma) {
//  cerr << v << ' ' << p << ' ' << ma << ' ' << d1[v] << endl;
  res = max(res, ma + d1[v]);
  vii ts(1, pii(pathup[v], p));
  for (int i = 0; i < gr[v].size(); ++i) {
    int nv = gr[v][i];
    if (nv == p) continue;
    ts.push_back(pii(path[nv], nv));
  }
  vii tsd(0);
  for (int i = 0; i < gr[v].size(); ++i) {
    int nv = gr[v][i];
    if (nv == p) continue;
    tsd.push_back(pii(d1[nv], nv));
  }
  sort(ts.rbegin(), ts.rend());
  sort(tsd.rbegin(), tsd.rend());
  for (int i = 0; i < gr[v].size(); ++i) {
    int nv = gr[v][i];
    if (nv == p) continue;
    int cnt = 0;
    ll sum = a[v];
    for (int j = 0; j < ts.size() && cnt < 2; ++j) if (ts[j].second != nv) {
      ++cnt;
      sum += ts[j].first;
    }
    ll sumd = 0;
    cnt = 0;
    for (int j = 0; j < tsd.size() && cnt < 1; ++j) if (tsd[j].second != nv) {
      ++cnt;
      sumd += tsd[j].first;
    }
    dfs2(nv, v, max(ma, max(sumd, sum)));
  }
}

int main() {
  int n;
  cin >> n;
  a.resize(n);
  path.assign(n, 0);
  pathup.assign(n, 0);
  d1.assign(n, 0);
  gr.resize(n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < n-1; ++i) {
    int a,b;
    scanf("%d%d", &a, &b);
    --a; --b;
    gr[a].push_back(b);
    gr[b].push_back(a);
  }
  dfs0(0, -1);
  dfs1(0, -1);
  dfs2(0, -1, 0);
  cout << res << endl;
  return 0;
}