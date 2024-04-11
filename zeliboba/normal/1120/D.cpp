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
vl c, res;
vii d;
const int N = 1 << 18;
int ok[N];
int link[N];

void rm(int v) {
  if (v < 0 || !ok[v]) return;
  ok[v] = 0;
  rm(link[v]);
}

void dfs0(int v, int p) {
  link[v] = -1;
  bool leaf = true;
  res[v] = 0;
  d[v] = pii(-1, -1);
  int cnt = 0;
  for (int nv : g[v]) if (nv != p) {
    dfs0(nv, v);
    res[v] += res[nv];
    leaf = false;
    if (d[nv].first == d[v].first) ++cnt;
    if (d[nv].first > d[v].first) cnt = 1;
    d[v] = max(d[v], d[nv]);
  }
  if (leaf) {
    ok[v] = 1;
    res[v] = c[v];
    d[v] = pii(c[v], v);
  } else {
    if (c[v] < d[v].first) {
      res[v] += c[v] - d[v].first;
      if (d[v].second >= 0 && cnt == 1) {
        rm(d[v].second);
      }
      d[v] = pii(c[v], v);
      ok[v] = 1;
    } else if (c[v] > d[v].first) {
      if (cnt > 1) d[v].second = -1;
    } else {
      ok[v] = 1;
      if (cnt == 1) {
        link[v] = d[v].second;
      }
      d[v].second = v;
    }
  }
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  c.resize(n);
  d.resize(n);
  res.assign(n, 0);
  g.resize(n);
  for (int i = 0; i < n; ++i) cin >> c[i];
  for (int i = 0; i < n-1; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs0(0, -1);
  vi ans;
  for (int i = 0; i < N; ++i) if (ok[i]) {
    ans.push_back(i + 1);
  }
  cout << res[0] << ' ' << ans.size() << endl;
  sort(ans.begin(), ans.end());
  for (int x : ans) cout << x << ' ';
  return 0;
}