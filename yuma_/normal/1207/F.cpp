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
int main() {

	ios::sync_with_stdio(false);
	int N;cin>>N;
	vector<ll>as(500000);
	vector<vector<ll>>anss(700);
	for(int i=0;i<anss.size();++i){
		anss[i].resize(i);
	}
	while(N--){
		int type;
		int x,y;
		cin>>type>>x>>y;
		if(type==1){
			as[x-1]+=y;
			for(int i=1;i<anss.size();++i){
				anss[i][x%i]+=y;
			}
		}else{
			ll answer=0;
			if(x<anss.size()){
				answer=anss[x][y];
			}else{
				for(int k=y-1<0?x-1:y-1;k<500000;k+=x){
					answer+=as[k];
				}
			}
			cout<<answer<<endl;
		}
	}
	return 0;
}