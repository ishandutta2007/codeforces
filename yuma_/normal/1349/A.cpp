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
    int N;cin>>N;
    vector<int>primes=gp();
   // WHATS(primes)

    map<int,vector<int>>mp;
    map<int,int>cnts;
    for(int i=0;i<N;++i){
        int a;cin>>a;
        map<int,int>nums;
        for(auto pr:primes){
            
            if(pr*pr>a){
                if(a!=1)nums[a]++;
                break;
            }else{
                while(true){
                    if(a%pr==0){
                        nums[pr]++;
                        a/=pr;
                    }else{
                        break;
                    }
                }
                
            }
        }
        for(auto n:nums){
            mp[n.first].push_back(n.second);
            sort(mp[n.first].begin(),mp[n.first].end());
            cnts[n.first]++;

            if(mp[n.first].size()>=3){
                mp[n.first].pop_back();
            }
        }
    }
    
    ll answer=1;
    for(auto m:mp){
       // WHATS(m)
        if(cnts[m.first]==N){
            for(int i=0;i<mp[m.first][1];++i){
                answer*=m.first;
            }
        }else if(cnts[m.first]==N-1){
            for(int i=0;i<mp[m.first][0];++i){
                answer*=m.first;
            }
        }
    }
    cout<<answer<<endl;
    return 0;
}
// 0 1 2 3 4  5  6  7
// 0 2 3 1 8  10 11 9
// 0 3 1 2 12 15 13 14