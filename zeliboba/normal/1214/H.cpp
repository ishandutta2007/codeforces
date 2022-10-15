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

vvi g;

vi far(int s) {
  vi d(g.size(), 1e9);
  d[s] = 0;
  vi q(1, s), pr(g.size(), -1);
  int it = 0;
  while (it < q.size()) {
    int v = q[it++];
    for (int nv : g[v]) {
      if (d[nv] > d[v] + 1) {
        d[nv] = d[v] + 1;
        pr[nv] = v;
        q.push_back(nv);
      }
    }
  }
  vi res(1, q.back());
  while (pr[res.back()] != -1) {
    res.push_back(pr[res.back()]);
  }
  return res;
}

vi col, dep;
bool FAIL = 0;
int k;

void dfs(int v, int p, int add) {
//  cerr << v << ' ' << p << endl;
  vi ts;
  dep[v] = 1;
  col[v] = (col[p] + add) % k;
  for (int nv : g[v]) if (nv != p) {
    dfs(nv, v, add);
    ts.push_back(dep[nv]);
    dep[v] = max(dep[v], dep[nv] + 1);
  }
  sort(ts.rbegin(), ts.rend());
  if (ts.size() >= 2 && k > 2 && ts[0] + ts[1] >= k - 1) {
    FAIL = 1;
  }
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n >> k;
  g.resize(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int a = far(0)[0];
  vi p = far(a);
  col.assign(n, -1);
  for (int i = 0; i < p.size(); ++i) col[p[i]] = i % k;
  int l = p.size();
  dep.assign(n, 1);
//  cerr << l << ' ' << p[0] << ' ' << p[1] << ' ' << p[2] << endl;
  dfs(p[(l + 1) / 2], p[(l + 1) / 2 - 1], 1);
  dfs(p[l / 2 - 1], p[l / 2], k - 1);
  if (l % 2 && l > 1) {
    dfs(p[l/2], p[l/2 - 1], 1);
  }
  if (FAIL) cout << "No\n";
  else {
    cout << "Yes\n";
    for (int i = 0; i < n; ++i) cout << col[i] + 1 << ' ';
    cout << endl;
  }
  return 0;
}