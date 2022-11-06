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
	cin.tie();
	
	// int H,W;cin>>H>>W;
	// vector<string>field(H);
	// for(int y=0;y<H;++y){
	// 	cin>>field[y];

	// }
	// UnionFind uf(H+W);
	// for(int y=0;y<H;++y){
	// 	for(int x=0;x<W;++x){
	// 		if(field[y][x]=='#')uf.unionSet(y,x+H);
	// 	}
	// }
	// bool ok=true;
	// for(int y=0;y<H;++y){
	// 	for(int x=0;x<W;++x){
	// 		if(field[y][x]=='.'){
	// 			if(uf.root(y)==uf.root(x+H))ok=false;
	// 		}
	// 	}
	// }
	// if(ok)cout<<"Yes"<<endl;
	// else cout<<"No"<<endl;

	int N;cin>>N;
	vector<ll>v(N);
	for(int i=0;i<N;++i)cin>>v[i];
	vector<ll>v2(N);
	ll answer=0;
	ll kk=0;
	for(int i=N-1;i>=0;--i){
		kk--;
		kk=max(kk,v[i]);
		v2[i]=kk;
	}
	kk=0;
	for(int i=0;i<N;++i){
		v2[i]=max(v2[i],kk);
		kk=max(kk,v[i]);
	}
	for(int i=0;i<N;++i)answer+=v2[i]-v[i];
	cout<<answer<<endl;
	return 0;
}