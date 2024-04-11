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

using ll = long long int;

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
struct flag{
	string colors;
	int x;
	int u;
	int d;
	int id;
};
int main() {
	ios::sync_with_stdio(false);
	int N,M;cin>>N>>M;

	vector<vector<int>>tos(int(5e5)+1,vector<int>(20));
	for(int i=0;i<5e5+1;++i){
		for(int j=0;j<20;++j)tos[i][j]=i;
	}
	for(int i=0;i<N;++i){
		int l,r;cin>>l>>r;
		tos[l][0]=max(tos[l][0],r);
	}
	for(int i=1;i<=5e5;++i){
		tos[i][0]=max(tos[i][0],tos[i-1][0]);
	}
	for(int k=1;k<20;++k){
		for(int i=0;i<=5e5;++i){
			tos[i][k]=tos[tos[i][k-1]][k-1];
		}
	}
	while(M--){
		int l,r;cin>>l>>r;
		int ans=0;
		int now=l;
		for(int k=19;k>=0;--k){
			if(tos[now][k]>=r){

			}else{
				ans+=(1<<k);
				now=tos[now][k];
			}
		}
		if(tos[l][19]<r){
			ans=-1;
		}else{
			ans++;

		}
		cout<<ans<<endl;
	}
	return 0;
}