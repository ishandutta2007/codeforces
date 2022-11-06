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


using ll=long long ;


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
	int N,M,K;cin>>N>>M>>K;
	vector<pair<int,int>>ps(M);
	vector<set<int>>edges(N);
	for(int i=0;i<M;++i){
		int u,v;cin>>u>>v;u--;v--;
		ps[i]=make_pair(u,v);
		edges[u].emplace(v);
		edges[v].emplace(u);
	}

	vector<int>dels;
	int sum=N;
	for(int i=0;i<N;++i){
		if(edges[i].size()<K){
			dels.push_back(i);
		}
	}
	vector<int>valids(N,true);
	while(!dels.empty()){
		
		int now=dels.back();
		dels.pop_back();

		if(valids[now]){
			valids[now]=false;
			sum--;
		}else{
			continue;
		}
		for(auto e:edges[now]){
			edges[e].erase(now);
			if(edges[e].size()<K){
				dels.emplace_back(e);
			}
		}
		edges[now].clear();
	}
	vector<int>answers(M+1);
	answers[M]=sum;
	for(int i=M-1;i>=0;--i){
		auto p=ps[i];
		int u=p.first,v=p.second;
		if(edges[u].find(v)!=edges[u].end()){
			edges[u].erase(v);
			if(edges[u].size()<K){
				dels.push_back(u);
			}
		}
		if(edges[v].find(u)!=edges[v].end()){
			edges[v].erase(u);
			if(edges[v].size()<K){
				dels.push_back(v);
			}
		}
		//WHATS(dels)
		while(!dels.empty()){
			int now=dels.back();
			dels.pop_back();

			if(valids[now]){
				valids[now]=false;
				sum--;
			}else{
				continue;
			}
			for(auto e:edges[now]){
				edges[e].erase(now);
				if(edges[e].size()<K){
					dels.emplace_back(e);
				}
			}
			edges[now].clear();
		}
		//WHATS(edges)
		answers[i]=sum;
	}
	for(int i=1;i<=M;++i)cout<<answers[i]<<endl;

	return 0;
}