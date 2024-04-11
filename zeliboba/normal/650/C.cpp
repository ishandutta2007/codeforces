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

vi p;
vvi r;

int getp(int v) {
  if (v == p[v]) return v;
  return p[v] = getp(p[v]);
}

void join(int a, int b) {
  a = getp(a); b = getp(b);
  if (a == b) return;
  if (r[a].size() < r[b].size()) swap(a, b);
  p[b] = a;
  while (r[b].size()) {
    r[a].push_back(r[b].back());
    r[b].pop_back();
  }
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vvi a(n, vi(m));
  vi ts;
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    scanf("%d", &a[i][j]);
    ts.push_back(a[i][j]);
  }
  sort(ts.begin(), ts.end());
  ts.resize(unique(ts.begin(), ts.end()) - ts.begin());
  vector<vii> v(ts.size());
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
    a[i][j] = lower_bound(ts.begin(), ts.end(), a[i][j]) - ts.begin();
    v[a[i][j]].push_back(pii(i, j));
  }
  vi mar(n), mac(m);
  for (int i = 0; i < v.size(); ++i) {
    p.resize(v[i].size());
    r.resize(p.size());
    for (int j = 0; j < p.size(); ++j) {
      p[j] = j;
      r[j] = vi(1, j);
    }
    vvi ts(v[i].size(), vi(3));
    for (int j = 0; j < ts.size(); ++j) {
      ts[j][0] = v[i][j].first;
      ts[j][1] = v[i][j].second;
      ts[j][2] = j;
    }
    sort(ts.begin(), ts.end());
    for (int j = 0; j + 1 < ts.size(); ++j) {
      if (ts[j][0] == ts[j+1][0]) join(ts[j][2], ts[j+1][2]);
    }
    for (int j = 0; j < ts.size(); ++j) swap(ts[j][0], ts[j][1]);
    sort(ts.begin(), ts.end());
    for (int j = 0; j + 1 < ts.size(); ++j) {
      if (ts[j][0] == ts[j+1][0]) join(ts[j][2], ts[j+1][2]);
    }
    for (int j = 0; j < p.size(); ++j) if (p[j] == j) {
      int ma = 0;
      for (int x : r[j]) {
        auto p = v[i][x];
        ma = max(ma, mar[p.first]);
        ma = max(ma, mac[p.second]);
      }
      ++ma;
      for (int x : r[j]) {
        auto p = v[i][x];
        a[p.first][p.second] = ma;
        mar[p.first] = ma;
        mac[p.second] = ma;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
  return 0;
}