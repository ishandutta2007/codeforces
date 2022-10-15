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

int cent = -1;
vi d, sz;
vvi g;

void dfs0(int v, int p) {
  sz[v] = 1;
  for (int nv : g[v]) if (nv != p) {
    dfs0(nv, v);
    sz[v] += sz[nv];
  }
  if (sz[v] >= (g.size() + 1) / 2 && cent == -1) cent = v;
}

void dfs(int v1, int p, const vi& v, int& it) {
  if (p != -1) {
    int e = v[it] - d[p];
    d[v1] = v[it];
    cout << p + 1 << ' ' << v1 + 1 << ' ' << e << '\n';
    ++it;
  }
  for (int nv : g[v1]) if (nv != p) {
    dfs(nv, v1, v, it);
  }
}

/*vi getv(int n) {
  vi v;
  int m = n / 2;
  for (int i = 1; i <= m; ++i) v.push_back(i);
  for (int j = 1; v.size() < n - 1; ++j) {
    int j2 = j * j;
    if (j2 > m) {
      v.push_back(j2);
    }
  }
  vi was(2 * n * n / 9 + 1);
  for (int i = 0; i < v.size(); ++i) {
    was[v] = 1;
  }
  return v;
}*/

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
/*  vi v(1, 1);
  vi was(1e6);
  was[1] = 1;
  int it = 2;
  for (int i = 2; i <= 1000; ++i) {
    for (int i : v) if (i + it < was.size()) was[i + it] = 1;
    was[it] = 1;
    v.push_back(it);
    while (it < was.size() && was[it]) ++it;
    cerr << i << ' ' << v.back() << ' ' << it << endl;
    assert(it > 2 * i * i / 9);
  }*/
  int n;
  cin >> n;
  g.resize(n);
  d.assign(n, 0);
  sz.assign(n, 0);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs0(0, -1);
  cerr << cent << endl;
  dfs0(cent, -1);
  vi v1;
  for (int i = 1; i <= n; ++i) v1.push_back(i);
  vii ts;
  for (int v : g[cent]) ts.emplace_back(sz[v], v);
  sort(ts.rbegin(), ts.rend());
  int s = 0, it = 0;
  for (pii p : ts) {
    int v = p.second;
    dfs(v, cent, v1, it);
    s += sz[v];
//    cerr << v << ' ' << s << endl;
    if (s >= n / 3) {
      v1.clear();
      for (int j = 1; v1.size() < n - s; ++j) {
        v1.push_back(j * (s + 1));
      }
      it = 0;
      s = -1e9;
    }
  }
  return 0;
}