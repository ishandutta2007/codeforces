

#include "bits/stdc++.h"
using namespace std;
using ld= long double;
struct Edge {
	int id;
	int src, dest;
	int  rev;
	ld t;
};
typedef  vector<vector<Edge>> Graph;

void add_edge(Graph &g, int id,int src, int dest) {
	g[src].push_back(Edge{ id,src, dest, (int)g[dest].size(),-2 });
	g[dest].push_back(Edge{ id,dest, src, (int)g[src].size() - 1,-2  });
}
void set_t(Graph&g, int src, int index, ld at) {
	g[src][index].t = at;
	int dest = g[src][index].dest;
	ld nextat = at+1.0l;
	if (nextat >= 2)nextat -= 2;
	g[dest][g[src][index].rev].t = nextat;
}
void dfs(Graph&g,const int now,const int from) {
	ld nextt = g[now][from].t;
	nextt += 2.0l/g[now].size();
	if (nextt >= 2)nextt -= 2;
	for (int i = 0; i < g[now].size(); ++i) {
		if (i != from) {
			set_t(g, now, i, nextt);
			dfs(g, g[now][i].dest, g[now][i].rev);

			nextt += 2.0l / g[now].size();
			if (nextt >= 2)nextt -= 2;
		}
	}
}
struct aa {
	int len;
	int edgeid;
	int u;
	int v;
	ld x;
};
void output(Graph&g) {
	cout << g.size() - 1 << endl;
	vector<aa>aas;
	for (auto es : g) {
		for (auto e : es) {
			if (e.src < e.dest) {
				if (e.t < -1)assert(false);
				if (e.t >= 1) {
					aas.push_back(aa{ 1,e.id,e.dest,e.src,e.t - 1.0 });
				}
				else {
					aas.push_back(aa{ 1,e.id,e.src,e.dest,e.t });
				
				}
			}
		}
	}
	sort(aas.begin(), aas.end(), [](const aa&l, const aa&r) {
		return l.edgeid < r.edgeid;
	});
	for (auto a : aas) {
		cout << a.len << " " << a.edgeid + 1 << " " << a.u+1 << " " << a.v+1 << " " << setprecision(10) << fixed << a.x << endl;
	}
}
int main() {
	int N; cin >> N;
	Graph g(N);
	for (int i = 0; i < N-1; ++i) {
		int a, b; cin >> a >> b; a--; b--;
		add_edge(g,i, a, b);
	}
	set_t(g, 0, 0, 0.0);
	int adest = g[0][0].dest;
	dfs(g, 0, 0);
	dfs(g, g[0][0].dest, g[0][0].rev);
	output(g);
	return 0;
}