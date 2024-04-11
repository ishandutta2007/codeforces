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
	void unite(vector<vector<int>>&e) {
		T = e;
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

	void dfs2(int v, int p, vector<vector<int>>&doubles, const vector<int>&nums) {
		for (int next : T[v]) {
			if (next != p) dfs2(next, v, doubles, nums);
		}
		doubles[0][v] = nums[v];
		for (int j = 1; j < MAXLOGV; ++j) {
			doubles[j][v] = min(doubles[j][v], doubles[j - 1][v]);
		}
		for (int j = 0; j < MAXLOGV - 1; ++j) {
			doubles[j + 1][parent[j][v]] = min(doubles[j + 1][parent[j][v]], doubles[j][v]);
		}
	}
	//2^i
	vector<vector<int>>get_doubles(const vector<int>&nums) {
		vector<vector<int>>doubles(MAXLOGV, vector<int>(V, 1e9));
		dfs2(root, -1, doubles, nums);
		return doubles;
	}

	void getid(const int v, const int p, int &nplace) {
		place[v] = nplace;
		id[nplace] = v;
		nplace++;
		for (int next : T[v]) {
			if (next != p) getid(next, v, nplace);
		}
	}
	static const int MAXLOGV = 20;
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
	int N;cin>>N;
	vector<int>ns;
	vector<vector<int>>edges(N+1);
	for (int i = 0; i < N; ++i) {
		int a;scanf("%d",&a);
		a--;
		ns.push_back(a);
		edges[a].push_back(i+1);
		edges[i+1].push_back(a);
	}
	Tree t(N+1,0);
	t.unite(edges);
	t.init();
	vector<int>dias(N+1);
	vector<int>ls(N+1),rs(N+1);
	dias[0]=0;
	int l=0;int r=0;
	for (int i = 0; i < N; ++i) {
		int predia=dias[i];
		int ldis=t.dist(i+1,l);
		int rdis=t.dist(i+1,r);
		if (ldis > predia&&ldis>rdis) {
			dias[i+1]=ldis;
			r=i+1;
		}
		else if (rdis > predia) {
			dias[i+1]=rdis;
			l=i+1;
		}else{
			dias[i+1]=predia;
		}
		ls[i+1]=l;
		rs[i+1]=r;
	}
	vector<int>pluss(N+2);
	for (int id = 0; id <= N; ++id) {
		int appear=id;
		int al=appear-1;
		int ar=N+1;
		while (al + 1 != ar) {
			int am((al+ar+1)/2);
			int adis=max(t.dist(ls[am],id),t.dist(rs[am],id));
			if (adis == dias[am]) {
				al=am;
			}else{
				ar=am;
			}
		}
		pluss[ar]++;
	}
	int ans=1;
	for (int i = 0; i < N; ++i) {
		ans++;
		ans-=pluss[i+1];
		printf("%d\n",ans);
	}
	return 0;
}