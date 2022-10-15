#include <cstdio>
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
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

vvi gr;
int T = 1;
vi was;

void dfs(int v) {
  if (was[v]) return;
  was[v] = T++;
  for (auto nv : gr[v]) dfs(nv);
  was[v] = T++;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  gr.resize(n);
  vii e(m);
  for (int i = 0; i < m; ++i) {
    int a,b;
    scanf("%d%d", &a, &b);
    --a; --b;
    gr[a].push_back(b);
    e[i] = pii(a, b);
  }
  was.assign(n, 0);
  for (int i = 0; i < n; ++i) dfs(i);
  vii ts(n);
  for (int i = 0; i < n; ++i) {
    ts[i] = pii(was[i], i);
  }
  sort(ts.rbegin(), ts.rend());
  vi ord(n);
  for (int i = 0; i < n; ++i) {
    ord[ts[i].second] = i;
  }
  int res = -1, cnt = 0;
  for (int i = 0; i < m; ++i) {
    int pos = ord[e[i].first];
    if (pos + 1 < n && ts[pos+1].second == e[i].second) ++cnt;
    if (cnt == n-1) {
      res = i + 1;
      break;
    }
  }
  cout << res << endl;
  return 0;
}