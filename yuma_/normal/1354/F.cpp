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
using Graph=vector<vector<int>>;
    
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
vector<int>ap;
void dfs(const Graph&g,vector<int>&colors,int now,int color,vector<int>&uses){
    uses.push_back(now);
    colors[now]=color;
    ap[color]++;
    
    for(auto e:g[now]){
        if(colors[e]==-1){
            dfs(g,colors,e,!color,uses);
        }else{
            if(colors[e]!=colors[now]){

            }else{
                throw(false);
            }
        }
    }
}
int memo[5001][5001];

void dfs2(const Graph&g,vector<int>&answer,int now,int color){

}
struct minion{
    int id;
    ll buff;
    ll pow;
};


int main() {
    ap=vector<int>{0,0};
    //for(int i=0;i<int(1e6)+1;++i)have_rs[i]=-1;
    // for(int i=0;i<(1<<21);++i)as[i]=-1;
    //ios::sync_with_stdio(false);
    //cin.tie();
    int T;cin>>T;
    while(T--){
        int N,K;cin>>N>>K;
        vector<minion>ms;
        for(int i=0;i<N;++i){
            int a,b;cin>>a>>b;
            ms.push_back(minion{i+1,b,a});
        }
        sort(ms.begin(),ms.end(),[](const minion&l,const minion&r){return l.buff<r.buff;});

        vector<vector<vector<ll>>>memo(N,vector<vector<ll>>(N+1,vector<ll>(K+1,ll(-1e18))));

        for(int last_id=0;last_id<N;++last_id){
            memo[last_id][0][0]=ms[last_id].buff*(K-1)+ms[last_id].pow;
            for(int now=0;now<N;++now){
                
                for(int use=0;use<K;++use){
                    if(now==last_id){
                        memo[last_id][now+1][use]=memo[last_id][now][use];
                    }else{
                        auto now_cost=memo[last_id][now][use];

                        //only buff
                        memo[last_id][now+1][use]=max(memo[last_id][now+1][use],now_cost+(K-1)*ms[now].buff);

                        //
                        if(use+1<K)memo[last_id][now+1][use+1]=max(memo[last_id][now+1][use+1],now_cost+use*ms[now].buff+ms[now].pow); 
                    }
                    
                }
            }
        }
        pair<ll,int>ans_p(-1ll,-1);
        for(int last_id=0;last_id<N;++last_id){
            auto p=make_pair(memo[last_id][N][K-1],last_id);
            //WHATS(p)
            
            ans_p=max(ans_p,p);
        }
        
        int last_id=ans_p.second;
        vector<int>answers{ms[last_id].id};
        vector<int>buffs;
        //WHATS(last_id)
        int use=K-1;
        ll cost=memo[last_id][N][use];

        for(int now=N-1;now>=0;--now){
            if(last_id==now)continue;
            //WHATS(now)
            //WHATS(cost)
            //WHATS(memo[last_id][now][use]+(K-1)*ms[now].buff)
            //only buff
            if(memo[last_id][now][use]+(K-1)*ms[now].buff==cost){
                buffs.push_back(ms[now].id);
            }else if(use>0 && memo[last_id][now][use-1]+(use-1)*ms[now].buff+ms[now].pow){
                answers.push_back(ms[now].id);
                use--;
            }else{
                assert(false);
            }
            cost=memo[last_id][now][use];
        }
        //WHATS(cost)
        vector<int>nums;
        reverse(answers.begin(),answers.end());
        for(int i=0;i<K-1;++i){
            nums.push_back(answers[i]);
        }
        for(int i=0;i<N-K;++i){
            nums.push_back(buffs[i]);
            nums.push_back(-buffs[i]);

        }
        nums.push_back(answers[K-1]);
        cout<<nums.size()<<endl;
        for(auto nu:nums){
            cout<<nu<<' ';
        }
        cout<<endl;
    }
    
    return 0;
}
// 0 1 2 3 4  5  6  7
// 0 2 3 1 8  10 11 9
// 0 3 1 2 12 15 13 14