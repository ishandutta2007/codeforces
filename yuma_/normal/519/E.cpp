#include "bits/stdc++.h"
#include<unordered_map>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;

static const int MAXLOGV = 25;
class Tree {
public:
	Tree(int V, int root) : V(V), root(root) {
		T.resize(V);
		for (int i = 0; i < MAXLOGV; i++) {
			parent[i].resize(V);
		}
		depth.resize(V);
		childnums.resize(V);
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
		int childnum = 1;
		for (int i = 1; i < MAXLOGV; i++) {
			parent[i][v] = parent[i - 1][parent[i - 1][v]];
		}
		for (int next : T[v]) {
			if (next != p) childnum+=dfs(next, v, d + 1);
		}
		return childnums[v] = childnum;
	}
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
	vector<int>childnums;
};

int main() {
	int N; cin >> N;
	Tree tree(N,0);
	for (int i = 0; i < N-1; ++i) {
		int a, b; cin >> a >> b;
		a--; b--;
		tree.unite(a, b);
	}
	tree.init();
	int Q; cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int a, b; cin >> a >> b;
		a--; b--;
		if (a == b) {
			cout << N << endl;
			continue;
		}
		int depth0 = tree.depth[a];
		int depth1 = tree.depth[b];
		if (depth0 > depth1) {
			swap(a, b);
			swap(depth0, depth1);
		}
		assert(depth0 <= depth1);
		if ((depth1 - depth0) % 2) {
			cout << 0 << endl;
		}
		else if (depth0 == depth1) {
			const int alca = tree.lca(a, b);
			const int targetdepth = tree.depth[alca];
			int nexttargetid0 = a;
			for (int k = 0; k < MAXLOGV; k++) {
				if ((depth1 - targetdepth)-1 >> k & 1) {
					nexttargetid0 = tree.parent[k][nexttargetid0];
				}
			}
			int nexttargetid1 = b;
			for (int k = 0; k < MAXLOGV; k++) {
				if (((depth1 - targetdepth) - 1) >> k & 1) {
					nexttargetid1 = tree.parent[k][nexttargetid1];
				}
			}
			int ans = N - (tree.childnums[nexttargetid0] + tree.childnums[nexttargetid1]);
			cout << ans << endl;
		}
		else {
			const int rootdepth = tree.depth[tree.lca(a, b)];
			const int targetdepth = depth1-((depth1 - rootdepth)+(depth0- rootdepth)) / 2;

			int targetid = b;
			for (int k = 0; k < MAXLOGV; k++) {
				if ((depth1-targetdepth) >> k & 1) {
					targetid = tree.parent[k][targetid];
				}
			}
			int nexttargetid = b;
			for (int k = 0; k < MAXLOGV; k++) {
				if (((depth1 - targetdepth)-1) >> k & 1) {
					nexttargetid = tree.parent[k][nexttargetid];
				}
			}
			int ans = tree.childnums[targetid] - tree.childnums[nexttargetid];
			cout << ans << endl;
		}
	}
	return 0;
}