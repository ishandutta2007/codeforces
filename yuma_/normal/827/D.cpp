#include "bits/stdc++.h"
using namespace std;

struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};
typedef  int Weight;
struct Edge {
	int src;
	int dst;
	Weight cost;
	int id;
};
class Compare {
public:
	bool operator()(const Edge&l, const Edge&r) {
		return l.cost > r.cost;
	}
};
typedef vector<vector<Edge>>Graph;
vector<int> mst(Graph&g,int num) {
	priority_queue<Edge,vector<Edge>,Compare>que;
	vector<int>v(num);
	for (auto es : g) {
		for (auto e : es) {
			que.push(e);
		}
	}
	UnionFind uf(g.size());
	while (!que.empty()) {
		auto atop(que.top());
		que.pop();
		if (uf.root(atop.src) != uf.root(atop.dst)) {
			v[atop.id] = true;
			uf.unionSet(atop.src, atop.dst);
		}
	}
	return v;
}
long long int INI = 0;
class Tree {
public:
	Tree(int V, int root) : V(V), root(root), cnum(V), place(V), id(V),
		T(V), parent(MAXLOGV, vector<int>(V)), depth(V), ws(MAXLOGV, vector<Weight>(V,1e9+2)) {
	}

	// init
	// lca
	void init() {
		dfs(root, 0, 0, 0, -1);
		int id = 0;
		getid(root, 0, id);
	}
	//uv
	// lca
	void unite(Edge&e) {
		T[e.src].push_back(Edge{ e.src, e.dst, e.cost, e.id });
		T[e.dst].push_back(Edge{ e.dst, e.src, e.cost, e.id });
	}
	Weight connect(const Weight&l, const  Weight&r)const {
		return max(l, r);
	}
	// uvlca
	pair<int,Weight> lca(int u, int v) const {
		if (depth[u] > depth[v]) swap(u, v);
		Weight ans = -10000;
		for (int k = 0; k < MAXLOGV; k++) {
			if ((depth[v] - depth[u]) >> k & 1) {
				ans = connect(ans, ws[k][v]);
				v = parent[k][v];

			}
		}
		if (u == v) return make_pair(u,ans);
		for (int k = MAXLOGV - 1; k >= 0; k--) {
			if (parent[k][u] != parent[k][v]) {
				ans = connect(ans, ws[k][u]);
				ans = connect(ans, ws[k][v]);
				u = parent[k][u];
				v = parent[k][v];
			}
		}
		ans = connect(ans, ws[0][u]);
		ans = connect(ans, ws[0][v]);
		return make_pair(parent[0][u],ans);
	}

	int dfs(int v, int p, int d, long long int w, int id) {
		parent[0][v] = p;
		ws[0][v] = w;
		depth[v] = d;
		cnum[v] = 0;
		for (int i = 1; i < MAXLOGV; i++) {
			parent[i][v] = parent[i - 1][parent[i - 1][v]];

			ws[i][v] = connect(ws[i - 1][v], ws[i - 1][parent[i - 1][v]]);
		}
		for (auto e : T[v]) {
			auto next = e.dst;
			if (next != p) cnum[v] += dfs(next, v, d + 1, e.cost, e.id);
		}
		return cnum[v] + 1;
	}

	void getid(const int v, const int p, int &nplace) {
		place[v] = nplace;
		id[nplace] = v;
		nplace++;
		for (auto e : T[v]) {
			const auto next = e.dst;
			if (next != p) getid(next, v, nplace);
		}
	}
	static const int MAXLOGV = 25;
	// 
	vector<vector<Edge> > T;
	// 
	int V;
	// 
	int root;

	// 
	vector<vector<int>>parent;
	// aa
	vector<vector<Weight>>ws;
	// 
	vector<int> depth;

	//
	vector<int>cnum;

	//
	vector<int>place;
	vector<int>id;
};

vector<vector<int>>adds, dels;
vector<int>anss;
void dfs(const Graph&g, const int now, const int from_id,multiset<int>&nms) {
	
	for (auto& e : g[now]) {
		if (e.id == from_id)continue;
		multiset<int>ams;
		dfs(g, e.dst, e.id,ams);
		if (nms.size()< ams.size())swap(nms, ams);
		for (auto am : ams)nms.emplace(am);
	}
	for (auto ad : adds[now])nms.emplace(ad);
	for (auto de : dels[now])nms.erase(nms.find(de));
	if(from_id!=-1)anss[from_id] = nms.empty() ? -1 : *nms.begin()-1;

}

int main() {
	int N, M; cin >> N >> M;
	anss.assign(M, -100);
	adds.resize(N); dels.resize(N);
	Graph g(N);
	vector<Edge>all_es;
	for (int i = 0; i < M; ++i) {
		int a, b,c; cin >> a >> b >> c;
		a--; b--;
		g[a].push_back(Edge{ a,b,c,i });
		g[b].push_back(Edge{ b,a,c ,i});
		all_es.emplace_back(Edge{ a,b,c,i });
	}
	auto v(mst(g, M));
	Tree t(N, 0);
	for (int i = 0; i < M; ++i) {
		if (v[i])t.unite(all_es[i]);
	}
	t.init();
	for (int i = 0; i < M; ++i) {
		if (v[i])continue;
		auto alca = t.lca(all_es[i].src, all_es[i].dst);
		adds[all_es[i].src].push_back(all_es[i].cost);
		adds[all_es[i].dst].push_back(all_es[i].cost);

		dels[alca.first].push_back(all_es[i].cost);
		dels[alca.first].push_back(all_es[i].cost);
		anss[i] = alca.second-1;
	}
	multiset<int>ms;
	dfs(t.T, 0, -1, ms);
	for (int i = 0; i < M; ++i) {
		cout << anss[i];
		if (i == M - 1)cout << endl;
		else cout << " ";
	}
	return 0;
}