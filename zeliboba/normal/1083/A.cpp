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
typedef long double ld;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<ll, ll> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

struct E{
  E (int to, int c): to(to), c(c) {}
  int to;
  int c;
};

vector<vector<E>> g;
vl d;
ll res = 0;

void upd(pii& p, ll val) {
  if (p.first < val) {
    p.second = p.first;
    p.first = val;
  } else {
    p.second = max(p.second, val);
  }
}

void dfs(int v, int pr, const vi& w) {
  d[v] = w[v];
  pii ma(-1e18, -1e18);
  for (auto e : g[v]) {
    if (e.to == pr) continue;
    dfs(e.to, v, w);
    upd(ma, d[e.to] - e.c);
    d[v] = max(d[v], d[e.to] + w[v] - e.c);
  }
  res = max(res, d[v]);
  res = max(res, w[v] + ma.first + ma.second);
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vi w(n);
  for (int i = 0; i < n; ++i) cin >> w[i];
  g.resize(n);
  d.assign(n, 0);
  for (int i = 0; i < n-1; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    --a; --b;
    g[a].push_back(E(b, c));
    g[b].push_back(E(a, c));
  }
  dfs(0, -1, w);
  cout << res << endl;
  return 0;
}