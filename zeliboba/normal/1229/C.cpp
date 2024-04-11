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

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m;
  cin >> n >> m;
  vvi g(n);
//  vl c(n);
//  vi val(n);
  vvi bigger(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    if (a > b) swap(a, b);
    bigger[a].push_back(b);
//    ++c[b];
    g[a].push_back(b);
    g[b].push_back(a);
  }
  ll res = 0;
  vl deg(n);
  for (int i = 0; i < n; ++i) {
//    val[i] = i;
    deg[i] = g[i].size();
    res += bigger[i].size() * (deg[i] - bigger[i].size());
  }
  cout << res << '\n';
  int Q; cin >> Q;
  for (int q = 0; q < Q; ++q) {
    int v;
    cin >> v;
    --v;
    res -= bigger[v].size() * (deg[v] - bigger[v].size());
    for (int x : bigger[v]) {
      res -= bigger[x].size() * (deg[x] - bigger[x].size());
      bigger[x].push_back(v);
      res += bigger[x].size() * (deg[x] - bigger[x].size());
    }
    bigger[v].clear();
//    val[v] = q + n;
    cout << res << '\n';
  }
  return 0;
}