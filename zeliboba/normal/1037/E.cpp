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

vi q, added;
vector<set<int>> g;
int k, alive;

void rem() {
  while (!q.empty()) {
    int v = q.back();
    q.pop_back();
    --alive;
    for (int nv : g[v]) if (!added[nv]) {
      g[nv].erase(v);
      if (g[nv].size() < k) {
        added[nv] = 1;
        q.push_back(nv);
      }
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m;
  cin >> n >> m >> k;
  vii e(m);
  g.resize(n);
  added.assign(n, 0);
  for (int i = 0; i < m; ++i) {
    cin >> e[i].first >> e[i].second;
    --e[i].first;
    --e[i].second;
    g[e[i].first].insert(e[i].second);
    g[e[i].second].insert(e[i].first);
  }
  alive = n;
  for (int i = 0; i < n; ++i) if (g[i].size() < k) {
    q.push_back(i);
    added[i] = 1;
  }
  vi res(m);
  for (int i = m-1; i >= 0; --i) {
    rem();
    res[i] = alive;
    int a = e[i].first, b = e[i].second;
    g[a].erase(b);
    g[b].erase(a);
    for (int v : {a, b}) {
      if (!added[v] && g[v].size() < k) {
        q.push_back(v);
        added[v] = 1;
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    cout << res[i] << '\n';
  }
  return 0;
}