#include "bits/stdc++.h"
using namespace std;
using ld=long double;
#pragma warning(disable:4996)

vector<int>ls(1e5+1),rs(1e5+1);
vector<int>ds(1e5+1,-1);
#define Seg_Max_N (1<<18) 

using Value = int;
const Value ini = 1e9;
struct segtree {
	int N;
	vector<Value>dat;

	segtree() {}
	segtree(int n) :dat(2 * Seg_Max_N) {
		N = 1;
		while (N < n) N *= 2;
		for (int i = 0; i < 2 * N - 1; i++) {
			dat[i] = ini;
		}
	}
	Value connect(const Value&l, const Value&r) {
		return min(l,r);
	}
	// update k th element
	void update(int k, Value a) {
		k += N - 1;
		dat[k] = a;

		while (k > 0) {
			k = (k - 1) / 2;
			const Value al(dat[k * 2 + 1]);
			const Value ar(dat[k * 2 + 2]);
			dat[k] = connect(al, ar);
		}
	}
	 //min [a, b)
	Value  query(int a, int b) { return query(a, b, 0, 0, N); }
	Value  query(int a, int b, int k, int l, int r) {
		if (r <= a or b <= l) return ini;
		if (a <= l and r <= b) return dat[k];
		const int m = (l + r) / 2;
		const Value al(query(a, b, k * 2 + 1, l, m));
		const Value ar(query(a, b, k * 2 + 2, m, r));
		return connect(al, ar);
	}
};
void dfs(const vector<vector<int>>&edges,const int depth,const int now, const int from,int&id) {
	ls[now]=id;
	ds[now]=depth;
	id++;
	for (auto e : edges[now]) {
		if(e==from)continue;
		else {
			dfs(edges,depth+1,e,now,id);
		}
	}
	rs[now]=id;
}
vector<int>ch(vector<int>&froms, vector<int>&tos) {
	vector<int>nextfroms(froms.size());
	for (int i = 0; i < froms.size(); ++i) {
		nextfroms[tos[i]]=froms[i];
	}
	return nextfroms;
}
vector<vector<int>>ch(vector<vector<int>>&froms, vector<int>&tos) {
	vector<vector<int>>nextfroms(froms.size());
	for (int i = 0; i < froms.size(); ++i) {
		for (int j = 0; j < froms[i].size(); ++j) {
			//if (tos[i] < tos[froms[i][j]]) {

				nextfroms[tos[i]].push_back(tos[froms[i][j]]);
			//}
		}
	}
	return nextfroms;
}
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
		T=e;
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

	void dfs2(int v, int p, vector<vector<int>>&doubles,const vector<int>&nums) {
		for (int next : T[v]) {
			if (next != p) dfs2(next, v, doubles,nums);
		}
		doubles[0][v] = nums[v];
		for (int j = 1; j < MAXLOGV; ++j) {
			doubles[j][v]=min(doubles[j][v],doubles[j-1][v]);
		}
		for (int j = 0; j < MAXLOGV-1; ++j) {
			doubles[j+1][parent[j][v]]=min(doubles[j+1][parent[j][v]],doubles[j][v]);
		}
	}
	//2^i
	vector<vector<int>>get_doubles(const vector<int>&nums) {
		vector<vector<int>>doubles(MAXLOGV,vector<int>(V,1e9));
		dfs2(root,-1,doubles,nums);
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

//root,ID
//tos 
vector<int> get_width_tos(const vector<vector<int>>&edges,int root) {
	vector<int>tos(edges.size());
	queue<int>que;
	que.push(root);
	vector<int>flags(edges.size());
	int nid = 0;
	while (!que.empty()) {
		const int now(que.front());
		que.pop();
		tos[now] = nid++;
		flags[now]=true;
		for (auto e : edges[now]) {
			if (flags[e]) {
			}
			else {
				que.push(e);
			}
		}
	}
	return tos;
}
int main() { 
	int N,root;cin>>N>>root;
	ds=vector<int>(N,-1);
	root--;
	vector<int>nums(N);
	for (int i = 0; i < N; ++i) {
		cin>>nums[i];
	}
	vector<vector<int>>edges(N);
	for (int i = 0; i < N-1; ++i) {
		int a,b;cin>>a>>b;
		a--;b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	vector<int>tos(get_width_tos(edges,root));
	
	{
		nums = ch(nums, tos);
		root = tos[root];
		edges=ch(edges,tos);
	}
	int id=0;
	dfs(edges,0,0,-1,id);
	vector<segtree>segs(18,N);
	{
		Tree t(N,0);
		t.unite(edges);
		t.init();
		vector<vector<int>>doubles=t.get_doubles(nums);

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < 18; ++j) {
				segs[j].update(i,doubles[j][i]);
			}
		}
	}
	int pre=0;
	int Q;cin>>Q;
	bool flag=false;
	if(Q>10000) flag=true;
	while (Q--) {
		//if(flag==1&&Q==95000)return 0;
		int x,k;scanf("%d %d",&x,&k);
		x=(x+pre)%N;
		x=tos[x];
		k=(k+pre)%N+1;
		const int xd=ds[x];
		int num=1;
		for(int i=0;i<17;++i)num*=2;
		int ans=1e9;
		int nplus=0;
		for (int i = 17; i >= 0; --i) {
			if (k&num) {
				auto at=lower_bound(ds.begin(),ds.end(),xd+nplus);
				auto bt=upper_bound(at,ds.end(),xd+nplus);
				auto lt=lower_bound(ls.begin()+(at-ds.begin()),ls.begin()+(bt-ds.begin()),ls[x]);
				auto rt=lower_bound(lt, ls.begin() + (bt - ds.begin()), rs[x]);
				if (lt != rt) {

					ans = min(ans, segs[i].query(lt - ls.begin(), rt - ls.begin()));
				}
				nplus += num;
			}
			num/=2;
		}
		pre=ans;
		printf("%d\n",ans);
	}
	return 0;
}