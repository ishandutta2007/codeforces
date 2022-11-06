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
void solveB(){
    int N;cin>>N;
    map<int,int>mp;
    for(int i=0;i<N;++i){
        int a;cin>>a;
        mp[a]++;
    }
    auto it=prev(mp.end());

    bool awin=false;
    awin=false;
    for(auto m:mp){
        if(m.second%2==1)awin=true;
    }
    if(awin)cout<<"Conan"<<endl;
    else cout<<"Agasa"<<endl;
}

vector<vector<vector<ll>>>dp;
bool flag=false;
ll solve(string st,int cnt){
    if(st.size()<cnt)return 0;
    const int mod=1e9+7;
    if(!flag){
        flag=true;
        dp[0][0][1]=true;
        for(int now=0;now<st.size();++now){
            for(int use=0;use<=now;++use){
                for(int same=0;same<2;++same){
                    for(int now_use=0;now_use<2;++now_use){
                        int nextsame=same;
                        if(same){
                            if(st[now]=='1'){
                                if(now_use)nextsame=true;
                                else nextsame=false;
                            }else{
                                if(now_use)continue;
                                else nextsame=true;
                            }
                        }else{
                            nextsame=false;
                        }
                        dp[now+1][use+now_use][nextsame]+=dp[now][use][same];
                        dp[now+1][use+now_use][nextsame]%=mod;
                    }
                }
            }
        }
        //WHATS(dp)
        flag=true;
    }
    
    return (dp[st.size()][cnt][0]+dp[st.size()][cnt][1])%mod;
}
void solveC(){
    string st;cin>>st;
    dp=vector<vector<vector<ll>>>(st.size()+1,vector<vector<ll>>(st.size()+1,vector<ll>(2)));
    vector<int>cnts(1001);
    cnts[1]=0;
    for(int i=2;i<=1000;++i){
        int k=__builtin_popcount(i);
        cnts[i]=cnts[k]+1;
    }
    //WHATS(cnts)
    int K;cin>>K;
    ll answer=0;
    for(int i=1;i<=1000;++i){
        if(cnts[i]==K-1){
            ll plus=solve(st,i);
            answer+=plus;
        }
    }
    const ll mod=1e9+7;
    answer%=int(1e9+7);
    if(K==0)answer=1;
    if(K==1)answer+=mod-1;
    answer%=mod;
    cout<<answer<<endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
    solveB();
    // int N;cin>>N;
    // vector<int>as(N);
    // ll answer=-1e9;
    // for(int i=0;i<N;++i){
    //    ll a;cin>>a;
    //     if(a<0)answer=max(answer,a);
    //     else{
    //         int xx=sqrt(a);
    //         if(ll(xx)*xx==a){

    //         }else{
    //             answer=max(answer,a);
    //         }
    //     }
    // }
    // cout<<answer<<endl;
	return 0;
}