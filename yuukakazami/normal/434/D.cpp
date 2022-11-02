#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int INF = ~0U >> 1;

template<class Flow>
struct Maxflow {
	static const Flow INF = ~0U >> 1; //should change with type
//	static const Flow INF = numeric_limits<Flow>::max();
	struct Edge {
		int t;
		Flow c;
		Edge*n, *r;
		Edge(int _t, Flow _c, Edge*_n) :
				t(_t), c(_c), n(_n) {
		}
	};
	vector<Edge*> E;

	int addV() {
		E.push_back((Edge*) 0);
		return E.size() - 1;
	}

	void clear() {
		E.clear();
	}

	Edge* makeEdge(int s, int t, Flow c) {
		return E[s] = new Edge(t, c, E[s]);
	}

	void addEdge(int s, int t, Flow c) {
		Edge*e1 = makeEdge(s, t, c), *e2 = makeEdge(t, s, 0);
		e1->r = e2, e2->r = e1;
	}

	int calcMaxFlow(int vs, int vt) {
		int nV = E.size();
		Flow totalFlow = 0;

		vector<Flow> am(nV, 0);
		vector<int> h(nV, 0), cnt(nV + 1, 0);
		vector<Edge*> prev(nV, (Edge*) 0), cur(nV, (Edge*) 0);
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
					Flow by = am[u];
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

	~Maxflow() {
		for (int i = 0; i < E.size(); ++i) {
			for (Edge*e = E[i]; e;) {
				Edge*ne = e->n;
				delete e;
				e = ne;
			}
		}
	}
};

Maxflow<int> net;
int n, m;
const int MAX_N = 50 + 1, MAX_M = 100 + 1;
int a[MAX_N], b[MAX_N], c[MAX_N];

const int BIG = int(3e5);
const int MX = 110;

vector<int> id[MAX_N];
int l[MAX_M], r[MAX_M];
int vs, vt;

int eval(int i, int x) {
	return (a[i] * x + b[i]) * x + c[i];
}

int get(int u, int i) {
	if (i < -MX || i > MX)
		return -1;
	return id[u][i + MX];
}

void addEdge(int u, int i, int v, int j) {
	int x = get(u, i), y = get(v, j);
	if (x == -1 || y == -1)
		return;
	net.addEdge(x, y, INF);
}

void constraint(int u, int v, int d) {
	//X_u \ge X_v +d
	for (int i = -MX; i <= MX; ++i) {
		addEdge(v, i, u, i + d);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i] >> c[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> l[i] >> r[i];
	}
	vs = net.addV(), vt = net.addV();
	for (int me = 0; me < n; ++me) {
		int tot = MX * 2 + 2; //[-100,100]

		vector<int>&v = id[me];
		for (int j = 0; j < tot; ++j) {
			v.push_back(net.addV());
		}
		net.addEdge(vs, v[0], INF);
		for (int i = -MX; i <= MX; ++i) {
			if (i >= l[me] && i <= r[me])
				net.addEdge(v[i + MX], v[i + MX + 1], BIG - eval(me, i));
			else
				net.addEdge(v[i + MX], v[i + MX + 1], INF);
		}
		net.addEdge(v.back(), vt, INF);
	}
	while (m--) {
		int u, v, d;
		cin >> u >> v >> d;
		--u, --v;
		constraint(v, u, -d);
	}
	int ans = BIG * n - net.calcMaxFlow(vs, vt);
	cout << ans << endl;
}