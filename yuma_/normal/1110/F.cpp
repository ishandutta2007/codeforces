#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

void dfs(vector<vector<pair<int, int>>>&graph, int now, int from,
	vector<long long int>&deps, vector<int>&ls, vector<int>&rs,int& id,long long int d) {

	deps[now]=d;

	ls[now]=id++;
	for (auto e : graph[now]) {
		dfs(graph,e.first,now,deps,ls,rs,id,d+e.second);
	}
	rs[now]=id;
}

struct query {
	int id;
	int a;
	int l;
	int r;
};
typedef long long int Value1;
typedef long long Value2;
const Value1 Zero1(1e18);
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
		dat[k].sum+=dat[k].lazy;
	}

	Value1 connect(const Value1 l, const Value1 r) {
		return min(l,r);

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
void dfs2(const vector<vector<pair<int,int>>>&graph,int now,int from,const vector<int>&ls,const vector<int>&rs,vector<Value1>&anss,
	const vector<long long int>&deps,const vector<vector<query>>&qs,lazy_segtree&seg) {
	
	for (auto q : qs[now]) {
		int l=q.l;
		int r=q.r;
		Value1 val=seg.get(l,r);
		anss[q.id]=val;
	}

	for (auto e : graph[now]) {
		long long int cost=e.second;
		seg.update(0,graph.size(),cost);
		seg.update(ls[e.first],rs[e.first],-2*cost);
		dfs2(graph,e.first,now,ls,rs,anss,deps,qs,seg);
		seg.update(0, graph.size(), -cost);
		seg.update(ls[e.first], rs[e.first], 2*cost);
	}
}

int main() {
	int N,Q;cin>>N>>Q;
	vector<vector<pair<int,int>>>graph(N);
	for (int i = 0; i < N-1; ++i) {
		int a,c;scanf("%d %d",&a,&c);
		a--;
		graph[a].push_back(make_pair(i+1,c));
	}
	int id=0;
	vector<int>ls(N),rs(N);
	vector<long long int>deps(N);
	dfs(graph,0,-1,deps,ls,rs,id,0);
	vector<vector<query>>querys(N);
	for (int i = 0; i < Q; ++i) {
		int a,l,r;scanf("%d %d %d",&a,&l,&r);
		l--;a--;
		querys[a].push_back(query{ i,a,l,r });
	}
	lazy_segtree seg(N);
	for (int i = 0; i < N; ++i) {
		if(graph[i].size()==0)seg.update(i,i+1,static_cast<long long int>(-1e18)+deps[i]);
	}
	vector<long long int>anss(Q);
	dfs2(graph,0,-1,ls,rs,anss,deps,querys,seg);
	for (int i = 0; i < Q; ++i) {
		printf("%lld\n",anss[i]);
	}
	return 0;
}