// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;

const int N = (int) 30005, mod = (int) 0;
vector<int> adj[N];
int sz[N], mark[N], cyc[N];
long long dp[N], dw_alone[N];
vector<int> c;
int dfs_find_cyc(int v, int p = -1) {
	if (mark[v]++) return v + 1;
	for (int u : adj[v]) if (u != p) {
		int marked_node = dfs_find_cyc(u, v);
		if (marked_node == -1) return -1;
		if (marked_node) {
			cyc[v] = 1;
			c.push_back(v);
			if (v + 1 == marked_node) return -1;
			return marked_node;
		}
	}
	return 0;
}
int n, par[N];
void dfs_down(int v, int p = -1) {
	sz[v] = 1;	
	par[v] = p;
	for (int u : adj[v]) if (u != p && !cyc[u]) {
		dfs_down(u, v);	
		sz[v] += sz[u];
		dw_alone[v] += dw_alone[u] + sz[u];
	}
}
int rev[N], sum[N];
int main() {
	cin >> n;
	for (int j = 0; j < n; ++j) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs_find_cyc(0);
	for (int cur : c) {
		dfs_down(cur);	
	}
	for (int j = 0; j < (int) c.size(); ++j) rev[c[j]] = j;
	int m = (int) c.size();
	for (int j = 0; j < m; ++j) c.push_back(c[j]);
	for (int j = 0; j < 2 * m; ++j) sum[j + 1] = sum[j] + sz[c[j]];
	for (int sz = 1; sz <= m - 1; ++sz) {
		if (sz == 1) {
			for (int j = 0; j < 2 * m; ++j)	{
				int cur = c[j];
				dp[j] = ::sz[cur] + dw_alone[cur];
			}
		} else {
			for (int j = 0; j + sz - 1 < 2 * m; ++j) {
				int sum_all = sum[j + sz] - sum[j];
				int nx = c[j + sz - 1];
				dp[j] = max(dp[j] + sum_all + dw_alone[nx], dp[j + 1] + sum_all + dw_alone[c[j]]);
			}
		}
	}
	long long res = 0;
	for (int stv = 0; stv < n; ++stv) {
		int v = stv;
		long long cur_res = 0, to_add = 0;
		while (par[v] != -1) {
			cur_res += n - to_add;
			cur_res -= sz[v];
			to_add = sz[v];
			v = par[v];
		}
		cur_res += dw_alone[v];
		cur_res += n - to_add;
		int pos = rev[v];
		cur_res += dp[pos + 1];
		res = max(res, cur_res);
	}
	cout << res << endl;
	
}