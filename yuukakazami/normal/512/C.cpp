#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int MAX_N = 200 + 10;
const int MAX_V = int(1e5) + 10;

bool isP[MAX_V];

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

	pair<int, int> get(int vs, int vt, int u) {
		vector<int> have;

		for (Edge*e = E[u]; e; e = e->n)
			if (e->c == 0)
				have.push_back(e->t);

		return make_pair(have[0], have[1]);
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

vector<int> edge[MAX_N];
bool mark[MAX_N];
vector<int> cur;

void dfs(int u) {
	if (mark[u])
		return;
	mark[u] = true;
	cur.push_back(u);
	for (vector<int>::iterator e = edge[u].begin(); e != edge[u].end(); ++e) {
		dfs(*e);
	}
}

int main() {
	fill(isP, isP + MAX_V, true);

	for (int i = 2; i < MAX_V; ++i) {
		for (int j = i + i; j < MAX_V; j += i)
			isP[j] = false;
	}

	int n;
	cin >> n;
	vector<int> odd, even, oddi, eveni;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (x % 2 == 0)
			even.push_back(x), eveni.push_back(i + 1);
		else
			odd.push_back(x), oddi.push_back(i + 1);
	}

	if (odd.size() != even.size()) {
		puts("Impossible");
		return 0;
	}

	Maxflow<int> net;

	vector<int> vodd, veven;
	for (int i = 0; i < odd.size(); ++i) {
		vodd.push_back(net.addV());
	}
	for (int i = 0; i < even.size(); ++i) {
		veven.push_back(net.addV());
	}

	int vs = net.addV(), vt = net.addV();
	for (int i = 0; i < odd.size(); ++i) {
		net.addEdge(vs, vodd[i], 2);
		net.addEdge(veven[i], vt, 2);
	}

	for (int i = 0; i < odd.size(); ++i) {
		for (int j = 0; j < even.size(); ++j) {
			if (isP[odd[i] + even[j]])
				net.addEdge(vodd[i], veven[j], 1);
		}
	}

	int flow = net.calcMaxFlow(vs, vt);

	if (flow != n) {
		puts("Impossible");
		return 0;
	}

	for (int i = 0; i < vodd.size(); ++i) {
		pair<int, int> get = net.get(vs, vt, vodd[i]);
		edge[i].push_back(get.first);
		edge[i].push_back(get.second);
		edge[get.first].push_back(i);
		edge[get.second].push_back(i);
	}

	//build cycle
	vector<vector<int> > ans;
	for (int i = 0; i < n; ++i) {
		if (!mark[i]) {
			cur.clear();
			dfs(i);
			for (int j = 0; j < cur.size(); ++j) {
				if (cur[j] < n / 2)
					cur[j] = oddi[cur[j]];
				else
					cur[j] = eveni[cur[j] - n / 2];
			}
			ans.push_back(cur);
		}
	}

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i].size();
		for (int j = 0; j < ans[i].size(); ++j) {
			cout << " " << ans[i][j];
		}
		cout << endl;
	}

	return 0;
}