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


int main() {
	ios::sync_with_stdio(false);
	ll M;
	int N;cin>>M>>N;

	vector<pair<ll,int>>as,bs;
	for(int i=0;i<N;++i){
		ll a;cin>>a;
		as.emplace_back(a,i);
	}
	for(int i=0;i<N;++i){
		ll a;cin>>a;
		bs.emplace_back(a,i);
	}
	sort(as.begin(),as.end());
	sort(bs.begin(),bs.end());
	for(int i=0;i<2*N;++i){
		bs.emplace_back(bs[i]);
		bs.back().first+=M;
	}
	vector<ll>pluss(3*N+1);
	for(int i=0;i<N;++i){
		as[i].first+=M;
		pluss[0]+=as[i].first;
	}
	for(int i=0;i<N;++i){
		pluss[0]-=bs[i].first;
		pluss[i+1]+=bs[i].first;
	}
	for(int i=0;i<N;++i){
		pluss[i+1]-=bs[N+i].first;
	}
	for(int i=0;i<N;++i){
		pluss[i+N+1]+=bs[2*N+i].first;
	}
	//WHATS(pluss)
	int pos=N;
	for(int i=0;i<N;++i){
		while(bs[pos].first<as[i].first)pos++;
		pluss[pos-i]-=2*as[i].first;
	}
	pos=0;
	for(int i=N;i<2*N;++i){
		while(pos<N&&as[pos].first<=bs[i].first){
			pos++;
		}
		pluss[i-pos+1]+=bs[i].first*2;
		pluss[i+1]-=bs[i].first;
	}
	//WHATS(pluss)
	pos=0;
	
	for(int i=0;i<3*N;++i){
		pluss[i+1]+=pluss[i];
	}
	pair<ll,int>ap(ll(1e18),-1);
	for(int i=0;i<=3*N;++i){
		ap=min(ap,make_pair(pluss[i],i));
	}
	int id=ap.second;
	ll sum=0;
	cout<<ap.first<<endl;
	vector<int>answers(N);
	for(int i=0;i<N;++i){
		answers[as[i].second]=bs[(id+i)].second;
	}
	for(int i=0;i<N;++i){
		cout<<answers[i]+1<<' ';

	}
	cout<<endl;
	

	return 0;
}