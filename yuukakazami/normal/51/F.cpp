#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
const int MAX_N = 2000 + 10, INF = ~0U >> 3;
//first we should merge every cycle!
//run a 2-connected-component algorithm :)
vector<int> E[MAX_N];
int n, m;

bool vis[MAX_N];
int low[MAX_N], ord[MAX_N], pt = 0;
int stack[MAX_N], top = 0;
int nId;
int id[MAX_N];

void dfs(int u, int par) {
	vis[u] = true;
	low[u] = ord[u] = pt++;
	stack[top++] = u;
	for (vector<int>::iterator e = E[u].begin(); e != E[u].end(); ++e)
		if (*e != par) {
			if (!vis[*e]) {
				dfs(*e, u);
				low[u] = min(low[u], low[*e]);
			} else {
				low[u] = min(low[u], ord[*e]);
			}
		}
	if (par == -1 || low[u] == ord[u]) {
		while (top > 0) {
			int v = stack[--top];
			id[v] = nId;
			if (v == u)
				break;
		}
		nId++;
	}
}

int ans;

void merge() {
	for (int i = 0; i < n; ++i) {
		if (!vis[i])
			dfs(i, -1);
	}
	static vector<int> tmp[MAX_N];
	for (int i = 0; i < n; ++i) {
		for (vector<int>::iterator e = E[i].begin(); e != E[i].end(); ++e) {
			if (id[i] < id[*e]) {
				int u = id[i], v = id[*e];
				tmp[u].push_back(v);
				tmp[v].push_back(u);
			}
		}
	}
	ans = n - nId;
	n = nId;
	for (int i = 0; i < n; ++i) {
		E[i] = tmp[i];
	}
}

int d[MAX_N];
int dia;

int cnt;
pair<int, int> memo[MAX_N][MAX_N];
bool save[MAX_N][MAX_N];
pair<int, int> calc(int u, int par) {
	pair<int, int>&ret = memo[u][par + 1];
	if (save[u][par + 1])
		return ret;
	save[u][par + 1] = true;
	int ans = 0, size = 1;
	for (vector<int>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
		if (*e != par) {
			pair<int, int> t = calc(*e, u);
			ans += min(t.second - 1, 1 + t.first);
			size += t.second;
		}
	}
	return ret = make_pair(ans, size);
}

vector<int> vs;
void dfs3(int u, int par) {
	vs.push_back(u);
	vis[u] = true;
	for (vector<int>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
		if (*e != par)
			dfs3(*e, u);
	}
}

int mi;
void dfs2(int u, int par, int p) {
	//end here
	int tmp = p + calc(u, par).first;
//	if (tmp == 0) {
//		cout << u << " " << par << endl;
//	}
	mi = min(mi, tmp);

	int total = 0;
	for (vector<int>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
		if (*e != par) {
			pair<int, int> ret = calc(*e, u);
			total += min(ret.first + 1, ret.second - 1);
		}
	}

	for (vector<int>::iterator e = E[u].begin(); e != E[u].end(); ++e)
		if (*e != par) {
			pair<int, int> ret = calc(*e, u);
			total -= min(ret.first + 1, ret.second - 1);
			dfs2(*e, u, p + total);
			total += min(ret.first + 1, ret.second - 1);
		}
}

void work() {

	for (int i = 0; i < n; ++i) {
		d[i] = E[i].size() - 1;
	}
	memset(vis, 0, sizeof vis);
	int nComp = 0;
	for (int i = 0; i < n; ++i)
		if (!vis[i]) {
			vs.clear();
			dfs3(i, -1);
			mi = INF;
			for (vector<int>::iterator e = vs.begin(); e != vs.end(); ++e) {
				dfs2(*e, -1, 0);
			}
			ans += mi;
			++nComp;
		}
	ans += nComp - 1;
	cout << ans << endl;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		E[a].push_back(b), E[b].push_back(a);
	}
	merge();
//now every one is a tree!
	work();
	return 0;
}