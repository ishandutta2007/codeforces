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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, k;
  cin >> n >> k;
  vvi g(n);
  vi deg(n), lvl(n, -1), added(n);
  for (int i = 0; i < n-1; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vi q;
  for (int i = 0; i < n; ++i) {
    deg[i] = g[i].size();
    if (deg[i] <= 1) {
      q.push_back(i);
      added[i] = 1;
    }
  }
  int it = 0;
  bool fail = 0;
  int ma = 0;
  while (it < q.size()) {
    int v = q[it++];
    int prlvl = -1;
    for (int nv : g[v]) {
      if (lvl[nv] != -1) {
        if (prlvl == -1) prlvl = lvl[nv];
        else if (prlvl != lvl[nv]) fail = 1;
      }
      --deg[nv];
      if (!added[nv] && deg[nv] <= 1) {
        q.push_back(nv);
        added[nv] = 1;
      }
    }
    if (it != n && g[v].size() < 4 && g[v].size() != 1) {
//      cerr << it << ' ' << v + 1 << ' ' << g[v].size() << endl;
      fail = 1;
    }
    ma = lvl[v] = prlvl + 1;
  }
  cerr << fail << ' ' << ma << ' ' << g[q.back()].size() << ' ' << q.size() << endl;
  if (fail || ma != k || g[q.back()].size() < 3 || q.size() != n) cout << "No\n";
  else cout << "Yes\n";
  return 0;
}