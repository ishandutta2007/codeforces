#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

//template<class Flow = int, class Cost = int>
typedef int Flow;
typedef int Cost;

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

	void addEdge(int s, int t, Flow f, Cost c) {
		Edge*e1 = makeEdge(s, t, f, c), *e2 = makeEdge(t, s, 0, -c);
		e1->rev = e2, e2->rev = e1;
	}

	pair<Flow, Cost> minCostFlow(int vs, int vt, bool maxFlow) { //flow,cost
		int n = E.size();
		Flow flow = 0;
		Cost cost = 0;
//		const Cost MAX_COST = numeric_limits<Cost>::max();
//		const Flow MAX_FLOW = numeric_limits<Flow>::max();
		const Cost MAX_COST = ~0U >> 1;
		const Flow MAX_FLOW = ~0U >> 1;
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

			if (maxFlow) {
				if (dist[vt] == MAX_COST)
					break;
			} else {
				if (dist[vt] >= 0)
					break;
			}

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

const int MAX_N = 100 + 10;
int n, m;
string how[MAX_N];
int A[MAX_N], B[MAX_N];
int ia[MAX_N], ib[MAX_N];

int notKillAll() {
	MinCostFlow net;
	int vs = net.addV(), vt = net.addV();
	for (int i = 0; i < n; ++i) {
		ia[i] = net.addV();
		net.addEdge(vs, ia[i], 1, 0);
	}
	for (int i = 0; i < m; ++i) {
		ib[i] = net.addV();
		net.addEdge(ib[i], vt, 1, 0);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			//j attack i
			if (B[j] > A[i] && how[i] == "ATK") {
				net.addEdge(ia[i], ib[j], 1, -(B[j] - A[i]));
			}
		}
	}
	return -net.minCostFlow(vs, vt, false).second;
}

int killAll() {
	MinCostFlow net;
	int vs = net.addV(), vt = net.addV();
	//m>n!
	for (int i = 0; i < m; ++i) {
		ia[i] = net.addV();
		net.addEdge(vs, ia[i], 1, 0);
	}
	for (int i = 0; i < m; ++i) {
		ib[i] = net.addV();
		net.addEdge(ib[i], vt, 1, 0);
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			//j attack i
			if (i < n) {
				if (how[i] == "ATK") {
					if (B[j] >= A[i])
						net.addEdge(ia[i], ib[j], 1, -(B[j] - A[i]));
				} else {
					if (B[j] > A[i])
						net.addEdge(ia[i], ib[j], 1, 0);
				}
			} else {
				//directly attack
				net.addEdge(ia[i], ib[j], 1, -B[j]);
			}
		}
	}
	pair<int, int> ret = net.minCostFlow(vs, vt, true);
	if (ret.first == m)
		return -ret.second;
	return 0;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> how[i] >> A[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> B[i];
	}
	int ans = notKillAll();
	if (m > n)
		ans = max(ans, killAll());
	cout << ans << endl;
	return 0;
}