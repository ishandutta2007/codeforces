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

ll powll(ll a,ll b){
	if(b==0)return 1;
	else{
		ll x=powll(a,b/2);
		x*=x;
		x%=mod;
		if(b%2)x*=a;
		x%=mod;
		return x;
	}
}
int main() {
	
	ios::sync_with_stdio(false);
	cin.tie();
	int N,M;cin>>N>>M;
	vector<vector<ll>>vs(2,vector<ll>(M+1));
	vs[0][0]=1;
	int cur=0,tar=1;
	for(int i=0;i<M;++i){

		for(int j=0;j<=i;++j){
			vs[tar][j]+=vs[cur][j]*j;
			vs[tar][j+1]+=vs[cur][j]*(N-j);
		}
		for(int j=0;j<=i+1;++j){
			vs[cur][j]=0;
			vs[tar][j]%=mod;
		}
		swap(cur,tar);
	}
	//WHATS(vs[cur]);
	ll answer=0;
	ll mul=2;
	for(int i=M;i>=0;--i){
		if(i>N)continue;
		else{
			answer+=powll(2,N-i)*vs[cur][i];
			answer%=mod;
		}
	}
	cout<<answer<<endl;

	return 0;
}