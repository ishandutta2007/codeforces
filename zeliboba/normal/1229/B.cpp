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
typedef pair<ll, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
const int mod = 1e9 + 7;

vl x;
ll res = 0;
vvi g;
vector<vii> gs;

ll gcd(ll a, ll b) {
  if (a == 0 || b == 0) return a + b;
  return __gcd(a, b);
}

void upd(vii& v) {
  sort(v.begin(), v.end());
  vii nv(1, v[0]);
  for (int i = 1; i < v.size(); ++i) {
    if (v[i].first == nv.back().first) nv.back().second += v[i].second;
    else nv.push_back(v[i]);
  }
  v.swap(nv);
}

void dfs(int v, int p) {
  gs[v].emplace_back(x[v], 1);
  if (p != -1) {
    for (auto t : gs[p]) {
      gs[v].emplace_back(gcd(t.first, x[v]), t.second);
    }
  }
  upd(gs[v]);
  for (auto p : gs[v]) {
    res = (res + p.second * p.first) % mod;
  }
  for (int nv : g[v]) if (nv != p) {
    dfs(nv, v);
  }
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  g.resize(n);
  x.resize(n);
  gs.resize(n);
  for (int i = 0; i < n; ++i) cin >> x[i];
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0, -1);
  cout << res << endl;
  return 0;
}