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

vector<set<int>> g;
//vector<set<int>> tr;
vector<array<int, 3>> res;
vi was;//, sz;

void del(int a, int b) {
  g[a].erase(b);
  g[b].erase(a);
//  tr[a].erase(b);
//  tr[b].erase(a);
}

void push(int a, int b, int c) {
  res.push_back({a, b, c});
  del(a, b);
  del(b, c);
}

//vi comp;
bool dfs(int v, int p) {
  if (was[v]) return 0;
  was[v] = 1;
//  sz[v] = 1;
//  comp.push_back(v);
  vi bad, all;
  for (int nv : g[v]) {
    all.push_back(nv);
  }
  for (int nv : all) {
    if (!g[v].count(nv) || nv == p) continue;
    if (!was[nv]) {
      if (dfs(nv, v)) {
        bad.push_back(nv);
//        sz[v] += sz[nv];
      }
    } else {
      bad.push_back(nv);
    }
  }
  while (bad.size() >= 2) {
    int a = bad.back();
    bad.pop_back();
    int b = bad.back();
    bad.pop_back();
    push(a, v, b);
  }
  if (bad.empty()) return true;
  if (p != -1) push(bad[0], v, p);
  return false;
}
/*
array<int, 3> check0(int v) {
  if (tr[v].size() == 1 && g[v].size() > 1) {
    int a = *tr[v].begin();
    auto it = g[v].begin();
    while (*it == a) ++it;
    int b = *it;
    return {a, v, b};
  }
  return {-1, -1, -1};
}

array<int, 3> check1(int v) {
  if (tr[v].size() == 2) {
    auto it = tr[v].begin();
    int a = *it; ++it;
    int b = *it;
    if (tr[a].size() == 1 || tr[b].size() == 1) return {a, v, b};
  }
  return {-1, -1, -1};
}*/

int main() {
  //std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m;
  scanf("%d%d", &n, &m);
  g.resize(n);
  was.assign(n, 0);
//  sz.assign(n, 0);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a;--b;
    g[a].insert(b);
    g[b].insert(a);
  }
  for (int i = 0; i < n; ++i) if (!was[i] && !g[i].empty()) {
  //  comp.clear();
    dfs(i, -1);
/*    vi q;
    for (int v : comp) {
      bool add = 0;
      int c = 0;

    }*/
  }
  printf("%d\n", (int)res.size());
  for (auto v : res) {
    printf("%d %d %d\n", v[0] + 1, v[1] + 1, v[2] + 1);
  }
  return 0;
}