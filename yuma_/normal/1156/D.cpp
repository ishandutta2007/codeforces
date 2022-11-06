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
struct Edge{
	int u;
	int v;
	ll cost;
};
int N,M,Q;
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
int main() {
	ios::sync_with_stdio(false);
	int N;cin>>N;
	g.resize(N);
	UnionFind uf1(N),uf2(N);

	for(int i=0;i<N-1;++i){
		int u,v,c;cin>>u>>v>>c;u--;v--;
		g[u].push_back(Edge{u,v,c});
		g[v].push_back(Edge{v,u,c});
		if(c){
			uf1.unionSet(u,v);
		}else{
			uf2.unionSet(u,v);
		}
	}
	ll answer=0;
	for(int i=0;i<N;++i){
		{
			//int v=e.v;
			//int c=e.cost;
			{
				answer+=(uf2.size(i)-1)*ll(uf1.size(i)-1);
			}
		}
	}
	set<int>used;
	{
		for(int i=0;i<N;++i){
			if(used.find(uf1.root(i))==used.end()){
				used.emplace(uf1.root(i));
				answer+=uf1.size(i)*ll(uf1.size(i)-1);
			}
		}
		used.clear();
			for(int i=0;i<N;++i){
			if(used.find(uf2.root(i))==used.end()){
				used.emplace(uf2.root(i));
				answer+=uf2.size(i)*ll(uf2.size(i)-1);
			}
		}
	}
	cout<<answer<<endl;


	return 0;
}