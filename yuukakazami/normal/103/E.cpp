/*
 * e.cpp
 *
 *  Created on: 2011-8-7
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
const int MAX_N = 300 + 10;
bool has[MAX_N][MAX_N];
int linkL[MAX_N], linkR[MAX_N], n, w[MAX_N];
bool vis[MAX_N];
bool dfs(int u) {
	if (vis[u])
		return false;
	vis[u] = true;
	for (int v = 0; v < n; ++v) {
		if (has[u][v] && (linkR[v] == -1 || dfs(linkR[v])))
			return linkL[u] = v, linkR[v] = u, true;
	}
	return false;
}

struct Maxflow {
	struct Edge {
		int t, c;
		Edge*n, *r;
		Edge(int _t, int _c, Edge*_n) :
				t(_t), c(_c), n(_n) {
		}
	};
	vector<Edge*> E;

	int addV() {
		E.push_back(NULL);
		return E.size() - 1;
	}

	void clear() {
		E.clear();
	}

	Edge* makeEdge(int s, int t, int c) {
		return E[s] = new Edge(t, c, E[s]);
	}

	void addEdge(int s, int t, int c) {
		Edge*e1 = makeEdge(s, t, c), *e2 = makeEdge(t, s, 0);
		e1->r = e2, e2->r = e1;
	}

	int calcMaxFlow(int vs, int vt, int INF = ~0U >> 2) {
		int nV = E.size();
		int totalFlow = 0;

		vector<int> am(nV, 0), h(nV, 0), cnt(nV + 1, 0);
		vector<Edge*> prev(nV, (Edge*) (0)), cur(nV, (Edge*) (0));
		cnt[0] = nV;

		int u = vs;
		Edge*e;
		am[u] = INF;
		while (h[vs] < nV) {
			for (e = cur[u]; e; e = e->n)
				if (e->c > 0 && h[u] == h[e->t] + 1)
					break;
			if (e) {
				int v = e->t;
				cur[u] = prev[v] = e;
				am[v] = min(am[u], e->c);
				u = v;
				if (u == vt) {
					int by = am[u];
					while (u != vs) {
						prev[u]->c -= by;
						prev[u]->r->c += by;
						u = prev[u]->r->t;
					}
					totalFlow += by;
					am[u] = INF;
				}
			} else {
				if (!--cnt[h[u]])
					break;
				h[u] = nV;
				for (e = E[u]; e; e = e->n)
					if (e->c > 0 && h[e->t] + 1 < h[u]) {
						h[u] = h[e->t] + 1;
						cur[u] = e;
					}
				++cnt[h[u]];
				if (u != vs)
					u = prev[u]->r->t;
			}
		}

		return totalFlow;
	}
};

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int c;
		cin >> c;
		for (int j = 0; j < c; ++j) {
			int x;
			cin >> x;
			has[i][--x] = true;
		}
	}
	for (int i = 0; i < n; ++i) {
		cin >> w[i];
	}
	memset(linkL, -1, sizeof linkL);
	memset(linkR, -1, sizeof linkR);
	for (int i = 0; i < n; ++i) {
		memset(vis, false, sizeof vis);
		if (!dfs(i)) {
			cout << "OH NO!" << endl;
			return 0;
		}
	}
	Maxflow sol;
	for (int i = 0; i < n; ++i) {
		sol.addV();
	}
	int vs = sol.addV(), vt = sol.addV();
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		w[i] = -w[i];
		if (w[i] >= 0) {
			ans += w[i];
			sol.addEdge(vs, i, w[i]);
		} else {
			sol.addEdge(i, vt, -w[i]);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (has[i][j]) {
				sol.addEdge(i, linkR[j], INT_MAX);
			}
		}
	}
	cout << sol.calcMaxFlow(vs, vt, INT_MAX) - ans << endl;
	return 0;
}