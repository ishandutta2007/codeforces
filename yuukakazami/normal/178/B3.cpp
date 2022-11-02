/*
 * b.cpp
 *
 *  Created on: 2012-4-28
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

const int MAX_N = int(1e5) + 10;
int n, m, nQ;

vector<int> E[MAX_N];
int ord[MAX_N], low[MAX_N];

const int MAX_LOG = 20;
int anc[MAX_N][MAX_LOG];
int dep[MAX_N];
int cnt[MAX_N];

int father[MAX_N];

int pt;
bool bad[MAX_N];

void dfs(int u, int par, int d, int c) {
	dep[u] = d;
	cnt[u] = c;
	anc[u][0] = par;
	for (int i = 1; i < MAX_LOG; ++i) {
		int go = anc[u][i - 1];
		if (go == -1)
			anc[u][i] = -1;
		else
			anc[u][i] = anc[go][i - 1];
	}
	for (vector<int>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
		if (father[*e] == u)
			dfs(*e, u, d + 1, c + bad[*e]);
	}
}

int getLca(int u, int v) {
	if (dep[u] < dep[v])
		swap(u, v);
	int need = dep[u] - dep[v];
	for (int i = MAX_LOG - 1; i >= 0; --i) {
		if (need >> i & 1)
			u = anc[u][i];
	}
	if (u == v)
		return u;
	for (int i = MAX_LOG - 1; i >= 0; --i) {
		int nu = anc[u][i], nv = anc[v][i];
		if (nu != nv)
			u = nu, v = nv;
	}
	return anc[u][0];
}

void dfs(int u, int par) {
	father[u] = par;
	low[u] = ord[u] = pt++;
	for (vector<int>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
		if (*e != par) {
			if (ord[*e] == -1) {
				dfs(*e, u);
				low[u] = min(low[u], low[*e]);
			} else {
				low[u] = min(low[u], ord[*e]);
			}
		}
	}
	if (low[u] >= ord[u]) {
		bad[u] = true;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		E[a].push_back(b), E[b].push_back(a);
	}
	pt = 0;
	memset(ord, -1, sizeof ord);
	memset(bad, 0, sizeof bad);
	dfs(0, -1);
	dfs(0, -1, 0, 0);
	cin >> nQ;
	for (int i = 0; i < nQ; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		int l = getLca(a, b);
		printf("%d\n", cnt[a] + cnt[b] - 2 * cnt[l]);
	}
	return 0;
}