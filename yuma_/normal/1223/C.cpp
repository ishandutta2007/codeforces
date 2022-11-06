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
ll gcd (ll a,ll b){
	if(a%b)return gcd(b,a%b);
	else{
		return b;
	}
}
int main() {
	
	ios::sync_with_stdio(false);
	int Q;cin>>Q;
	while(Q--){
		int N;cin>>N;
		vector<ll>prices(N);
		for(int i=0;i<N;++i){
			cin>>prices[i];
			prices[i]/=100;
		}
		sort(prices.begin(),prices.end(),greater<ll>());
		vector<ll>sums(N+1);
		for(int i=1;i<=N;++i){
			sums[i]=sums[i-1]+prices[i-1];
		}
		ll x,a;
		ll y,b;
		cin>>x>>a>>y>>b;
		if(x<y){
			swap(x,y);
			swap(a,b);
		}
		ll alca=a*b/gcd(a,b);
		ll ok=N+1;
		ll ng=0;
		ll K;cin>>K;
		while(ng+1!=ok){
			ll amid((ng+ok)/2);
			ll ab_cnt=amid/alca;
			ll a_cnt=amid/a-ab_cnt;
			ll b_cnt=amid/b-ab_cnt;

			ll sum=(x+y)*(sums[ab_cnt]-sums[0]);
			sum+=x*(sums[ab_cnt+a_cnt]-sums[ab_cnt]);
			sum+=y*(sums[ab_cnt+a_cnt+b_cnt]-sums[ab_cnt+a_cnt]);
			//WHATS(sum)
			//WHATS(amid)
			if(sum>=K)ok=amid;
			else ng=amid;
		}
		if(ok==N+1){
			ok=-1;
		}
		cout<<ok<<endl;
	}
	return 0;
}