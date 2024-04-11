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

vi h, mh;
vl d;
vvi g;

void dfs(int v, int p) {
  int sech = 0;
  for (int nv : g[v]) if (nv != p) {
    dfs(nv, v);
    d[v] += d[nv];
    if (mh[v] > mh[nv]) sech = max(sech, mh[nv]);
    else sech = mh[v];
    mh[v] = max(mh[v], mh[nv]);
  }
  if (p != -1) {
    if (h[v] > mh[v]) {
      d[v] += h[v] - mh[v];
    }
  } else {
//    ll res0 = h[v] + d[v];
    ll res1 = d[v] + 2 * h[v] - mh[v] - sech; 
    d[v] = res1;
  }
  mh[v] = max(mh[v], h[v]);
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T = 1;
  for (int test = 1; test <= T; ++test) {
    int n;
    cin >> n;
    mh.assign(n, 0);
    d.assign(n, 0);
    h.resize(n);
    g.resize(n);
    pii ma(-1, -1);
    for (int i = 0; i < n; ++i) {
      cin >> h[i];
      ma = max(ma, pii(h[i], i));
    }
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a; --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    dfs(ma.second, -1);
    cout << d[ma.second] << '\n';
  }
  return 0;
}