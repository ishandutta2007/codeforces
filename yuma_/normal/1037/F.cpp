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
const ll mod=1e9+7;
ll get_sz(ll sz,int M){
	ll depth=(sz-1)/(M-1)+1;
	ll u=sz;
	ll d=u-(depth-1)*(M-1);

	return (u+d)*depth/2;
}
ll solve(int sz,int place,int M){
	ll cnt=get_sz(sz,M)-get_sz(place,M)-get_sz(sz-place-1,M);
	cnt%=mod;
	return cnt-1;
}
int main() {
	ios::sync_with_stdio(false);
	int N,M;cin>>N>>M;
	vector<ll>nums(N);
	vector<pair<ll,int>>ps;
	for(int i=0;i<N;++i){
		cin>>nums[i];
		ps.emplace_back(nums[i],i);
	}
	sort(ps.begin(),ps.end());
	vector<int>ls(N),rs(N);
	for(int i=0;i<N;++i){
		ls[i]=i-1;
		rs[i]=i+1;
	}
	ll answer=0;
	for(auto p:ps){
		ll num=p.first;
		int place=p.second;
		int r=rs[place];
		int l=ls[place];

		ll nanswer=solve(r-l-1,place-l-1,M);
		//WHATS(nanswer)
		answer+=nanswer%mod*num%mod;
		if(r!=N)ls[r]=l;
		if(l!=-1)rs[l]=r;
	}
	answer%=mod;
	cout<<answer<<endl;
	return 0;
}