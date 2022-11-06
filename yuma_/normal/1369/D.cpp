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

void check(){
    for(int N=10;N<=110;++N){
        vector<int>v(3*N+1,1);
        for(int j=N;j>=1;--j){
            if((v[j+1]==false)||(v[2*j]==false)){
                v[j]=true;
            }else{
                v[j]=false;
            }
        }
        cout<<N<<endl;
        for(int i=0;i<=N;++i){
            char ch='0'+i;
            if(i>=10)ch='a'+(i-10);

            cout<<ch;
        }
        cout<<endl;
        for(int i=0;i<=N;++i){
            if(i==0)cout<<'x';
            else cout<<v[i];
        }
        cout<<endl;
    }
}

bool solve(ll awin,ll S){
    while(true){
        if(awin<=S)return true;
        else{
            if(awin%2==0){
                return !((awin-S)%2);
            }else{
                ll nwin=(awin+3)/4;
                ll nlose=(awin+1)/2;
                if(nlose<=S)return !((awin-S)%2);
                else if(nwin<=S)return true;

                awin=nwin;
            }
        }
    }
}
const ll mod=1e9+7;
const int MAX_N=2200000;
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
    vector<vector<ll>>dp(MAX_N,vector<ll>(2));
    vector<ll>dp2(MAX_N);


    dp[1][0]=0;
    dp[1][1]=0;
    vector<int>fl{0,0,0,1,-1,1};
    for(int i=3;i<MAX_N;++i){
        dp[i][0]=2*max(dp[i-2][0],dp[i-2][1])+max(dp[i-1][0],dp[i-1][1]);
        dp[i][1]=1+2*dp[i-2][0]+dp[i-1][0];


        dp[i][0]%=mod;
        dp[i][1]%=mod;

        dp2[i]=dp2[i-1]*2+fl[i%6];
        dp2[i]%=mod;
    }
    //WHATS(dp)
    //WHATS(dp2)

    int T;cin>>T;
    while(T--){
        int a;cin>>a;
        cout<<dp2[a]*4%mod<<endl;
    }
	return 0;
}