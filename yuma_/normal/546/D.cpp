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

#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;
using Graph=vector<vector<int>>;
	
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
const int MAX_N=5000000;
    vector<int>min_divs(MAX_N+1);

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie();
    for(int i=2;i<=MAX_N;++i){
        if(min_divs[i]==0){
            min_divs[i]=i;
            for(ll j=ll(i)*i;j<=MAX_N;j+=i){
                if(min_divs[j]==0)min_divs[j]=i;
            }
        }
    }
    //WHATS(min_divs)
    vector<int>cnts(MAX_N+1);
    for(int i=1;i<=MAX_N;++i){
        int now(i);
        while(now!=1){
            now/=min_divs[now];
            cnts[i]++;
        }
    }
    //WHATS(cnts)
    vector<int>sums(MAX_N+2);
    for(int i=1;i<=MAX_N;++i){
        sums[i]=sums[i-1]+cnts[i];
    }
    int T;cin>>T;
    while(T--){
        int a,b;scanf("%d %d",&a,&b);
       printf("%d\n",sums[a]-sums[b]);
    }
	return 0;
}