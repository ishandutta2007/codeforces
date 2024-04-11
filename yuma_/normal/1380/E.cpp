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
#include<memory>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse2")

#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;
using Graph=vector<vector<int>>;
using ll=long long;
	
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
//1. mask
	// 	a. i==0
	// 	for(int i=mask; i>0; i=(i-1)&mask) {
	// 	}

	// b. i==0
	// 	for(int i=mask; i>=0; i--) {
	// 		i&=mask;
	// 	}
// 2. mask

// mask

// 	for(int i=mask; i<(1<<n); i=(i+1)|mask) {
// 	}

	
using ll = long long int;


struct UnionFind {
	vector<int> data;
	UnionFind(int size,vector<int>v) : data(size, -1) { 
		for(int i=0;i<size;++i){
			data[i]=-v[i];
		}
	}
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			//if (data[y] < data[x]) swap(x, y);
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

int get_id(vector<int>&tos,int a){
	
	int xx=a;
	while(tos[a]!=-1){
		a=tos[a];
	}
	return tos[xx]=a;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int N,M;cin>>N>>M;
	vector<int>places(N);
	vector<vector<int>>towers(M);
	for(int i=0;i<N;++i){
		int a;cin>>a;a--;
		towers[a].push_back(i);
		places[i]=a;
	}
	
	vector<int>av;
	for(int i=0;i<M;++i)av.push_back(towers[i].size());
	
	UnionFind uf(M,av);
	int answer=N-1;
	for(int i=0;i<N-1;++i){
		if(places[i+1]==places[i])answer--;
	}
	cout<<answer<<'\n';
	for(int i=0;i<M-1;++i){
		int u,v;cin>>u>>v;u--;v--;
		u=uf.root(u),v=uf.root(v);
		//WHATS(u)
		//WHATS(v)
		if(uf.size(u)>uf.size(v)){
			swap(u,v);
		}
		{
			for(auto id:towers[u]){
				if(id!=N-1){
					if(places[id+1]==v){
						answer--;
					}
				}
				if(id!=0){
					if(places[id-1]==v){
						answer--;
					}
				}
			}
			while(!towers[u].empty()){
				int id=towers[u].back();
				places[id]=v;
				towers[u].pop_back();
				towers[v].push_back(id);
			}
			assert(uf.size(u)<=uf.size(v));
			uf.unionSet(v,u);
			
		}
		cout<<answer<<'\n';
		//WHATS(towers)


	}


	
	return 0;
}