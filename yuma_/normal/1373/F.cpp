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

int solve(const vector<int>&as,const vector<int>&bs,int power){
    for(int i=1;i<as.size();++i){
        if(power+bs[i]<as[i])return -1;
        else {
            power=min(bs[i],power+bs[i]-as[i]);
        }
    }
    return power;
}
int main() {
	int T;cin>>T;
    while(T--){
        int N;cin>>N;
        vector<int>as(N),bs(N);
        for(int i=0;i<N;++i)scanf("%d",&as[i]);
        for(int i=0;i<N;++i)scanf("%d",&bs[i]);
        int ret=solve(as,bs,bs[0]);
        bool ok=false;
        if(ret>=as[0])ok=true;
        else if(ret!=-1){
            int need=as[0]-ret;
            if(need<=bs[0]){
                int ret2=solve(as,bs,bs[0]-need);
                if(ret2>=as[0]-need){
                    ok=true;
                }
            }
            
        }
        if(ok)printf("YES\n");
        else printf("NO\n");
    }
	return 0;
}