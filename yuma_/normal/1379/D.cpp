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
using Graph=vector<vector<pair<int,int>>>;
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

int N,H,M,K;
int ans_time;
set<int>answer;
pair<int,int> solve(map<int,vector<int>>mp,int flag=-int(2e9)){
	pair<int,int>ans(11424341,-1);
	set<int>er_ids;
	for(auto m:mp){
		auto v=m.second;
		if(0<=m.first&&m.first<M){
			ans=min(ans,make_pair(int(er_ids.size()),m.first));
		}
		//WHATS(ans)
		if(flag==m.first){
			answer=er_ids;
			ans_time=m.first+K-1;
			ans_time%=M;
			if(ans_time<0)ans_time+=M;
			

			return ans;
		}
		for(auto x:v){
			if(x<0){
				er_ids.erase(-x);
			}else{
				er_ids.insert(x);
			}
		}
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie();cin>>N>>H>>M>>K;
	M/=2;
	map<int,vector<int>>mp;
	for(int i=0;i<N;++i){
		int h,m;cin>>h>>m;
		m%=M;
		mp[m-K+1].push_back(i+1);
		mp[m].push_back(-i-1);
		mp[m-K+1+M].push_back(i+1);
	}
	for(auto &m:mp){
		sort(m.second.begin(),m.second.end());
		//WHATS(m)
	}
	mp[0];
	mp[M-1];
	auto p=solve(mp);
	solve(mp,p.second);
	
	cout<<answer.size()<<' '<<ans_time<<endl;
	for(auto an:answer){
		cout<<an<<' ';
	}
	cout<<endl;

	
	
	return 0;
}