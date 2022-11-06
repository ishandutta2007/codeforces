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

using ll =long long ;
ll mod;
const int N=10;

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
	vector<ll>xs(N),ys(N);
	vector<ll>plants(N),wires(N);
	for(int i=0;i<N;++i){
		cin>>xs[i];
		cin>>ys[i];
	}
	priority_queue<pair<ll,pair<int,int>>>que;

	for(int i=0;i<N;++i){
		cin>>plants[i];
		que.emplace(-plants[i],make_pair(i,i));
	}
	for(int i=0;i<N;++i){
		cin>>wires[i];
	}

	vector<vector<ll>>costs(N,vector<ll>(N));
	for(int i=0;i<N;++i){
		for(int j=i+1;j<N;++j){
			costs[i][j]=(wires[i]+wires[j])*(abs(xs[i]-xs[j])+abs(ys[i]-ys[j]));
			que.emplace(-costs[i][j],make_pair(i,j));
		}
	}
	UnionFind uf(N+1);
	ll sum=0;
	vector<int>mk_plants;
	vector<pair<int,int>>mk_wires;
	while(!que.empty()){
		auto p=que.top();
		que.pop();
		int u=p.second.first,v=p.second.second;
		if(uf.root(N)==uf.root(u)&&uf.root(N)==uf.root(v))continue;
		if(u!=v&&(uf.root(u)==uf.root(v)))continue;
		if(u==v){
			uf.unionSet(N,u);
		}else{
			uf.unionSet(u,v);
		}
		if(p.second.first==p.second.second){
			mk_plants.push_back(p.second.first);
		}else{
			mk_wires.push_back(p.second);
		}
		sum-=p.first;
	}
	cout<<sum<<endl;
	cout<<mk_plants.size()<<endl;
	for(auto p:mk_plants)cout<<p+1<<' ';
	cout<<endl<<mk_wires.size()<<endl;
	for(auto p:mk_wires)cout<<1+p.first<<' '<<1+p.second<<endl;
	
	return 0;	
}