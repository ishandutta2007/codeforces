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
    int N;cin>>N;
    vector<vector<vector<ll>>>memo(2,vector<vector<ll>>(65,vector<ll>(65)));

    ll answer=0;
    int now=0;
    int sum=0;
    for(int kk=0;kk<N;++kk){
        int cur=kk&1;
        int tar=1-cur;
        ll aa;cin>>aa;
        int cnt=__builtin_popcountll(aa);
        sum+=cnt;
        memo[cur][0][0]++;
        //WHATS(kk)
        for(int i=0;i<=64;++i){
            for(int j=i;j<=64;++j){
                if(memo[cur][i][j]==0)continue;
                //WHATS(i)
                //WHATS(j)
                int x,y;
                if(i<=cnt && cnt<=j){
                    x=0;
                }else{
                    if(cnt<i){
                        x=i-cnt;
                    }else{
                        assert(j<cnt);
                        x=cnt-j;
                    }
                }
                y=min(64,j+cnt);
                
                if(i%2!=cnt%2){
                    if(x==0)x=1;
                    y=min(63,y);
                }
                //WHATS(x)
                //WHATS(y)
               // WHATS(memo[cur][i][j])
                if(x==0)answer+=memo[cur][i][j];
                memo[tar][x][y]+=memo[cur][i][j];
            }
        }
        for(int i=0;i<=64;++i){
            for(int j=i;j<=64;++j){
                memo[cur][i][j]=0;
            }
        }
        //WHATS(answer)
    }
    cout<<answer<<endl;
	return 0;
}