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
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

#define WHATS(var) cout<<__LINE__<<' '<<#var<<"="<<var<<endl;

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
struct query{
	int id;
	int cost;

	int u;
	int v;
};
bool operator <(const query&l,const query&r){
	return l.cost==r.cost?l.id<r.id:l.cost<r.cost;
}
int main() {
	ios::sync_with_stdio(false);
	int N,Q;cin>>N>>Q;
	vector<query>qs;
	for(int i=0;i<N-1;++i){
		int a,b,c;cin>>a>>b>>c;
		qs.push_back(query{1,c,a-1,b-1});
	}
	for(int i=0;i<Q;++i){
		int a;cin>>a;
		qs.push_back(query{2,a,i,0});
	}
	sort(qs.begin(),qs.end());
	UnionFind uf(N);
	ll answer=0;
	vector<ll>anss(N);
	for(auto q:qs){
		if(q.id==1){
			int u=q.u;
			int v=q.v;
			answer-=uf.size(u)*ll(uf.size(u)-1)/2;
			answer-=uf.size(v)*ll(uf.size(v)-1)/2;
			uf.unionSet(u,v);
			answer+=uf.size(u)*ll(uf.size(u)-1)/2;
		}else{
			anss[q.u]=answer;
		}
	}
	for(int i=0;i<Q;++i){
		cout<<anss[i]<<' ';
	}
	cout<<endl;
	return 0;
}