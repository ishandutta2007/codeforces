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

vector < vector<int> > g, gr;
vector<char> used;
vector<int> order, component;
 
void dfs1 (int v) {
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i)
		if (!used[ g[v][i] ])
			dfs1 (g[v][i]);
	order.push_back (v);
}
 
void dfs2 (int v) {
	used[v] = true;
	component.push_back (v);
	for (size_t i=0; i<gr[v].size(); ++i)
		if (!used[ gr[v][i] ])
			dfs2 (gr[v][i]);
}

int D;

void dfs(int v, int curind, int tocol, const vi& ind, vi& col) {
  if (col[v] != -1 || ind[v] != curind) return;
  col[v] = tocol;
  for (int nv : g[v]) {
    dfs(nv, curind, (tocol + 1) % D, ind, col);
  }
}
 
int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
	int n, m;
	cin >> n >> m >> D;
  vvi sch(n, vi(D));
  g.resize(n);
  gr.resize(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
    cin >> a >> b;
    --a; --b;
		g[a].push_back (b);
		gr[b].push_back (a);
	}
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < D; ++j) sch[i][j] = s[j] == '1';
  }
 
	used.assign (n, false);
	for (int i=0; i<n; ++i)
		if (!used[i])
			dfs1 (i);
	used.assign (n, false);
  vvi comps;
  vi ind(n);
	for (int i=0; i<n; ++i) {
		int v = order[n-1-i];
		if (!used[v]) {
			dfs2 (v);
      for (int x : component) {
        ind[x] = comps.size();
      }
      comps.push_back(component);
			component.clear();
		}
	}
  vi col(n, -1);
  vvi d(n, vi(D));
  for (int t = comps.size() - 1; t >= 0; --t) {
    dfs(comps[t][0], t, 0, ind, col);
    int curd = D;
    for (int v : comps[t]) {
      assert(col[v] >= 0 && ind[v] == t);
      for (int nv : g[v]) {
        assert(ind[nv] >= ind[v]);
        if (ind[v] == ind[nv]) {
          curd = __gcd(curd, abs(col[nv] - col[v] - 1));
        }
      }
    }
//    cerr << "curd: " << curd << endl;
    for (int v : comps[t]) {
      col[v] %= curd;
      for (int i = 0; i < curd; ++i) {
        for (int j = i; j < D; j += curd) {
          sch[v][i] |= sch[v][j];
        }
      }
//      cerr << v << ' ' << sch[v][0] << endl;
    }
    vi res(curd);
    for (int i = 0; i < curd; ++i) {
      int ma = 0, sum = 0;
      for (int v : comps[t]) {
        sum += sch[v][(i + col[v]) % curd];
        for (int nv : g[v]) if (ind[nv] > ind[v]) {
          for (int t1 = (i + col[v] + 1) % curd; t1 < D; t1 += curd) {
            ma = max(ma, d[nv][t1]);
          }
        }
      }
      res[i] = ma + sum;
    }
    for (int v : comps[t]) {
      for (int i = 0; i < D; ++i) {
        d[v][i] = res[(i + curd - col[v]) % curd];
      }
    }
  }
  cout << d[0][0] << endl;
  return 0;
}