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
const int MAX_N=5000;
int memo[MAX_N+2][MAX_N+2];
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int N;cin>>N;
	Graph g(N+2);
	vector<int>v(N);
	for(int i=0;i<N;++i)cin>>v[i];

	{
		vector<vector<int>>ls(7);
		map<int,vector<int>>mp;
		for(int i=0;i<N;++i){
			int num(v[i]);
			int amod=num%7;
			
			for(int x=0;x<ls[amod].size();++x){
				g[ls[amod][x]].push_back(i+1);
			}
			for(int anum=num-1;anum<=num+1;anum+=2){
				if(mp.find(anum)!=mp.end()){
					for(int x=0;x<mp[anum].size();++x){
						g[mp[anum][x]].push_back(i+1);
					}
				}
			}
			mp[num].push_back(i+1);
			if(mp[num].size()>=4)mp[num].erase(mp[num].begin());
			ls[amod].push_back(i+1);
			if(ls[amod].size()>=4)ls[amod].erase(ls[amod].begin());
			g[0].push_back(i+1);
			g[i+1].push_back(N+1);
		}
	}
	g[0].push_back(N+1);
	//WHATS(g)
	for(int i=0;i<=MAX_N+1;++i){
		for(int j=0;j<=MAX_N+1;++j){
			memo[i][j]=0;
		}
	}
	//WHATS(memo[0][0])
	for(int i=0;i<=N+1;++i){
		for(int j=i;j<=N+1;++j){
			if(i!=N+1){
				for(auto e:g[i]){
					if(e==N+1 ||e!=j){
						int ni=e;
						int nj=j;
						if(ni>nj)swap(ni,nj);
						// WHATS(i)
						// WHATS(j)
						// WHATS(ni)
						// WHATS(nj)
						memo[ni][nj]=max(memo[ni][nj],memo[i][j]+1);
					}
				}
			}
		}
	}
	int answer=0;
	answer=memo[N+1][N+1];
	cout<<answer-2<<endl;
	return 0;
}