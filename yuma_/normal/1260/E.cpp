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
using ll=long long ;

ll int_pow(ll a,ll b){
	if(b==0)return 1;
	else{
		ll k=int_pow(a,b/2);
		k*=k;
		if(b%2)k*=a;
		return k;
	}
}
int main() {
	ios::sync_with_stdio(false);
	int N;cin>>N;
	vector<int>v(N);
	int place=-1;
	for(int i=0;i<N;++i){
		cin>>v[i];
		if(v[i]==-1){
			place=i;
		}
	}
	int M=0;
	int k=1;
	while(k!=N){
		k*=2;
		M++;
	}
	vector<vector<ll>>dp(N+1,vector<ll>(M+1,ll(1e18)));
	vector<ll>sums(M+1);
	sums[0]=0;
	for(int i=0;i<M;++i){
		sums[i+1]=sums[i]+int_pow(2,i+1)-1;
	}
	dp[0][0]=0;
	for(int i=0;i<N;++i){
		for(int use=0;use<=M;++use){
			if(i==place){
				dp[i+1][use]=dp[i][use];
			}else{
				if(i<place){
					int unuse=i-use;
					if(unuse<0)continue;
					ll need=sums[use];
					if(need<=unuse){
						dp[i+1][use+1]=min(dp[i+1][use+1],dp[i][use]);
					}
					dp[i+1][use]=min(dp[i+1][use],dp[i][use]);
				}else{
					int unuse=i-use-1;
					if(unuse<0)continue;
					ll need=sums[use];
					if(need<=unuse){
						dp[i+1][use+1]=min(dp[i+1][use+1],dp[i][use]+v[i]);
					}
					dp[i+1][use]=min(dp[i+1][use],dp[i][use]);
				}
			}
		}
	}
	//WHATS(dp)
	//WHATS(sums)
	cout<<dp[N][M]<<endl;
	return 0;
}