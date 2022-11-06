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

using ll = long long int;
using Hash=pair<ll,ll>;
static const ll mul0 = 10009, mul1 = 10007;
static const ll add0 = 1000010007, add1 = 1003333331;
static const ll mod0 = 1000000007, mod1 = 1000000009;

void add(vector<Hash>& hs,int x){
	Hash ah=hs.back();
	ah.first=(ah.first*mul0+add0+x)%mod0;
	ah.second=(ah.second*mul1+add1+x)%mod1;
	hs.push_back(ah);
}	

int main() {
	ios::sync_with_stdio(false);
	int N;cin>>N;
	int K;cin>>K;
	vector<int>v(N);
	for(int i=0;i<N;++i)cin>>v[i];
	int ans=0;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			if(abs(v[i]-v[j])<=K)ans++;
		}
	}
	cout<<ans-N<<endl;
	return 0;
}