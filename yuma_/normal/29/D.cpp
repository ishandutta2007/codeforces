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
	int N;cin>>N;
	vector<vector<int>>graph(N);
	Tree t(N,0);
	for(int i=0;i<N-1;++i){
		int u,v;cin>>u>>v;
		u--;v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
		t.unite(u,v);
	}
	t.init();
	vector<int>answer;
	vector<int>leafs;
	int x=0;
	while(cin>>x){
		x--;
		leafs.push_back(x);
	}
	//WHATS(leafs)
	answer.push_back(0);
	answer.push_back(leafs[0]);
	for(int i=0;i<leafs.size()-1;++i){
		answer.push_back(t.lca(leafs[i],leafs[i+1]));
		answer.push_back(leafs[i+1]);
	}

	answer.push_back(0);
	vector<int>route{0};
	for(int i=0;i<answer.size()-1;++i){
		int x=answer[i];
		int y=answer[i+1];
		vector<int>av;
		if(t.depth[x]<t.depth[y]){
			int now=y;
			while(now!=x){
				//WHATS(now)
				av.push_back(now);
				now=t.parent[0][now];
			}
			reverse(av.begin(),av.end());
		}else{
			int now=x;
			while(now!=y){
				now=t.parent[0][now];
				av.push_back(now);
			}
		}
		route.insert(route.end(),av.begin(),av.end());
	}
	if(route.size()!=2*N-1){
		route=vector<int>{-2};
	}
	for(int i=0;i<route.size();++i){
		cout<<route[i]+1<<' ';
	}
	cout<<endl;

	return 0;
}