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
int N;
vector<int>v;
vector<int> check(int k){
	vector<vector<pair<int,int>>>nums(20);
	//WHATS(k)
	for(int i=0;i<N;++i){
		int a=v[i];
		if(a>=(1<<k))continue;
		for(int j=19;j>=0;--j){
			if(a&(1<<j)){
				nums[j].push_back(make_pair(a,a));
				break;
			}
		}
	}
	//WHATS(nums)
	for(int i=19;i>=1;--i){
		sort(nums[i].begin(),nums[i].end(),[](const pair<int,int>&l,const pair<int,int>&r){
			return l.second<r.second;
		});
		if(!nums[i].empty()){
			for(int j=1;j<nums[i].size();++j){
				int anum=nums[i][j].first^nums[i][0].first;
				//WHATS(anum);
				for(int k=i-1;k>=0;--k){
					if(anum&(1<<k)){
						nums[k].push_back(make_pair(anum,nums[i][j].second));
						break;
					}
				}

			}
			nums[i].erase(nums[i].begin()+1,nums[i].end());
			assert((1<<i)<=nums[i][0].first&&nums[i][0].first<(1<<(i+1)));
		}
	}
	//WHATS(nums)
	int sz=0;
	for(int i=0;i<20;++i){
		if(!nums[i].empty()){
			sz++;
		}else{
			break;
		}
	}
	if(sz<k)return vector<int>();
	vector<int>anss(1<<sz);
	anss[0]=0;
	//WHATS(nums)
	for(int i=1;i<(1<<sz);++i){
		for(int j=0;j<20;++j){
			if((i)&(1<<j)){
				anss[i]=anss[i-1]^(nums[j][0].second);
				break;
			}
		}
	}
	return anss;
}
int main() {
	ios::sync_with_stdio(false);
	cin>>N;
	v.resize(N);
	for(int i=0;i<N;++i)cin>>v[i];
	int sz;
	vector<int>anss;
	for(sz=19;sz>=1;--sz){
		auto av=check(sz);
		//WHATS(sz)
		if(!av.empty()){
			anss=av;

			break;
		}else{
		}
	}
	if(sz==0)anss=vector<int>{0};
	cout<<sz<<endl;

	for(auto ans:anss)cout<<ans<<' ';
	cout<<endl;
	
	return 0;
}