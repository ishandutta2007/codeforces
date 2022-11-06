#include "bits/stdc++.h"
#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<iomanip>
#include<assert.h>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<stack>
#include<complex>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

#define WHATS(var)//cout<<__LINE__<<' '<<#var<<"="<<var<<endl;

template<class S, class T> ostream& operator <<(ostream &os, const pair<S, T> v){
os << "( " << v.first << ", " << v.second << ")"; return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<T> &v){
for(int i = 0; i < v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<vector<T>> &v){
for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<set<T>> &v){
for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const set<T> &v){
int i=0;
for(auto it:v){
	if(i > 0){os << ' ';}
	os << it;
	i++;
} 
return os;
}


using ll=long long ;

#define WHAT(var) cout<<__LINE__<<' '<<#var<<" : "<<var<<endl;

const int mod=998244353;
int N,M,K,Q;
struct Edge{
	int src;
	int dst;
	ll cost;
};
using Graph=vector<vector<Edge>>;
Graph g;

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

class Tree {
public:
	Tree(int V, int root) : V(V), root(root), cnum(V), place(V), id(V) {
		T.resize(V);
		for (int i = 0; i < MAXLOGV; i++) {
			parent[i].resize(V);
		maxs[i].resize(V);

		}
		depth.resize(V);
	}
	// uv
	// lcaIOt
	void unite(int u, int v,ll x) {
		T[u].push_back(make_pair(v,x));
		T[v].push_back(make_pair(u,x));
	}
	// init
	// RXgN^lca
	void init() {
		dfs(root, root, 0,ll(0));
		int id = 0;
	}
	// uvlca
	ll lca(int u, int v) const {
		WHATS(maxs[0])
		if (depth[u] > depth[v]) swap(u, v);
		ll answer=0;
		WHATS(u)
		WHATS(v)
		WHATS(depth[u])
		WHATS(depth[v])
		for (int k = 0; k < MAXLOGV; k++) {
			if ((depth[v] - depth[u]) >> k & 1) {
				answer=max(maxs[k][v],answer);
				v = parent[k][v];
			}
		}
		WHATS(answer)
		if (u == v) return answer;
		for (int k = MAXLOGV - 1; k >= 0; k--) {
			if (parent[k][u] != parent[k][v]) {
				answer=max(maxs[k][v],answer);
				answer=max(maxs[k][u],answer);

				u = parent[k][u];
				v = parent[k][v];
			}
		}
		WHATS(answer)
		if(u!=v){
			answer=max(answer,maxs[0][u]);
			answer=max(answer,maxs[0][v]);
		}
		return answer;
	}

	int dfs(int v, int p,int de, ll d) {
		WHATS(v)
		depth[v]=de;
		parent[0][v] = p;
		maxs[0][v]=d;
		cnum[v] = 0;
		for (int i = 1; i < MAXLOGV; i++) {
			parent[i][v] = parent[i - 1][parent[i - 1][v]];
			maxs[i][v]=max(maxs[i-1][v],maxs[i-1][parent[i-1][v]]);
		}
		for (auto e: T[v]) {
			int next=e.first;
			ll cost=e.second;
			if (next != p) cnum[v] += dfs(next, v,de+1, cost);
		}
		return cnum[v] + 1;
	}

	static const int MAXLOGV = 25;
	// OtXg\
	vector<vector<pair<int,ll>> > T;
	// _
	int V;
	// m[h
	int root;

	// em[h
	vector<int> parent[MAXLOGV];
	vector<ll>maxs[MAXLOGV];
	// [
	vector<int> depth;

	//q
	vector<int>cnum;

	//
	vector<int>place;
	vector<int>id;

};
int main(){
	ios::sync_with_stdio(false);
	cin>>N>>M>>K>>Q;
	g.resize(N);
	vector<Edge>all_edges;
	for(int i=0;i<M;++i){
		int a,b,c;cin>>a>>b>>c;a--;b--;
		g[a].push_back(Edge{a,b,c});
		g[b].push_back(Edge{b,a,c});
		all_edges.push_back(Edge{a,b,c});
	}

	vector<pair<ll,int>>near_cs(N,make_pair(ll(1e18),-1));
	priority_queue<pair<ll,int>>que;

	for(int i=0;i<K;++i){
		near_cs[i]=make_pair(0ll,i);
		que.emplace(0ll,i);
	}
	while(!que.empty()){
		auto p(que.top());
		que.pop();
		int now=p.second;
		ll cost=-p.first;
		if(near_cs[now].first<cost)continue;
		for(auto e:g[now]){
			auto np=make_pair(cost+e.cost,near_cs[now].second);
			if(near_cs[e.dst]>np){
				near_cs[e.dst]=np;
				que.emplace(-np.first,e.dst);
			}
		}
	}
	WHATS(near_cs)
	vector<pair<ll,pair<int,int>>>connects;
	for(auto e:all_edges){
		if(near_cs[e.src].second!=near_cs[e.dst].second){
			ll sum=near_cs[e.src].first+near_cs[e.dst].first+e.cost;
			connects.emplace_back(sum,make_pair(near_cs[e.src].second,near_cs[e.dst].second));
			WHATS(e.src)
			WHATS(e.dst)
			WHATS(e.cost)
		}
	}
	sort(connects.begin(),connects.end());
	UnionFind uf(N);
	vector<vector<int>>mst(N);
	Tree tree(N,0);
	for(auto con:connects){
		int u=con.second.second;
		int v=con.second.first;
		
		if(uf.root(u)==uf.root(v)){

		}else{
			WHATS(u)
		WHATS(v)
		WHATS(con.first)
			uf.unionSet(u,v);
			mst[u].push_back(v);
			mst[v].push_back(u);
			tree.unite(u,v,con.first);
		}
	}
	WHATS(mst)
	tree.init();
	while(Q--){
		int s,t;cin>>s>>t;
		s--;t--;
		auto sc=near_cs[s].second;
		auto tc=near_cs[t].second;

		ll answer=max(near_cs[s].first,near_cs[t].first);
		answer=max(answer,tree.lca(sc,tc));

		cout<<answer<<endl;
	}
	return 0;
}