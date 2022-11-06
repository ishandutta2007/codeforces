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


ll gcd(ll a,ll b){
	if(a==0||b==0){
		return max(a,b);
	}
	if(a%b==0)return b;
	else return gcd(b,a%b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int N;cin>>N;
	vector<vector<int>>vals(N,vector<int>(5));
	vector<int>solver_cnts(5);
	vector<int>now_scores(5);
	vector<vector<ll>>costs(5,vector<ll>(6));
	for(int i=0;i<N;++i){
		for(int j=0;j<5;++j){
			int a;cin>>a;
			if(a==-1)vals[i][j]=0;
			else {
				vals[i][j]=250-a;
				solver_cnts[j]++;
			}
		}
	}
	for(int j=0;j<5;++j){
		int cnt=solver_cnts[j];
		int id=1;
		for(int k=0;k<6;++k){
			cnt*=2;
			if(cnt<=N){
				if(k!=5)costs[j][k]=(N-cnt)/id+1;
				else costs[j][k]=0;

			}else{
				costs[j][k]=max(0,cnt/2-N);
			}
			id=id*2+1;

			if(costs[j][k]==0){
				now_scores[j]=k;
			}
		}
		if(vals[0][j]==0){
			for(int k=0;k<now_scores[j];++k){
				costs[j][k]=ll(1e18);
			}
		}
	}
	ll answer=1e18;
	for(int id=0;id<(216*36);++id){
		vector<int>v(5);
		int tt=id;
		bool ok=true;
		ll plus=0;
		ll cost=0;
		for(int j=0;j<5;++j){
			v[j]=tt%6;
			tt/=6;
			if(vals[0][j]==0){

			}
			else{	
				plus+=(vals[0][j]-vals[1][j])*(1+v[j])*2;
				cost=max(cost,costs[j][v[j]]);
			}
		}
		for(int j=0;j<5;++j){
			if(vals[0][j]==0){
				int ascore=5;
				for(int k=now_scores[j]+1;k<6;++k){
					if(costs[j][k]>cost){
						ascore=k-1;
						break;
					}
				}

				plus+=(vals[0][j]-vals[1][j])*(1+ascore)*2;

			}
		}
		if(ok&&plus>0){
			// if(cost==1){
			// 	WHATS(v)
			// 	WHATS(plus)
			// }
			answer=min(answer,cost);
		}
	}
	//WHATS(costs)
	//WHATS(vals)
	if(answer>ll(1e17)){
		answer=-1;
	}
	cout<<answer<<endl;

	
	return 0;
}