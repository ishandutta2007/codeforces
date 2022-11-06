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
using ld = __float128;
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

int MAX_N=1000000;
vector<int>min_divs(MAX_N+1);
vector<int>primes;
vector<int>cnts(MAX_N+1);
void init(){
	min_divs[0]=-1;
	min_divs[1]=1;
	for(ll i=2;i<=MAX_N;++i){
		if(min_divs[i]==0){
			min_divs[i]=i;
			for(ll j=i*i;j<=MAX_N;j+=i){
				if(min_divs[j]==0)min_divs[j]=i;
			}
		}
	}
	for(int i=2;i<=MAX_N;++i){
		if(min_divs[i]==i)primes.push_back(i);
	}

	for(int k=3;k<=MAX_N;++k){
		set<int>adiv;
		int rest=k;
		while(rest!=1){
			int d=min_divs[rest];
			rest/=d;
			adiv.emplace(d);
		}
		int answer=k;
		for(auto d:adiv){
			answer/=d;
			answer*=(d-1);
		}
		cnts[k]=answer;
	}
	cnts[4]++;
	
}

int main() {
	ios::sync_with_stdio(false);
	int N,K;cin>>N>>K;
	init();
	vector<int>v(cnts.begin()+3,cnts.begin()+N+1);
	//WHATS(v)
	sort(v.begin(),v.end());
	ll answer=accumulate(v.begin(),v.begin()+K,0ll);
	if(K==2)answer=5;
	cout<<1+answer<<endl;
	return 0;
}