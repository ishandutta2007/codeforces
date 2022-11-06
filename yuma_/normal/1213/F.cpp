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
	int a;
	int b;
};
bool operator <(const query&l,const query&r){
	return l.a<r.a;
}
int main() {
	ios::sync_with_stdio(false);
	int N,T;cin>>N>>T;
	vector<query>ps(N);
	for(int i=0;i<N;++i){
		int a;cin>>a;a--;
		ps[i].a=a;
		ps[i].id=i;
	}
	for(int i=0;i<N;++i){
		int a;cin>>a;a--;
		ps[i].b=a;
	}
	vector<int>anss(N,-1);
	set<int>aset;
	int x=0;
	for(int i=0;i<N;++i){
		if(aset.empty())x++;
		anss[ps[i].a]=x;
		anss[ps[i].b]=x;
		if(aset.find(ps[i].a)==aset.end()){
			aset.emplace(ps[i].a);
		}else{
			aset.erase(ps[i].a);
		}
		if(aset.find(ps[i].b)==aset.end()){
			aset.emplace(ps[i].b);
		}else{
			aset.erase(ps[i].b);
		}
	}
	if(x>=T){
		cout<<"YES"<<endl;
		for(int i=0;i<N;++i){
			cout<<char('a'+min(25,anss[i]-1));
		}
		cout<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}