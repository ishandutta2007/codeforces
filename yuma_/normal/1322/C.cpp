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
 
 
const int mod = 998244353;



bool operator<(const vector<int>&lv,const vector<int>&rv){
    
    if(lv.size()!=rv.size()){
        return lv.size()<rv.size();
    }else{
        for(int i=0;i<lv.size();++i){
            if(lv[i]!=rv[i]){
                return lv[i]<rv[i];
            }
        }
        return false;
    }
}

ll gcd(ll a,ll b){
    if(a%b==0)return b;
    else{
        return gcd(b,a%b);
    }
}
int main() {
    //for(int i=0;i<int(1e6)+1;++i)have_rs[i]=-1;
    // for(int i=0;i<(1<<21);++i)as[i]=-1;
    // ios::sync_with_stdio(false);
    // cin.tie();
    // int N;cin>>N;
    // string st;cin>>st;
    // int now=0;
    // int answer=0;
    // for(auto c:st){
    //     if(c=='('){
    //         now++;
    //     }else{
    //         now--;
    //     }
    //     if(now<0)answer++;
    //     if(now==0&&c=='(')answer++;
    // }
    // if(now!=0)answer=-1;
    // cout<<answer<<endl;
    int T;cin>>T;
    while(T--){
        int N,M;scanf("%d %d",&N,&M);
        vector<pair<vector<int>,ll>>ps(N);
        for(int i=0;i<N;++i){
            ll aa;scanf("%lld",&aa);
           // WHATS(aa)
            ps[i].second=aa;
        }
        for(int i=0;i<M;++i){
            int u,v;scanf("%d %d",&u,&v);u--;v--;
            ps[v].first.push_back(u);
        }
        for(auto &p:ps){
            sort(p.first.begin(),p.first.end());
        }
        sort(ps.begin(),ps.end());
        
        vector<int>pre;
        ll sum=0;
        vector<ll>sums;
        for(auto p:ps){
            if(p.first.empty()){
                continue;
            }
            if(p.first==pre){
                sum+=p.second;
            }else{
                if(sum)sums.push_back(sum);
                sum=p.second;
            }
            pre=p.first;
        }
        if(sum){
            sums.push_back(sum);
        }
        
        ll answer=sums[0];
        for(int i=1;i<sums.size();++i){
            answer=gcd(answer,sums[i]);
        }
        //WHATS(sums)
        printf("%lld\n",answer);

        
    }
    return 0;
}