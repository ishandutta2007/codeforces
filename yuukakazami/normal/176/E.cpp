/*
 * e.cpp
 *
 *  Created on: 2012-4-21
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <set>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

const int MAX_N = int(1e5) + 10;
int n, nQ;

typedef long long int64;

struct Edge {
	int t, c;
	Edge(int _t, int _c) :
			t(_t), c(_c) {
	}
};

vector<Edge> E[MAX_N];

const int MAX_LOG = 20;
int anc[MAX_N][MAX_LOG];
int dep[MAX_N];
int ord[MAX_N], pt, at[MAX_N];
int64 length[MAX_N];

void dfs(int u, int par, int d, int64 len) {
	dep[u] = d;
	length[u] = len;
	anc[u][0] = par;
	at[u] = pt;
	ord[pt++] = u;

	for (int i = 1; i < MAX_LOG; ++i) {
		int go = anc[u][i - 1];
		if (go == -1)
			anc[u][i] = -1;
		else
			anc[u][i] = anc[go][i - 1];
	}
	for (vector<Edge>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
		if (e->t != par)
			dfs(e->t, u, d + 1, len + e->c);
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

set<int> cur;
int64 ans;

void recalc() {
	if (cur.empty()) {
		ans = 0;
		return;
	}
	vector<int> a(cur.begin(), cur.end());
	a.push_back(a[0]);
	ans = 0;
	for (int i = 0; i + 1 < a.size(); ++i) {
		ans += length[ord[a[i]]];
		ans -= length[getLca(ord[a[i]], ord[a[i + 1]])];
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		--a, --b;
		E[a].push_back(Edge(b, c));
		E[b].push_back(Edge(a, c));
	}

	pt = 0;
	dfs(0, -1, 0, 0);

	ans = 0;
	cin >> nQ;
	for (int i = 0; i < nQ; ++i) {
		char cmd;
		scanf(" ");
		scanf("%c", &cmd);
		if (cmd == '?') {
			cout << ans << endl;
		} else if (cmd == '+') {
			int x;
			scanf("%d", &x), --x;
			if (cur.size() < 2) {
				cur.insert(at[x]);
				recalc();
			} else {
				set<int>::iterator it = cur.insert(at[x]).first, prev = it, next = it;
				if (prev == cur.begin())
					prev = --cur.end();
				else
					--prev;
				++next;
				if (next == cur.end())
					next = cur.begin();

				ans += length[getLca(ord[*prev], ord[*next])];
				ans -= length[getLca(ord[*prev], ord[*it])] + length[getLca(ord[*it], ord[*next])];
				ans += length[x];
			}
		} else {
			int x;
			scanf("%d", &x), --x;
			if (cur.size() < 3) {
				cur.erase(at[x]);
				recalc();
			} else {
				set<int>::iterator it = cur.find(at[x]), prev = it, next = it;
				if (prev == cur.begin())
					prev = --cur.end();
				else
					--prev;
				++next;
				if (next == cur.end())
					next = cur.begin();
				ans -= length[getLca(ord[*prev], ord[*next])];
				ans += length[getLca(ord[*prev], ord[*it])] + length[getLca(ord[*it], ord[*next])];
				ans -= length[x];
				cur.erase(it);
			}
		}
	}
	return 0;
}