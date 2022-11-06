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
template<class T> ostream& operator <<(ostream &os, const map<T,T> &v){
	int i=0;
	for(auto it:v){
		if(i > 0){os << ' ';}
		os << it.first<<' '<<it.second;
		i++;
	} 
	return os;
}
using ll=long long ;
const ll mod=1e9+7;

int k=0;
vector<int>anss;
vector<vector<int>>g;
void dfs(int now,int from){
	vector<int>chs;
	if(now==0){
		anss.push_back(1);
	}
	for(auto e:g[now]){
		if(e!=from){
			chs.push_back(e);
		}
	}
	for(int i=chs.size()-1;i>=0;--i){
		anss.push_back(chs[i]+1);
	}
	anss.push_back(now+1);
	
	for(int i=0;i<chs.size();++i){
		dfs(chs[i],now);
	}
}
int main() {
	int N;cin>>N;
	g.resize(N);
	for(int i=0;i<N-1;++i){
		int u,v;
		scanf("%d %d",&u,&v);
		u--;v--;
		g[u].push_back(v);
		g[v].push_back(u);		
	}
	dfs(0,-1);
	//WHATS(anss)
	vector<vector<int>>vs(N);
	for(int i=0;i<2*N;++i){
		vs[anss[i]-1].push_back(i+1);
	}
	for(int i=0;i<N;++i){
		printf("%d %d\n",vs[i][0],vs[i][1]);
	}

	return 0;
}