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
const int MAX_N=3e5;
vector<int>min_divs(MAX_N+1,1);
vector<int>primes;
void init(){
    for(int i=2;i<=MAX_N;++i){
        if(min_divs[i]==1){
            min_divs[i]=i;
            for(ll j=ll(i)*i;j<=MAX_N;j+=i){
                min_divs[j]=i;
            }
        }
        if(min_divs[i]==i){
            primes.push_back(i);
        }
    }
}
int div_cnt(int x){
    map<int,int>mp;
    while(x!=1){
        mp[min_divs[x]]++;
        x/=min_divs[x];
    }
    int cnt=1;
    for(auto m:mp)cnt*=m.second+1;
    return cnt;
}
vector<int> solve(int N, ll K){
    int amax=1;
    ll sum=0;
    for(int i=1;i<=N;++i){
        sum+=div_cnt(i)-1;
        amax=i;
        if(sum>=K)break;
    }
    // WHATS(K)
    // WHATS(sum)
    // WHATS(amax)
    if(sum<K)return vector<int>();
    else{
        vector<int>uses(N+1);
        for(int i=1;i<=amax;++i)uses[i]=true;
        for(int x=amax;x>=1;--x){
            if(sum==K)break;
            int cnt=div_cnt(x)-1;
            if(sum-cnt>=K){
                sum-=cnt;
                uses[x]=false;
            }
        }
        vector<int>v;
        for(int i=1;i<=N;++i){
            if(uses[i])v.push_back(i);
        }
        return v;
    }
}
vector<vector<int>>anss{
    {1},
    {1,2},
    {1,2,3},
    {1,2,4},
    {1,2,3,4},
    {1,2,3,4,5},
    {1,2,4,5,6},//6
    {1,2,3,4,6},//7
    {1,2,3,4,5,6},//8

};
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
    init();
    int N,K;cin>>N>>K;
    vector<int>answers;
    if(K<=7){
        if(N<anss[K].back()){
            
        }else{
            answers=anss[K];
        }
    }else{
        answers=solve(N,K);
    }
    if(answers.empty())cout<<"No"<<endl;
    else{
        cout<<"Yes"<<endl;
        cout<<answers.size()<<endl;
        for(auto aa:answers)cout<<aa<<' ';
        cout<<endl;
    }


	return 0;
}