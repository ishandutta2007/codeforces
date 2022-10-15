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

vi p;
//vvi r;

int getp(int v) {
  if (p[v] == v) return v;
  return p[v] = getp(p[v]);
}

/*pii getp(int v) {
  if (p[v] == v) return pii(v, c[v]);
  auto res = getp(p[v]);
  p[v] = res.first;
  c[v] = max(c[v], res.second);
  return pii(p[v], c[v]);
}*/

vvi g;
ll res = 0;

bool join(int a, int b) {
  a = getp(a);
  b = getp(b);
  if (a == b) return false;
  if (rand() % 2) {
    swap(a, b);
  }
  p[a] = b;
  return true;
}

const int B = 19;
int lc[500005][19];
int mi[500005][19];
vi was, in, out;
const int MAX = 2e9;
int TIMER = 0;


void dfs(int v, int p) {
  if (was[v]) return;
  in[v] = TIMER++;
  was[v] = 1;
  lc[v][0] = p;
  for (int nv : g[v]) dfs(nv, v);
  out[v] = TIMER++;
}

bool isp(int a, int b) {
  return in[a] >= in[b] && out[a] <= out[b];
}

int lca(int a, int b) {
  if (isp(a, b)) return b;
  for (int i = B - 1; i >= 0; --i) {
    if (!isp(a, lc[b][i])) b = lc[b][i];
  }
  return lc[b][0];
}

void put(int a, int b, int w) {
//  cerr << a << ' ' << b << ' ' << w << endl;
  if (a == b) return;
  for (int i = B - 1; i >= 0; --i) {
    if (!isp(b, lc[a][i])) {
      mi[a][i] = min(mi[a][i], w);
      a = lc[a][i];
    }
  }
  mi[a][0] = min(mi[a][0], w);
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, k, m;
  cin >> n >> k >> m;
  p.resize(n);
  in.resize(n);
  out.resize(n);
  was.assign(n, 0);
  for (int i = 0; i < n; ++i) {
    p[i] = i;
  }
  vii e(k);
  g.resize(n);
  for (int i = 0; i < k; ++i) {
    cin >> e[i].first >> e[i].second;
    --e[i].first; --e[i].second;
    join(e[i].first, e[i].second);
    g[e[i].first].push_back(e[i].second);
    g[e[i].second].push_back(e[i].first);
  }
  vector<array<int, 3>> ts(m);
  for (int i = 0; i < m; ++i) {
    cin >> ts[i][1] >> ts[i][2] >> ts[i][0];
    --ts[i][1]; --ts[i][2];
  }
  sort(ts.begin(), ts.end());
  for (int i = 0; i < m; ++i) {
    if (join(ts[i][1], ts[i][2])) {
      g[ts[i][1]].push_back(ts[i][2]);
      g[ts[i][2]].push_back(ts[i][1]);
      res -= ts[i][0];
    }
  }
  for (int i = 0; i < n; ++i) {
    dfs(i, i);
  }
  for (int b = 1; b < B; ++b) {
    for (int i = 0; i < n; ++i) lc[i][b] = lc[lc[i][b-1]][b-1];
  }
  for (int b = B - 1; b >= 0; --b) {
    for (int i = 0; i < n; ++i) {
      mi[i][b] = MAX;
    }
  }
  for (int i = 0; i < m; ++i) {
    int a = ts[i][1], b = ts[i][2];
    if (getp(a) != getp(b)) continue;
    int c = lca(a, b);
    //cerr << a+1 << ' ' << b+1 << ' ' << c+1 << ' ' << ts[i][0] << endl;
    put(a, c, ts[i][0]);
    put(b, c, ts[i][0]);
  }
  /*for (int i = 0; i < n; ++i) {
    cerr << i + 1 << ' ' << lc[i][0] + 1 << ' ' << mi[i][0] << endl;
  }*/
  for (int b = B - 1; b > 0; --b) {
    for (int i = 0; i < n; ++i) {
      int p = lc[i][b-1];
      mi[i][b-1] = min(mi[i][b-1], mi[i][b]);
      mi[p][b-1] = min(mi[p][b-1], mi[i][b]);
    }
  }
  for (int i = 0; i < n; ++i) {
    //cerr << i + 1 << ' ' << lc[i][0] + 1 << ' ' << mi[i][0] << endl;
    if (lc[i][0] != i) {
      if (mi[i][0] == MAX) {
        cout << -1 << endl; return 0;
      }
      res += mi[i][0];
    }
  }
/*  sort(ts.begin(), ts.end());
  for (int i = 0; i < ts.size(); ++i) {
  }*/
  cout << res << endl;
  return 0;
}