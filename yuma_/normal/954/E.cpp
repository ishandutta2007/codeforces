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
	int N;
	ld T;cin>>N>>T;
	vector<pair<ld,ld>>ps(N);
	ld total_w=0,total_h=0;
	for(int i=0;i<N;++i){
		int a;cin>>a;
		ps[i].second=a;
		total_w+=a;
	}
	for(int i=0;i<N;++i){
		int a;cin>>a;
		a-=T;
		ps[i].first=a;
		total_h+=ps[i].first*ps[i].second;
	}
	sort(ps.begin(),ps.end());
	ld answer=total_w;
	//WHATS(total_w)
	//WHATS(total_h)
	if(total_h>0){
		
		for(int i=N-1;i>=0;--i){
			ld dt=ps[i].first;
			if(!dt)continue;
			ld use=min(total_h/dt,ps[i].second);
			total_h-=use*dt;
			answer-=use;
		}
	}else{
		for(int i=0;i<N;++i){
			ld dt=ps[i].first;
			if(!dt)continue;

			ld use=min(total_h/dt,ps[i].second);
			total_h-=use*dt;
			answer-=use;
		}
	}

	cout<<setprecision(10)<<fixed<<answer<<endl;
	return 0;
}