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

int main() {
	
	ios::sync_with_stdio(false);
	int N;cin>>N;
	map<int,vector<int>>edges;
	for(int i=0;i<N;++i){
		int u,v;cin>>u>>v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	int s=-1;
	for(auto m:edges){
		if(m.second.size()==1){
			s=m.first;
		}
	}
	int from=-1;
	int now=s;
	while(true){
		cout<<now<<' ';
		//WHATS(from)
		bool flag=false;
		for(auto e:edges[now]){
			if(e==from)continue;
			else{
				from=now;

				now=e;
				flag=true;
				break;
			}
		}
		if(flag)continue;
		else break;
	}
	cout<<endl;

	return 0;
}