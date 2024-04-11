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
void solve(int now,vector<int>&rest,vector<int>&ans){
	rest[now]--;
	ans.push_back(now);
	if(now&&rest[now-1]>=1){
		solve(now-1,rest,ans);
	}else if(now!=3&&rest[now+1]>=1){
		solve(now+1,rest,ans);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int>v(4);
	for(int i=0;i<4;++i)cin>>v[i];
	vector<int>ans;

	for(int s=0;s<4;++s){
		if(v[s]){
			vector<int>rest(v);
			solve(s,rest,ans);
			if(ans.size()==v[0]+v[1]+v[2]+v[3]){
				break;
			}
		}
		ans.clear();

	}
	if(ans.size()==v[0]+v[1]+v[2]+v[3]){
		cout<<"YES"<<endl;
		for(auto an:ans)cout<<an<<' ';
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}