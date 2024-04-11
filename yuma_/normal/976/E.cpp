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


const int MAX_X=2220;

using ll=long long ;

struct Edge{
	int src;
	int dst;
	int id;
};
using Graph=vector<vector<Edge>>;
int main() {
	ios::sync_with_stdio(false);
	int N,A,B;cin>>N>>A>>B;
	vector<pair<ll,ll>>pluss(N);
	ll abase=0;
	for(int i=0;i<N;++i){
		ll hp,da;cin>>hp>>da;
		abase+=da;
		ll val=hp<<A;

		ll n_plus=max(0ll,hp-da);
		ll val_plus=max(0ll,val-da);
		pluss[i]=make_pair(n_plus,val_plus-n_plus);
	}
	sort(pluss.begin(),pluss.end(),greater<pair<ll,ll>>());
	ll normal=0;
	for(int i=0;i<min(N,B);++i){
		normal+=pluss[i].first;
	}
	ll answer=normal;
	//WHATS(normal)
	if(B){
		for(int i=0;i<N;++i){
		normal+=max(0ll,pluss[i].second);
		if(i>=B&&B){
			normal+=pluss[i].first;
			normal-=pluss[B-1].first;
		}
		//WHATS(normal)
		answer=max(answer,normal);
		normal-=max(0ll,pluss[i].second);;
		if(i>=B&&B){
			normal-=pluss[i].first;
			normal+=pluss[B-1].first;
		}

	}
	}
	cout<<abase+answer<<endl;
	return 0;
}