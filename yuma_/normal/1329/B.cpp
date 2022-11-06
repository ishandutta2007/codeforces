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




map<vector<int>,int>get_mp(int N){
    map<vector<int>,int>mp;
    for(int id=0;id<(1<<(N-1));++id){
        int num=0;
        vector<int>v;
        num=1;
        for(int i=0;i<N-1;++i){       
            if(id&(1<<i)){
                num++;
            }else{
                v.push_back(num);
                num=1;
            }
        }
        if(num)v.push_back(num);
        sort(v.begin(),v.end());
        mp[v]++;
    }
    return mp;
}

vector<ll>answers;
void dfs(int used,int last){

}


int main() {
     ios::sync_with_stdio(false);
     cin.tie();
    int T;cin>>T;
    while(T--){
        ll D,mod;cin>>D>>mod;
        vector<ll>nums;
        {
            ll l=1;
            ll r=2;
            while(l<=D){
                nums.push_back(min(r-l,D-l+1));
                l=r;
                r=2*r;
            }
        }

        vector<ll>answers;
        answers.push_back(1);
        ll sum=1;
        for(int i=1;i<nums.size();++i){
            sum=(sum+1)*(nums[i]+1)-1;
            sum%=mod;

        }
        sum%=mod;
        cout<<sum<<endl;
    }
    return 0;
}