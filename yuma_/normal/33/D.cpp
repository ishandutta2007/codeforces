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


#include <complex>

typedef long double ld;
struct Circle{
	ld x;
	ld y;
	ld r;
};
bool a_in_b(Circle&a,Circle&b){
	ld dx=a.x-b.x;
	ld dy=a.y-b.y;

	ld dis=sqrt(dx*dx+dy*dy);
	if(dis+a.r<=b.r)return true;
	else return false;
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

};
int main() {
	ios::sync_with_stdio(false);
	int N,M,K;cin>>N>>M>>K;
	vector<Circle>ps;
	for(int i=0;i<N;++i){
		ld x,y;cin>>x>>y;
		ps.push_back(Circle{x,y,0});
	}
	vector<Circle>cs;

	for(int i=0;i<M;++i){
		ld r,x,y;cin>>r>>x>>y;
		cs.push_back(Circle{x,y,r});
	}
	cs.push_back(Circle{0,0,3e9});
	vector<vector<int>>edges(M+1);
	vector<int>comes(M+1);
	vector<vector<int>>real_edges(M+1);
	for(int i=0;i<=M;++i){
		for(int j=0;j<=M;++j){
			if(i==j)continue;
			else{
				if(a_in_b(cs[i],cs[j])){
					edges[j].push_back(i);
					comes[i]++;

				}
			}
		}
	}
	//WHATS(comes)
	//WHATS(edges)
	for(int i=0;i<=M;++i){
		for(int j=0;j<=M;++j){
			if(i==j)continue;
			else{
				if(a_in_b(cs[i],cs[j])){
					if(comes[j]+1==comes[i]){
						real_edges[j].push_back(i);
					}
				}
			}
		}
	}
	//WHATS(real_edges)
	vector<int>ids(N);
	for(int i=0;i<N;++i){
		int max_d=-1;
		for(int j=0;j<=M;++j){
			if(a_in_b(ps[i],cs[j])){
				if(max_d<=comes[j]){
					max_d=comes[j];
					ids[i]=j;
				}
			}
		}
	}
	//WHATS(ids)
	Tree t(M+1,M);
	for(int i=0;i<=M;++i){
		for(auto e:real_edges[i]){
			t.unite(i,e);
		}
	}
	t.init();
	for(int i=0;i<K;++i){
		int a,b;cin>>a>>b;
		a--;b--;
		//cout<<t.lca(a,b)<<endl;;
		//WHATS(t.depth)
		int dis=t.dist(ids[a],ids[b]);
		cout<<dis<<endl;
	}
	return 0;
}