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
int xx;

using ll =long long ;

int gcd(int a,int b){
	if(a%b)return gcd(b,a%b);
	else return b;
}
int main() {
	ios::sync_with_stdio(false);
	int N;ll K;cin>>N>>K;
	vector<ll>v(N);
	for(int i=0;i<N;++i)cin>>v[i];
	vector<vector<ll>>dp(N+1,vector<ll>(4,-1e18));
	dp[0][0]=0;
	ll answer=0;
	for(int i=0;i<N;++i){
		for(int use=0;use<4;++use){
			for(int n_use=use;n_use<4;++n_use){
				ll sum=dp[i][use];
				if(n_use==1)sum+=v[i];
				else if(n_use==2)sum+=K*v[i];
				else if(n_use==3)sum+=v[i];

				dp[i+1][n_use]=max(sum,dp[i+1][n_use]);
				answer=max(answer,dp[i+1][n_use]);
			}
		}
	}
	cout<<answer<<endl;
	return 0;	
}