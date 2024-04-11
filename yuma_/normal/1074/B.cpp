#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld=long double;

#define Seg_Max_N (1<<18) 

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

int f_out(char a, int b) {
	b++;
	printf("%c %d\n",a,b);
	fflush(stdout);
	if(a=='C')return -1;
	else {
		int ans;
		scanf("%d",&ans);ans--;
		return ans;
	}
}

int main() {
	int T;cin>>T;
	while (T--) {
		int N;cin>>N;
		vector<vector<int>>edges(N);
		for (int i = 0; i < N - 1; ++i) {
			int a,b;
			scanf("%d %d",&a,&b);
			a--;b--;
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
		Tree t(N,0);
		t.unite(edges);
		t.init();
		int k1;scanf("%d",&k1);
		vector<int>my_selects;
		for (int i = 0; i < k1; ++i) {
			int x;scanf("%d",&x);x--;
			my_selects.push_back(x);
		}
		int k2;scanf("%d",&k2);
		vector<int>op_selects;
		for (int i = 0; i < k2; ++i) {
			int x;scanf("%d",&x);
			x--;
			op_selects.push_back(x);
		}

		int mine=f_out('B',op_selects[0]);

		pair<int,int>min_p=make_pair(10000000,10000000);
		for (int i = 0; i < k1; ++i) {
			int dis=t.dist(my_selects[i],mine);
			min_p=min(min_p,make_pair(dis,my_selects[i]));
		}
		int yours=f_out('A',min_p.second);

		bool ok=false;
		for (int i = 0; i < k2; ++i) {
			if (op_selects[i] == yours) {
				f_out('C',min_p.second);
				ok=true;
				break;
			}
		}
		if(!ok)f_out('C',-2);
	}
	return 0;
}