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
	
	
using ll = long long int;

void solve(ll N ,ll K){
	ll sz=K*K+1;
	
	ll type=(N-1)/sz;
	ll id=(N-1)%sz;

	vector<ll>v;
	{
		ll now=type;
		while(now){
			v.push_back(now%K);
			now/=K;
		}
		reverse(v.begin(),v.end());
	}
	WHATS(v)

	ll now_selected=K*(K+1)/2-1;
	for(int i=0;i<v.size();++i){
		WHATS(now_selected)
		ll l=v[i]*K;
		ll r=(v[i]+1)*K;
		if(r<=now_selected){
			now_selected=K*(K+1)/2-(v[i]+1);
		}else if(now_selected<=l){
			now_selected=K*(K+1)/2-(v[i]+1)+K;
		}else{
			now_selected=K*(K+1)/2-(v[i]+1)+(r-now_selected);
		}
	}
	if(id==now_selected){

	}
	cout<<now_selected+1+type*sz<<endl;
}
map<long long int, int>soinnsuu(long long int a) {
	map<long long int, int>ans;
	for (long long i = 2; i*i <= a; ++i) {
		while (a%i == 0) {
			ans[i]++;
			a /= i;
		}
	}
	if (a != 1)ans[a]++;


	return ans;
}

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

int main() 
{
	ios::sync_with_stdio(false);
	int N,M;cin>>N>>M;
	UnionFind uf(N);
	int answer=0;
	for(int i=0;i<M;++i){
		int u,v;cin>>u>>v;
		u--;v--;
		if(uf.root(u)==uf.root(v)){
			answer++;
		}else{
			uf.unionSet(u,v);
		}
	}
	cout<<answer<<endl;

	return 0;
}