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

	
using ll = long long int;
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	{
		int N,M;cin>>N>>M;
		ll X,Y;
		int K;
		cin>>X>>K>>Y;
		vector<int>as(N);
		map<int,int>places;
		for(int i=0;i<N;++i){
			cin>>as[i];
			places[as[i]]=i;
		}
		vector<int>remains(M);
		bool ok=true;
		for(int i=0;i<M;++i){
			int id;cin>>id;
			if(places.find(id)==places.end()){
				ok=false;
			}else{
				remains[i]=places[id];
				if(i&&remains[i-1]>remains[i]){
					ok=false;
				}
			}
		}
		ll answer=0;
		if(ok){
			for(int i=0;i<=M;++i){
				int l,r;
				int side_power(0);
				if(i==0){
					l=0;
				}else{
					l=remains[i-1]+1;
					side_power=max(side_power,as[l-1]);
				}
				if(i==M){
					r=N-1;
					
				}else{
					r=remains[i]-1;
					side_power=max(side_power,as[r+1]);
				}
				int strong_cnt=0;
				for(int x=l;x<=r;++x){
					if(as[x]>side_power)strong_cnt++;
				}
				int sz=r-l+1;
				int amod=sz%K;
				ll nanswer=1e16;
				for(ll fire_cnt=0;fire_cnt*K<=sz;++fire_cnt){
					ll ber_cnt=sz-fire_cnt*K;
					if(fire_cnt==0&&strong_cnt){
						continue;
					}else{
						nanswer=min(nanswer,fire_cnt*X+ber_cnt*Y);
					}
				}
				if(nanswer>=1e15)ok=false;
				answer+=nanswer;
			}
		}
		if(ok){
			cout<<answer<<endl;
		}else{
			cout<<-1<<endl;
		}
	}
	
	return 0;
}