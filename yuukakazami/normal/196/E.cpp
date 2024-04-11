/*
 * e.cpp
 *
 *  Created on: 2012-6-12
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <queue>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

const int MAX_N = int(1e5) + 10;

typedef long long int64;

struct Edge {
	int t, c;
	Edge(int _t, int _c) :
			t(_t), c(_c) {
	}
};

struct WE {
	int a, b;
	int64 c;
	WE(int _a, int _b, int64 _c) :
			a(_a), b(_b), c(_c) {
	}
	bool operator<(const WE&o) const {
		return c < o.c;
	}
};

vector<Edge> E[MAX_N];

void addE(int a, int b, int c) {
	E[a].push_back(Edge(b, c));
	E[b].push_back(Edge(a, c));
}

int n, m;

const int64 INF = LONG_LONG_MAX / 4;

int from[MAX_N];

int64 distS[MAX_N], distP[MAX_N];

bool used[MAX_N];

void dijstra(vector<int> src, int64 dist[]) {
	priority_queue<pair<int, int> > pque;

	fill(dist, dist + n, INF);
	memset(used, 0, sizeof used);

	for (vector<int>::iterator e = src.begin(); e != src.end(); ++e) {
		dist[*e] = 0;
		from[*e] = *e;
		pque.push(make_pair(-dist[*e], *e));
	}

	while (!pque.empty()) {
		int u = pque.top().second;
		pque.pop();
		if (used[u])
			continue;
		used[u] = true;

		for (vector<Edge>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
			int64 nd = dist[u] + e->c;
			if (nd < dist[e->t]) {
				dist[e->t] = nd;
				from[e->t] = from[u];
				pque.push(make_pair(-dist[e->t], e->t));
			}
		}
	}
}

vector<int> ps;

int FA[MAX_N];

int fd(int x) {
	return FA[x] == x ? x : FA[x] = fd(FA[x]);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		--a, --b;
		addE(a, b, c);
	}

	int k;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		int x;
		scanf("%d", &x);
		--x;
		ps.push_back(x);
	}

	vector<int> S;
	S.push_back(0);

	dijstra(S, distS);

	dijstra(ps, distP);

	for (int i = 0; i < n; ++i) {
		FA[i] = i;
	}

	int64 ans = INF;
	for (vector<int>::iterator e = ps.begin(); e != ps.end(); ++e) {
		ans = min(ans, distS[*e]);
	}

	vector<WE> wes;

	for (int i = 0; i < n; ++i) {
		for (vector<Edge>::iterator e = E[i].begin(); e != E[i].end(); ++e) {
			if (i < e->t) {
				if (from[i] != from[e->t]) {
					wes.push_back(WE(from[i], from[e->t], e->c + distP[i] + distP[e->t]));
				}
			}
		}
	}

	sort(wes.begin(), wes.end());

	for (vector<WE>::iterator e = wes.begin(); e != wes.end(); ++e) {
		int a = e->a, b = e->b;
		a = fd(a), b = fd(b);
		if (a != b) {
			ans += e->c;
			FA[a] = b;
		}
	}

	cout << ans << endl;

	return 0;
}