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
template<class T> ostream& operator <<(ostream &os, const map<T,T> &v){
	int i=0;
	for(auto it:v){
		if(i > 0){os << ' ';}
		os << it.first<<' '<<it.second;
		i++;
	} 
	return os;
}
using ll=long long ;

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

const int MAX_N=1005;
ll dp[MAX_N+3][MAX_N+3][2];
int main() {
	ios::sync_with_stdio(false);
	int M;cin>>M;
	vector<Tree>trees;
	vector<vector<int>>leafs(2,vector<int>{0});
	int sum=0;
	for(int t=0;t<2;++t){
		int N;cin>>N;
		sum+=N-1;
		Tree t1(N,0);
		for(int i=1;i<N;++i){
			int k;cin>>k;
			k--;
			t1.unite(k,i);
		}
		for(int i=0;i<M;++i){
			int k;cin>>k;k--;
			leafs[t].push_back(k);
		}
		t1.init();
		trees.push_back(t1);
	}
	for(int i=0;i<MAX_N+3;++i){
		for(int j=0;j<MAX_N+3;++j){
			for(int k=0;k<2;++k){
				dp[i][j][k]=1e18;
			}
		}
	}
	//WHATS(leafs)
	dp[1][1][0]=0;
	for(int i=1;i<=M;++i){
		for(int pre=0;pre<2;++pre){
			for(int len=1;len<=i;++len){
				for(int use=0;use<2;++use){
					ll plus=0;
					int nlen;

					if(pre==use){
						//WHATS(leafs[use][i])
						//WHATS(leafs[use][i-1])
						plus=trees[use].depth[leafs[use][i]]-trees[use].depth[trees[use].lca(leafs[use][i],leafs[use][i-1])];
						nlen=len+1;
					}else{
						plus=trees[use].depth[leafs[use][i]]-trees[use].depth[trees[use].lca(leafs[use][i],leafs[use][i-len])];

						nlen=2;
					}
					//WHATS(plus)
					dp[i+1][nlen][use]=min(dp[i+1][nlen][use],dp[i][len][pre]+plus);
				}
			}
		}
	}
	ll answer=1e18;
	for(int pre=0;pre<2;++pre){
		for(int len=1;len<=M+1;++len){
			answer=min(answer,dp[M+1][len][pre]);
		}
	}
	cout<<ll(sum)-answer<<endl;
	
	
	return 0;
}