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

int d[100][100005];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m, k, s;
  cin >> n >> m >> k >> s;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
  }
  vvi g(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int c = 0; c < k; ++c) {
    vi q;
    for (int i = 0; i < n; ++i) {
      if (a[i] == c) {
        q.push_back(i);
      } else {
        d[c][i] = 1e9;
      }
    }
    int it = 0;
    while (it < (int)q.size()) {
      int v = q[it];
      int nd = d[c][v] + 1;
      for (int nv : g[v]) {
        if (d[c][nv] > nd) {
          d[c][nv] = nd;
          q.push_back(nv);
        }
      }
      ++it;
    }
  }
  for (int i = 0; i < n; ++i) {
    vi x(k);
    for (int j = 0; j < k; ++j) x[j] = d[j][i];
    sort(x.begin(), x.end());
    int sum = 0;
    for (int j = 0; j < s; ++j) sum += x[j];
    cout << sum << ' ';
  }
  cout << endl;
  return 0;
}