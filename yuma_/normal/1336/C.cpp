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
pair<int,int>dfs(const Graph&g,int now,int from){
    pair<int,int>p;
    p.first=1;
    for(auto e:g[now]){
        if(e==from)continue;
        auto ap=dfs(g,e,now);
        p.first+=ap.second;
        p.second+=max(ap.first,ap.second);
    }
    return p;
}
const ll mod=998244353;
int main() {
    // for(int i=0;i<(1<<21);++i)as[i]=-1;
 
    ios::sync_with_stdio(false);
    cin.tie();
    string S,T;cin>>S>>T;

    vector<vector<ll>>dp(S.size()+1,vector<ll>(S.size()+1));
    //dp[S.size()][0]=1;
    for(int i=0;i<=S.size();++i){
        dp[0][i]=1;
    }
    ll answer=0;
    for(int i=0;i<S.size();++i){
        for(int j=0;j<=S.size();++j){
            dp[i][j]%=mod;
            char ch=S[i];
            int l=j;
            int r=min(i+j,int(T.size()));
            
            if(l>=1&&(l>T.size()||S[i]==T[l-1])){
                dp[i+1][j-1]+=dp[i][j];
            }
            if(r>=int(T.size())||T[r]==S[i]){
                dp[i+1][j]+=dp[i][j];
                
            }
        }
    }
   // WHATS(dp)
    for(int i=0;i<=S.size();++i){
        for(int j=0;j<=S.size();++j){
            if((i>=T.size()&&j==0))answer+=dp[i][j];
        }
    }
    answer%=mod;
    cout<<answer<<endl;
    return 0;
}
// 0 1 2 3 4  5  6  7
// 0 2 3 1 8  10 11 9
// 0 3 1 2 12 15 13 14