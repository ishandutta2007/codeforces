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

int mex(vector<int>&v){
	vector<int>cnts(v.size()+1);
	for(auto x:v)cnts[x]++;
	for(int i=0;i<cnts.size();++i){
		if(!cnts[i])return i;
	}
	return -1;
}
void pl(){
	vector<int>v{3,5,2,1,3,5,6,3,2};
	while(true){
		int x;cin>>x;
		for(int i=0;i<100;++i){
			if(find(v.begin(),v.end(),i)==v.end()){
				v[x]=i;
				break;
			}
		}
		WHATS(v)
	}
}
using ll = long long int;
void dfs(int now,int from,const Graph&g,int d,vector<int>&ds){
	ds[now]=d;
	for(auto e:g[now]){
		if(e==from)continue;
		else dfs(e,now,g,d+1,ds);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	
	int N;cin>>N;
	Graph g(N);
	for(int i=0;i<N-1;++i){
		int u,v;cin>>u>>v;u--;v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int>ds(N);
	dfs(0,-1,g,0,ds);
	int odd_cnt=count_if(ds.begin(),ds.end(),[](const int a){return a%2==1;});
	int ev_cnt=N-odd_cnt;
	cout<<min(odd_cnt,ev_cnt)-1<<endl;
	return 0;
}