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

vi pa, ps, res;
vector<set<int>> wss, wa;
vector<map<int, int>> comp;
vector<vii> g;

int getp(vi& p, int v) {
  if (p[v] == v) return v;
  return p[v] = getp(p, p[v]);
}

void joins(int a, int b, int val) {
  auto& p = ps;
  auto& w = wss;
  a = getp(p, a);
  b = getp(p, b);
  if (a == b) return;
  if (w[a].size() > w[b].size()) swap(a, b);
  p[a] = b;
  for (int v : w[a]) {
    for (auto q : g[v]) if (w[b].count(q.first)) {
      res[q.second] = val;
    }
  }
  for (int v : w[a]) {
    w[b].insert(v);
  }
  w[a].clear();
}

map<int, int> tmp;
vi todo;

void filter(map<int, int>& comp) {
  todo.clear();
  for (auto it : comp) {
    int pr = getp(ps, it.first);
    if (pr != it.first) todo.push_back(it.first);
  }
  for (int v : todo) {
    auto it = comp.find(v);
    assert(it != comp.end());
    int val = it->second;
    comp.erase(it);
    comp[getp(ps, v)] += val;
  }
}

void joina(int a, int b, int val) {
  auto& p = pa;
  auto& w = wa;
  a = getp(p, a);
  b = getp(p, b);
  if (a == b) return;
  if (w[a].size() > w[b].size()) swap(a, b);
//  cerr << a << ' ' << b << ' ' << val << endl;
//  cerr << w[a].size() << ' ' << w[b].size() << endl;
  p[a] = b;
  for (int v : w[a]) {
    tmp.clear();
    for (auto q : g[v]) if (w[b].count(q.first)) {
      tmp[getp(ps, q.first)] += 1;
    }
    filter(comp[b]);
    for (auto it : comp[b]) {
      assert(getp(ps, it.first) == it.first);
      tmp[it.first] -= it.second;
    }
    for (auto it : tmp) {
//      cerr << it.first << ' ' << it.second << endl;
      if (it.second < 0) {
        joins(v, it.first, val);
      }
    }
  } 
  for (int v : w[a]) {
    w[b].insert(v);
    comp[b][getp(ps, v)] += 1;
  }
  w[a].clear();
  comp[a].clear();
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T = 1;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    int n, m;
    cin >> n >> m;
    res.assign(m, 1e9);
    g.assign(n, vii());
    vector<array<int, 3>> e(m);
    for (int i = 0; i < m; ++i) {
      cin >> e[i][1] >> e[i][2] >> e[i][0];
      --e[i][1]; --e[i][2];
      g[e[i][1]].emplace_back(e[i][2], i);
      g[e[i][2]].emplace_back(e[i][1], i);
    }
    pa.assign(n, 0);
    ps.assign(n, 0);
    wss.assign(n, set<int>());
    wa.assign(n, set<int>());
    comp.assign(n, map<int, int>());
    for (int i = 0; i < n; ++i) {
      pa[i] = ps[i] = i;
      wss[i].insert(i);
      wa[i].insert(i);
      comp[i][i] = 1;
    }
    sort(e.begin(), e.end());
    for (auto x : e) {
      joina(x[1], x[2], x[0]);
    }
    for (int i = 0; i < m; ++i) cout << res[i] << ' ';
    cout << '\n';
  }
  return 0;
}