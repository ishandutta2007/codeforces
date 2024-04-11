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


const int MAX_H=10000;
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int N,L,R;cin>>N>>L>>R;
	vector<int>dp(MAX_H+1,false);
	vector<int>imps;
	{
		vector<int>as,bs;
		for(int i=0;i<N;++i){
			int a;cin>>a;
			as.push_back(a);
		}
		for(int i=0;i<N;++i){
			int a;cin>>a;
			bs.push_back(a);
		}
		vector<int>oths;
		for(int i=0;i<N;++i){
			if(bs[i])imps.push_back(as[i]);
			else oths.push_back(as[i]);
		}
		dp[0]=true;
		for(auto ot:oths){
			for(int i=MAX_H;i>=0;--i){
				if(dp[i]){
					dp[i+ot]=true;
				}
			}
		}
		sort(imps.begin(),imps.end());
	}
	//WHATS(dp)
	vector<int>sums;
	sums.push_back(0);
	for(int id=0;id<imps.size();++id){
		sums.push_back(sums.back()+imps[id]);
	}
	sums.erase(sums.begin());
	int answer=0;

	vector<vector<int>>dps(2,vector<int>(MAX_H+1));
	dps[0]=dp;
	for(int h=L;h<=R;++h){
		if(dps[0][h]){
			auto it=upper_bound(sums.begin(),sums.end(),R-h);
			if(it!=sums.end()){
				answer=max(answer,it-sums.begin()+1);
			}else{
				answer=max(answer,it-sums.begin());	
			}
		}
		if(dps[1][h]){
			auto it=upper_bound(sums.begin(),sums.end(),R-h);
			{
				answer=max(answer,it-sums.begin()+1);	
			}
		}
	}
	for(int id=int(imps.size())-1;id>=0;--id){
		//WHATS(dps)
		for(int i=MAX_H;i>=0;--i){
			if(dps[1][i]){
				if(i+imps[id]<=10000)dps[1][i+imps[id]]=true;
			}
			if(dps[0][i]){
				if(i+imps[id]<=10000)dps[0][i+imps[id]]=true;
				dps[1][i]=true;
			}
		}
		sums.pop_back();
		for(int h=L;h<=R;++h){
			if(dps[0][h]){
				auto it=upper_bound(sums.begin(),sums.end(),R-h);
				if(it!=sums.end()){
					answer=max(answer,it-sums.begin()+1);
				}else{
					answer=max(answer,it-sums.begin());	
				}
				break;
			}
		}
		for(int h=L;h<=R;++h){
		
			if(dps[1][h]){
				auto it=upper_bound(sums.begin(),sums.end(),R-h);
				{
					answer=max(answer,it-sums.begin()+1);	
				}
			}
		}
	}
	//WHATS(dps)
	cout<<answer<<endl;
	
	return 0;
}