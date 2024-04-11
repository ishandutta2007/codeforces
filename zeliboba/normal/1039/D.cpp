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
#include <chrono>
#include <random>
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

vvi g, g1;
vi d, h;
vi ord;

void dfs0(int v, int pr) {
  for (int nv : g[v]) if (nv != pr) {
    dfs0(nv, v);
    g1[v].push_back(nv);
  }
  ord.push_back(v);
}

void dfs(int v, int k) {
  d[v] = 0;
  h[v] = 1;
  pii p(0, 0);
  for (int nv : g1[v]) {
//    dfs(nv, v, k);
    d[v] += d[nv];
    if (p.second <= h[nv]) {
      p.first = p.second;
      p.second = h[nv];
    } else p.first = max(p.first, h[nv]);
  }
  if (p.first + p.second + 1 >= k) {
    h[v] = 0;
    d[v]++;
  } else {
    h[v] = 1 + p.second;
  }
}

map<int, int> saved;
int solve(int k) {
  if (saved.count(k)) return saved[k];
  d.resize(g.size());
  h.resize(g.size());
  for (int v : ord) dfs(v, k);
  saved[k] = d[0];
  return d[0];
}

void run(int l, int r, vi& res) {
  if (r - l < 2) return;
  if (res[l] == res[r]) {
    for (int i = l + 1; i < r; ++i) res[i] = res[l];
    return;
  }
  int m = (l + r) / 2;
  res[m] = solve(m);
  run(l, m, res);
  run(m, r, res);
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n = 100000;
  cin >> n;
  g.resize(n);
  g1.resize(n);
  for (int i = 0; i < n-1; ++i) {
    int a = i + 1, b = i + 2;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs0(0, -1);
  vi res(n + 2, -1);
  res[1] = n;
  res[n + 1] = 0;
//  const int T = 2000;
//  for (int i = 2; i <= min(T, n); ++i) res[i] = solve(i);
  run(1, n + 1, res);
/*  for (int i = T + 1; i <= n; ++i) {
    int cur = n;
    while (cur > i-1) {
      int t = solve(cur);
      if (t == res[i-1]) {
        for (int j = i; j <= cur; ++j) res[j] = t;
        break;
      }
      cur = (i - 1 + cur) / 2;
    }
    if (cur == i-1) res[i] = solve(i);
  }*/
  for (int i = 1; i <= n; ++i) cout << res[i] << '\n';
  return 0;
}