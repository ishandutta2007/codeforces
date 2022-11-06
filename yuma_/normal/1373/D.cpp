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

    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        vector<ll>as(N);
        for(int i=0;i<N;++i)cin>>as[i];

        ll odd_min=2e9;
        ll even_min=2e9;
        even_min=0;

        ll max_plus=0;
        ll answer=0;
        ll sum=0;
        ll odd_sum=0;
        ll even_sum=0;
        for(int i=0;i<N;++i){
            

            if(i%2==0){
                answer+=as[i];
                odd_sum+=as[i];
                even_sum-=as[i];
                odd_min=min(odd_min,-odd_sum);

                max_plus=max(max_plus,-odd_sum-odd_min);
            }else{
                even_sum+=as[i];
                odd_sum-=as[i];
                even_min=min(even_min,even_sum);

                max_plus=max(max_plus,even_sum-even_min);
            }
        }
        cout<<answer+max_plus<<endl;
    }
	return 0;
}