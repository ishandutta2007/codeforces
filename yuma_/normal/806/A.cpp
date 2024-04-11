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
	int T;cin>>T;
	while(T--){
		ll x,y,p,q;cin>>x>>y>>p>>q;
		ll at=gcd(p,q);
		p/=at;
		q/=at;

		

		ll answer=-1;
		if(p==1&&q==1){
			if(x==y){
				answer=0;
			}else{
				answer=-1;
			}
		}else if(p==0&&q==1){
			if(x==0){
				answer=0;
			}else{
				answer=-1;
			}
		
		}else{
			if(x*q<y*p){
			x=y-x;
			p=q-p;
		}
			ll need1=(p-(x%p))%p;

			ll ax=x+need1;
			ll ay=y+need1;
			ll ap=ax;
			ll aq=q*ax/p;
			
			if(ay<=aq){
				answer=need1+(aq-ay);
			}else{
				assert(false);
			}
		}
		cout<<answer<<endl;
		
	}
	
	return 0;
}