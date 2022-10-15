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
#include <unordered_map>
#include <queue>
#include <array>
#include <bitset>
#include <chrono>
#include <random>
using namespace std;
typedef long double ld;
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
//const int mod = ;

vector < vector<int> > g, gr;
vector<char> used;
vector<int> order, component;
vvi comps;

void dfs1 (int v) {
  used[v] = true;
  for (size_t i=0; i<g[v].size(); ++i)
    if (!used[ g[v][i] ])
      dfs1 (g[v][i]);
  order.push_back (v);
}

void dfs2 (int v) {
  used[v] = true;
  component.push_back (v);
  for (size_t i=0; i<gr[v].size(); ++i)
    if (!used[ gr[v][i] ])
      dfs2 (gr[v][i]);
}

int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool in(int i, int j) {
  return i >= 0 && j >= 0 && i < n && j < m;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  cin >> n >> m;
  vs s(n);
  for (int i = 0; i < n; ++i) cin >> s[i];
  vi a(m);
  for (int i = 0; i < m; ++i) cin >> a[i];
  vvi dw(m, vi(n + 1)), sum(m, vi(n + 1)), up(m, vi(n, -1));
  vvi all(m);
  for (int j = 0; j < m; ++j) {
    dw[j][n] = n;
    for (int i = n - 1; i >= 0; --i) {
      dw[j][i] = dw[j][i + 1];
      if (s[i][j] == '#') {
        dw[j][i] = i;
        all[j].push_back(i);
      }
    }
    for (int i = 0; i < n; ++i) {
      if (s[i][j] == '#') {
        if (i && up[j][i - 1] != -1) up[j][i] = up[j][i - 1];
        else up[j][i] = i; 
      }
      sum[j][i + 1] = sum[j][i] + (s[i][j] == '#');
    }
  }
  g.resize(n * m); gr.resize(n * m);
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (s[i][j] == '#') {
    for (int d = 0; d < 4; ++d) {
      int i1 = i + dx[d], j1 = j + dy[d];
      if (in(i1, j1) && s[i1][j1] == '#') {
        g[i * m + j].push_back(i1 * m + j1);
      }
    }
    for (int t = max(0, j - 1); t <= min(m - 1, j + 1); ++t) {
      if (dw[t][i + 1] != n) g[i * m + j].push_back(dw[t][i + 1] * m + t);
    }
  }

  for (int i = 0; i < g.size(); ++i) for (int j : g[i]) gr[j].push_back(i);
  used.assign (g.size(), false);
  order.clear();
  for (int i=0; i<g.size(); ++i)
    if (!used[i])
      dfs1 (i);
  used.assign (g.size(), false);
  vi where(g.size());
  for (int i=0; i<g.size(); ++i) {
    int v = order[g.size()-1-i];
    if (!used[v]) {
      dfs2 (v);
      for (int x : component) where[x] = comps.size();
      comps.push_back(component);
      component.clear();
    }
  }
  vector<set<int>> w(comps.size());
  for (int i = 0; i < comps.size(); ++i) {
    w[i].insert(i);
    for (int v : comps[i]) {
      for (int v1 : g[v]) {
        w[i].insert(where[v1]);
      }
    }
  }
  int res = 0, pr = n;
  for (int j = m - 1; j >= 0; --j) {
    int i = pr;
    if (a[j]) {
      i = min(i, all[j][a[j] - 1]);
    }
//    cerr << res << ' ' << j << ' ' << i << ' ' << pr << endl;
    if (i == n) continue;
    int cur = where[i * m + j];
    pr = -1;
    if (j) for (int x : all[j - 1]) if (w[where[x * m + j - 1]].count(cur) || x <= i) {
      pr = x;
      break;
    }
    if (pr == -1) {
      ++res;
      pr = n;
      int cur = all[j].back() * m + j;
      bool ok = 1;
      for (int j1 = j - 1; j1 >= 0; --j1) {
        if (a[j1] && !w[where[cur]].count(where[j1 + m * all[j1][a[j1] - 1]]) && all[j1][a[j1] - 1] < cur / m) {
          j = j1 + 1;
          ok = 0;
          break;
        }
        int best = n;
        for (int x : all[j1]) if (w[where[cur]].count(where[j1 + m * x]) || x >= cur / m) {
          best = x;
        }
        if (best == n) {
          ok = 0;
          j = j1;
          break;
        }
        cur = j1 + best * m;
      }
      if (ok) j = 0;
    }
  }
  cout << res << endl;
  return 0;
}