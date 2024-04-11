#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld=long double;

void dfs(vector<int>&ls,vector<int>&rs,int &a,
	const vector<vector<int>>&edges,int now, int from) {
	ls[now]=a;
	a++;
	
	for (auto e : edges[now]) {
		if(e==from)continue; 
		dfs(ls,rs,a,edges,e,now);
	}
	rs[now]=a;
}
vector<int>mp;
vector<int>rev_mp;
vector<int>ls,rs;
vector<vector<int>>solve(
	const vector<vector<int>>&edges,const int root) {
	ls.resize(edges.size());
	rs.resize(edges.size());

	int a=0;
	dfs(ls,rs,a,edges,root,-1);
	mp.resize(edges.size());
	rev_mp.resize(edges.size());

	vector<vector<int>>newedges(edges.size());
	for (int i = 0; i < edges.size(); ++i) {
		for (auto e : edges[i]) {
			newedges[ls[i]].push_back(ls[e]);
		}
	}
	mp=ls;
	for (int i = 0; i < edges.size(); ++i) {
		rev_mp[ls[i]]=i;
	}
	vector<int>new_rs(edges.size());
	vector<int>new_ls(edges.size());
	for (int i = 0; i < edges.size(); ++i) {
		new_ls[ls[i]]=ls[i];
		new_rs[ls[i]]=rs[i];
	}
	ls=new_ls;
	rs=new_rs;
	return newedges; 
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

typedef pair<int,int> Value1;
typedef int Value2;
const Value1 Zero1(1e9,1);
const Value2 Zero2(0);

struct Node {
	Value1 sum;//. .
	Value2 lazy;	//
	Node() :sum(Zero1) {
		lazy = Zero2;
	}
};
struct lazy_segtree {
	int N;
	vector<Node>dat;
	lazy_segtree(int n) :N(1) {
		while (N < n) N *= 2;
		dat.resize(2 * N);
		for (int i = N - 1; i >= 1; --i) {
			update_node(i);
		}
	}

	Value2 lazy_connect(const Value2 l, const Value2 r) {
		return l+r;
	}

	void lazy_func(const int k, const int a, const int b) {
		dat[k].sum.first+=dat[k].lazy;
	}

	Value1 connect(const Value1 l, const Value1 r) {
		if(l.first>r.first)return r;
		else if(l.first==r.first)return make_pair(l.first,l.second+r.second);
		else return l;
	}

	// inline!()
	inline void lazy_evaluate_node(int k, int a, int b) {
		lazy_func(k, a, b);
		if (k < N) { // 2*k() < 2*N () . .
			dat[2 * k].lazy = lazy_connect(dat[2 * k].lazy, dat[k].lazy);	//.
			dat[2 * k + 1].lazy = lazy_connect(dat[2 * k + 1].lazy, dat[k].lazy);
		}
		dat[k].lazy = Zero2;
	}

	inline void update_node(int k) { // k. if.
		dat[k].sum = connect(dat[2 * k].sum, dat[2 * k + 1].sum);

	}

	// update(l,r,v) := [l,r). 0-indexed.
	void update(int l, int r, Value2 v, int k = 1, int a = 0, int b = -1) {
		if (b == -1)b = N;
		if (l < 0 || r < 0)assert(false);
		lazy_evaluate_node(k, a, b); 	// .

		if (b <= l || r <= a) //[a,b)[l,r)
			return;
		if (l <= a && b <= r) { // [l,r)[a,b)
			dat[k].lazy = lazy_connect(dat[k].lazy, v);
			lazy_evaluate_node(k, a, b); //.
			return;
		}

		int m = (a + b) / 2;
		update(l, r, v, 2 * k, a, m);
		update(l, r, v, 2 * k + 1, m, b);
		update_node(k);
	}
	//get(l,r) := [l,r). 0-indexed.
	Value1 get(int l, int r, int k = 1, int a = 0, int b = -1) {
		if (b == -1)b = N;

		if (l < 0 || r<0)assert(false);
		lazy_evaluate_node(k, a, b); // .

		if (b <= l || r <= a) //[a,b)[l,r)
			return Zero1;

		if (l <= a && b <= r) { // [l,r)[a,b)
			return dat[k].sum;
		}

		int m = (a + b) / 2;
		Value1 vl = get(l, r, 2 * k, a, m);
		Value1 vr = get(l, r, 2 * k + 1, m, b);
		update_node(k);
		return connect(vl, vr);
	}
};

//struct Node {
//	char var;
//	vector<shared_ptr<Node>>chs;
//	Node(char ch):var(ch) {
//
//	}
//	Node() :var('@') {
//
//	}
//};
//
//shared_ptr<Node> term(const vector<int>&ways,map<char,int>mp,string st, int&a,int k) {
//	if (st[a] == '(') {
//		a++;
//		auto ans=term(ways,mp,st,a,0);
//		assert(st[a]==')');
//		a++;
//		return ans;
//	}
//	else {
//		assert(isalpha(st[a]));
//		char var=st[a];
//		a++;
//
//		shared_ptr<Node>no = make_shared<Node>(var);
//		if (a == st.size() || st[a] == ')') {
//			return no;
//		}
//		if (mp[var] >= k) {
//			shared_ptr<Node>ans;
//			if (ways[mp[var]] == 1) {
//				 ans=term(ways,mp,st,a,k-1);
//			}
//			else {
//				ans=term(ways,mp,st,a,k);
//			}
//			shared_ptr<Node>pa;
//			pa->chs = vector<shared_ptr<Node>>{ no,ans };
//		}
//		else {
//			return no;
//		}
//	}
//}

int main() {
	int N,M;cin>>N>>M;
	vector<vector<int>>real_edges;
	{
		vector<vector<int>>edges(N);
		for (int i = 0; i < N - 1; ++i) {
			int a,b;scanf("%d %d",&a,&b);
			a--;b--;
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
		real_edges=solve(edges,0);
	}
	Tree t(N,0);
	t.unite(real_edges);
	t.init();
	lazy_segtree seg(N);
	seg.update(0,N,-1e9);
	set<pair<int,int>>aset;
	for (int i = 0; i < M; ++i) {
		int a,b;scanf("%d %d",&a,&b);a--;b--;
		a=mp[a];b=mp[b];
		int val = 1;  
		pair<int,int>ap(min(a,b),max(a,b));
		if (aset.find(ap) == aset.end()) {
			aset.emplace(ap);
		}
		else {
			aset.erase(ap);
			val=-1;
		}
		if(t.depth[a]>t.depth[b])swap(a,b);
		
		assert(t.depth[a]<=t.depth[b]);

		if (t.dist(a, b) == abs(t.depth[a] - t.depth[b])) {
			int rest=t.depth[b]-t.depth[a]-1;
			int c=b;
			for (int i = 23; i >= 0; --i) {
				if (rest >= (1 << i)) {
					rest-=(1<<i);
					c=t.parent[i][c];
				}
			}

			seg.update(ls[c],rs[c],val);
			seg.update(ls[b],rs[b],-val);
		}
		else {
			int c=t.lca(a,b);
			seg.update(0,N,val);
			seg.update(ls[a],rs[a],-val);
			seg.update(ls[b],rs[b],-val);
		}
		auto p=seg.get(0,N);
		printf("%d\n",((p.first==0?p.second:0)));
	}
	return 0;
/*
	int T;cin>>T;
	for (int t = 0; t < T; ++t) {
		int N; cin >> N;
		map<char, int>ch_mp;
		vector<int>ways(N);
		for (int i = 0; i < N; ++i) {
			char way; cin >> way;
			ways[i] = way == 'L';
			int K; cin >> K;
			for (int j = 0; j < K; ++j) {
				char ch; cin >> ch;
				ch_mp[ch] = i;

			}
		}
		int M; cin >> M;
		for (int i = 0; i < M; ++i) {
			string st; cin >> st;

		}
		if(t!=T-1)cout<<endl;
	}
	*/
}