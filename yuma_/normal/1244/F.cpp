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
	
#define WHATS(var)cout<<__LINE__<<' '<<#var<<"="<<var<<endl;
	
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

using ll = long long int;
class Tree {
public:
	Tree(int V, int root) : V(V), root(root), cnum(V), place(V), id(V) {
		T.resize(V);
		for (int i = 0; i < MAXLOGV; i++) {
			parent[i].resize(V);
		}
		depth.resize(V);
		rs.resize(V);
	}
	// uv
	// lcaIOt
	void unite(int u, int v) {
		T[u].push_back(v);
		T[v].push_back(u);
	}
	// init
	// RXgN^lca
	void init() {
		dfs(root, root, 0);
		int id = 0;
		getid(root, root, id);
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
	// edge`_
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
		rs[v]=nplace;
	}
	static const int MAXLOGV = 25;
	// OtXg\
	vector<vector<int> > T;
	// _
	int V;
	// m[h
	int root;

	// em[h
	vector<int> parent[MAXLOGV];
	// [
	vector<int> depth;

	//q
	vector<int>cnum;

	//
	vector<int>place;
	vector<int>id;
	vector<int>rs;

};
map<int,int>get_mp(int X){
	vector<int>v;
	int k=1;
	for(;k*k<=X;++k){
		v.push_back(k);
		v.push_back((X-1)/k+1);
	}
	v.push_back(k);
	v.push_back((X-1)/k+1);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	map<int,int>mp;

	for(auto x:v){
		mp[x]=(X-1)/x+1;
	}
	return mp;
}
struct Edge{
	int u;
	int v;
	int c;
	Edge(int a,int b,int c):u(a),v(b),c(c){
		
	}
};
struct query{
	int l;
	int r;
	int plus;
};

using Value1=long long ;
typedef ll Value2;
const Value1 Zero1=0;
const Value2 Zero2=0;
 
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
	lazy_segtree(int n) :lazy_segtree(n,vector<long long int>(n,0)) {
	}
	lazy_segtree(int n,vector<long long int>v) :N(1) {
		while (N < n) N *= 2;
		dat.resize(2 * N);
		for (int i = 0; i < v.size(); ++i) {
			dat[i+N].sum = Zero1;
		}
		for (int i = N - 1; i >= 1; --i) {
			update_node(i);
		}
	}
 
	Value2 lazy_connect(const Value2 l, const Value2 r) {
		return l+r;
	}
 
	void lazy_func(const int k, const int a, const int b) {
		
		dat[k].sum+=dat[k].lazy*(b-a);
	}
 
	Value1 connect(const Value1 l, const Value1 r) {
		return l+r;
 
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


int main() {
	
	ios::sync_with_stdio(false);
	int N,K;cin>>N>>K;
	string st;cin>>st;
	vector<int>v(N);
	for(int i=0;i<N;++i){
		if(st[i]=='B')v[i]=0;
		else v[i]=1;
	}
	vector<int>oks(N);
	for(int i=0;i<N;++i){
		if(st[i]==st[(i+1)%N]){
			oks[i]=true;
			oks[(i+1)%N]=true;
		}
	}
	vector<pair<int,int>>lens(N,make_pair(2e9,-1));
	for(int i=0;i<N;++i){
		if(oks[i])lens[i]=make_pair(0,v[i]);
	}
	for(int i=0;i<N;++i){
		lens[i]=min(lens[i],make_pair(lens[(i+N-1)%N].first+1,lens[(i+N-1)%N].second));
	}
	for(int i=0;i<N;++i){
		lens[i]=min(lens[i],make_pair(lens[(i+N-1)%N].first+1,lens[(i+N-1)%N].second));
	}
	for(int i=N-1;i>=0;--i){
		lens[i]=min(lens[i],make_pair(lens[(i+1)%N].first+1,lens[(i+1)%N].second));
	}
	for(int i=N-1;i>=0;--i){
		lens[i]=min(lens[i],make_pair(lens[(i+1)%N].first+1,lens[(i+1)%N].second));
	}
	vector<int>answers(N);
	for(int i=0;i<N;++i){
		if(lens[i].first<=K){
			answers[i]=lens[i].second;
		}else{
			if(K%2){
				answers[i]=!v[i];
			}else{
				answers[i]=v[i];
			}
		}
	}
	for(int i=0;i<N;++i){
		if(!answers[i])cout<<'B';
		else cout<<'W';
	}
	cout<<endl;
	
	return 0;
}