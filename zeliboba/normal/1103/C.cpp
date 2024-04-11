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
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

vvi g;
vi h, pr;

void dfs(int v, int p, int curh) {
  if (h[v] != -1) return;
  h[v] = curh;
  pr[v] = p;
  for (int nv : g[v]) {
    dfs(nv, v, curh + 1);
  }
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  int l = (n + k - 1) / k;
  g.resize(n);
  h.assign(n, -1);
  pr.assign(n, -1);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0, -1, 0);
  for (int v = 0; v < n; ++v) if (h[v] >= l - 1) {
    int cur = v;
    cout << "PATH\n" << h[v] + 1 << '\n';
    while (cur >= 0) {
      cout << cur + 1 << ' ';
      cur = pr[cur];
    }
    cout << endl;
    return 0;
  }
  cout << "CYCLES\n";
  int cnt = 0;
  for (int v = 0; cnt < k && v < n; ++v) {
    bool leaf = true;
    for (int nv : g[v]) if (h[nv] > h[v]) {
      leaf = false;
      break;
    }
    if (!leaf) continue;
    ++cnt;
    vi res(1, v);
    vi p;
    for (int nv : g[v]) if (nv != pr[v] && p.size() < 2) {
      p.push_back(nv);
    }
    assert(p.size() == 2);
    if ((h[v] - h[p[1]]) % 3 != 2) swap(p[0], p[1]);
    int cur = v;
    if ((h[v] - h[p[0]]) % 3 == 2) {
      if (h[p[0]] > h[p[1]]) swap(p[0], p[1]);
      res.push_back(p[1]);
      cur = p[1];
    }
    while (cur != p[0]) {
      res.push_back(pr[cur]);
      cur = pr[cur];
    }
    cout << res.size() << '\n';
    for (int v : res) cout << v + 1 << ' ';
    cout << '\n';
  }
  return 0;
}