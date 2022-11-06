#define _CRT_SECURE_NO_WARNINGS
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
#include<numeric>
/*
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
    
using namespace std;
    
using ll=long long;
using ld =long double;
    
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
using Graph=vector<vector<int>>;

vector<int>gp(){
    const int MAX_N=300000;
    vector<int>is_primes(MAX_N+1,true);
    vector<int>v;
    for(int i=2;i*i<=MAX_N;++i){
        if(is_primes[i]){
            v.push_back(i);
            for(ll j=i;j*j<=MAX_N;j+=i){
                is_primes[j]=false;
            }
        }
    }
    return v;
}

int main() {
    //for(int i=0;i<int(1e6)+1;++i)have_rs[i]=-1;
    // for(int i=0;i<(1<<21);++i)as[i]=-1;
    ios::sync_with_stdio(false);
    cin.tie();
    int T;cin>>T;
    while(T--){
        int N,K;cin>>N>>K;
        vector<int>v(N);
        vector<pair<int,int>>ps;
        bool flag=false;
        for(int i=0;i<N;++i){
            cin>>v[i];
            ps.emplace_back(v[i],i);
            if(v[i]==K)flag=true;
        }
        sort(ps.begin(),ps.end(),greater<pair<int,int>>());
        bool ok=false;
        for(auto p:ps){
            int i=p.second;
            int num=p.first;
            if(num<K)continue;
            {
                if(i&&v[i-1]>=num)ok=true;
                if((i!=N-1)&&v[i+1]>=num)ok=true;
            }
            
        }
        for(int i=1;i<N-1;++i){
            if(i&&(i!=N-1)){
                if(v[i-1]>=K&&v[i+1]>=K)ok=true;
            }
        }
        if(N==1)ok=true;
        if(flag&&ok)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}
// 0 1 2 3 4  5  6  7
// 0 2 3 1 8  10 11 9
// 0 3 1 2 12 15 13 14