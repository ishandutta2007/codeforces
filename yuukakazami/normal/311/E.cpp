#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
const int MAX_N = int(1e4) + 10;
int n, m, g;
int sex[MAX_N], v[MAX_N];
typedef int Flow;

const Flow INF = ~0U >> 1; //should change with type
struct Maxflow {
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
		for (int i = 0; i < (int) E.size(); ++i) {
			for (Edge*e = E[i]; e;) {
				Edge*ne = e->n;
				delete e;
				e = ne;
			}
		}
	}
};
int vs, vt, dog[MAX_N], rich[MAX_N];
Maxflow net;

int main() {
	cin >> n >> m >> g;
	vs = net.addV(), vt = net.addV();
	for (int i = 0; i < n; ++i) {
		cin >> sex[i];
		dog[i] = net.addV();
	}
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	int tot = 0;
	//S->x :0  x->T :1
	for (int i = 0; i < n; ++i) {
		if (sex[i] == 0) {
			net.addEdge(vs, dog[i], v[i]);
		} else {
			net.addEdge(dog[i], vt, v[i]);
		}
	}
	for (int i = 0; i < m; ++i) {
		int req, w, k, is;
		scanf("%d%d%d", &req, &w, &k);
		int who[11];
		for (int j = 0; j < k; ++j) {
			scanf("%d", who + j);
			--who[j];
		}
		scanf("%d", &is);
		tot += w;
		if (is) {
			w += g;
		}
		rich[i] = net.addV();
		if (req == 1)
			net.addEdge(rich[i], vt, w);
		else
			net.addEdge(vs, rich[i], w);
		for (int j = 0; j < k; ++j) {
			int x = who[j];
//			net.addEdge(rich[i], dog[x], INF);
			if (req == 1)
				net.addEdge(dog[x], rich[i], INF);
			else
				net.addEdge(rich[i], dog[x], INF);
		}
	}
	cout << tot - net.calcMaxFlow(vs, vt) << endl;
	return 0;
}