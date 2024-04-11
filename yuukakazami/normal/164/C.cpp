/*
 * c.cpp
 *
 *  Created on: 2012-4-8
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

template<class Flow = int, class Cost = int>
struct MinCostFlow {
	struct Edge {
		int t;
		Flow f;
		Cost c;
		Edge*next, *rev;
		Edge(int _t, Flow _f, Cost _c, Edge*_next) :
				t(_t), f(_f), c(_c), next(_next) {
		}
	};

	vector<Edge*> E;

	int addV() {
		E.push_back((Edge*) 0);
		return E.size() - 1;
	}

	Edge* makeEdge(int s, int t, Flow f, Cost c) {
		return E[s] = new Edge(t, f, c, E[s]);
	}

	Edge* addEdge(int s, int t, Flow f, Cost c) {
		Edge*e1 = makeEdge(s, t, f, c), *e2 = makeEdge(t, s, 0, -c);
		e1->rev = e2, e2->rev = e1;
		return e1;
	}

	pair<Flow, Cost> minCostFlow(int vs, int vt) { //flow,cost
		int n = E.size();
		Flow flow = 0;
		Cost cost = 0;
		const Cost MAX_COST = INT_MAX;
		const Flow MAX_FLOW = INT_MAX;
		for (;;) {
			vector<Cost> dist(n, MAX_COST);
			vector<Flow> am(n, 0);
			vector<Edge*> prev(n);
			vector<bool> inQ(n, false);
			queue<int> que;

			dist[vs] = 0;
			am[vs] = MAX_FLOW;
			que.push(vs);
			inQ[vs] = true;

			while (!que.empty()) {
				int u = que.front();
				Cost c = dist[u];
				que.pop();
				inQ[u] = false;
				for (Edge*e = E[u]; e; e = e->next)
					if (e->f > 0) {
						Cost nc = c + e->c;
						if (nc < dist[e->t]) {
							dist[e->t] = nc;
							prev[e->t] = e;
							am[e->t] = min(am[u], e->f);
							if (!inQ[e->t]) {
								que.push(e->t);
								inQ[e->t] = true;
							}
						}
					}
			}

			if (dist[vt] == MAX_COST)
				break;

			if (dist[vt] >= 0)
				break;

			Flow by = am[vt];
			int u = vt;
			flow += by;
			cost += by * dist[vt];
			while (u != vs) {
				Edge*e = prev[u];
				e->f -= by;
				e->rev->f += by;
				u = e->rev->t;
			}
		}

		return make_pair(flow, cost);
	}
};

MinCostFlow<int, int> sol;

const int MAX_N = 1000 + 10;
int n, k;
MinCostFlow<int, int>::Edge* task[MAX_N];

template<class T>
struct Index: public vector<T> {
	using vector<T>::erase;
	using vector<T>::begin;
	using vector<T>::end;
	void doit() {
		sort(begin(), end());
		erase(unique(begin(), end()), end());
	}
	int get(T x) {
		return lower_bound(begin(), end(), x) - begin();
	}
};

Index<int> idx;

int l[MAX_N], r[MAX_N], cst[MAX_N];

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		cin >> l[i] >> r[i] >> cst[i];
		r[i] += l[i];
		idx.push_back(l[i]);
		idx.push_back(r[i]);
	}

	idx.doit();

	for (int i = 0; i < idx.size(); ++i) {
		sol.addV();
	}

	int S = sol.addV(), T = sol.addV();

	sol.addEdge(S, 0, k, 0);
	sol.addEdge(idx.size() - 1, T, k, 0);

	for (int i = 0; i + 1 < idx.size(); ++i) {
		sol.addEdge(i, i + 1, INT_MAX / 4, 0);
	}

	for (int i = 0; i < n; ++i) {
		int a = idx.get(l[i]);
		int b = idx.get(r[i]);
		task[i] = sol.addEdge(a, b, 1, -cst[i]);
	}

	pair<int, int> ans = sol.minCostFlow(S, T);

	for (int i = 0; i < n; ++i) {
		if (task[i]->f == 0)
			printf("1 ");
		else
			printf("0 ");
	}

	puts("");
	return 0;
}