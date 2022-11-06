#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
class Tree {
public:
	Tree(int V, int root) : V(V), root(root), cnum(V), place(V), id(V) {
		T.resize(V);
		for (int i = 0; i < MAXLOGV; i++) {
			parent[i].resize(V);
		}
		depth.resize(V);
	}
	// uv
	// lca
	void unite(int u, int v) {
		T[u].push_back(v);
		T[v].push_back(u);
	}
	// init
	// lca
	void init() {
		dfs(root, 0, 0);
		int id = 0;
		getid(root, 0, id);
	}
	// uvlca
	int lca(int u, int v) const {
		if (depth[u] > depth[v]) swap(u, v);
		for (int k = 0; k < MAXLOGV; k++) {
			if ((depth[v] - depth[u]) >> k & 1) {
				v = parent[k][v];
			}
		}
		if (u == v) return u;
		for (int k = MAXLOGV - 1; k >= 0; k--) {
			if (parent[k][u] != parent[k][v]) {
				u = parent[k][u];
				v = parent[k][v];
			}
		}
		return parent[0][u];
	}
	// uv
	// edge
	int dist(int u, int v) const {
		int p = lca(u, v);
		return (depth[u] - depth[p]) + (depth[v] - depth[p]);
	}
	int dfs(int v, int p, int d) {
		parent[0][v] = p;
		depth[v] = d;
		cnum[v] = 0;
		for (int i = 1; i < MAXLOGV; i++) {
			parent[i][v] = parent[i - 1][parent[i - 1][v]];
		}
		for (int next : T[v]) {
			if (next != p) cnum[v] += dfs(next, v, d + 1);
		}
		return cnum[v] + 1;
	}

	void getid(const int v, const int p, int &nplace) {
		place[v] = nplace;
		id[nplace] = v;
		nplace++;
		for (int next : T[v]) {
			if (next != p) getid(next, v, nplace);
		}
	}
	static const int MAXLOGV = 25;
	// 
	vector<vector<int> > T;
	// 
	int V;
	// 
	int root;

	// 
	vector<int> parent[MAXLOGV];
	// 
	vector<int> depth;

	//
	vector<int>cnum;

	//
	vector<int>place;
	vector<int>id;

};


int main() {
	int N, Q; cin >> N >> Q;
	Tree t(N,0);
	for (int i = 0; i < N - 1; ++i) {
		int a; cin >> a;
		t.unite(i + 1, a - 1);
	}
	t.init();
	while (Q--) {
		int a, b, c; cin >> a >> b >> c;
		a--; b--; c--;
		int ab(t.lca(a, b)), bc(t.lca(b, c)), ca(t.lca(c, a));

		int k = -1;
		int dab(t.depth[ab]), dbc(t.depth[bc]), dca(t.depth[ca]);
		if (dab >= dbc&&dab >= dca)k = ab;
		else if (dbc >= dca&&dbc >= dab)k = bc;
		else if (dca >= dab&&dca >= dbc)k = ca;
		if (k == -1)assert(false);
		auto av = vector<int>{
			t.dist(k, a), t.dist(k, b), t.dist(k, c)
		};
		int ans = *max_element(av.begin(), av.end());
		cout << ans+1 << endl;
	}
	return 0;
}