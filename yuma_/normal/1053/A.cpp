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
map<ll,int>get_mp(ll x){
    map<ll,int>mp;
    for(int i=2;i*i<=x;++i){
        while(x%i==0){
            mp[i]++;
            x/=i;
        }
    }
    if(x!=1)mp[x]++;
    return mp;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
    ll N,M,K;cin>>N>>M>>K;
    if((N*M*2)%K==0){
        cout<<"YES"<<endl;
        ll y=2*M;
        ll x=N;

        ll rest=K;
        map<ll,int>rest_mp(get_mp(rest));
        for(auto m:rest_mp){
            //WHATS(m)
            while(m.second){
                if(y%m.first==0){
                    y/=m.first;
                    m.second--;
                }
                else if(x%m.first==0){
                    x/=m.first;
                    m.second--;
                }
            }
        }
        //WHATS(y)
        //WHATS(x)
        if(y>M){
            assert(y%2==0);
            assert(x*2<=N);
            y/=2;
            x*=2;
        }
        cout<<0<<' '<<0<<endl;
        cout<<0<<' '<<y<<endl;
        cout<<x<<' '<<0<<endl;
    }else{
        cout<<"NO"<<endl;
    }
	return 0;
}