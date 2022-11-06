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
int main() {
    ap=vector<int>{0,0};
    //for(int i=0;i<int(1e6)+1;++i)have_rs[i]=-1;
    // for(int i=0;i<(1<<21);++i)as[i]=-1;
    //ios::sync_with_stdio(false);
    //cin.tie();
    int N,M;cin>>N>>M;
    int A,B,C;cin>>A>>B>>C;
    int rest_A=A;
    Graph g(N);
    for(int i=0;i<M;++i){
        int u,v;cin>>u>>v;u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int>colors(N,-1);
    vector<vector<int>>ps;
    vector<vector<int>>usess;
    bool ok=true;
    for(int i=0;i<N;++i){
        if(colors[i]==-1){
            vector<int>uses;
            try{
                dfs(g,colors,i,0,uses);

            }catch(...){
                ok=false;
            }
            
            ps.emplace_back(ap);
            ap=vector<int>{0,0};
            usess.push_back(uses);
        }
    }
    memo[0][0]=true;
    for(int i=0;i<ps.size();++i){
        for(int from=0;from<=5000;++from){
            auto p=ps[i];
            if(memo[i][from]){
                if(from+p[0]<=5000){
                    memo[i+1][from+p[0]]=true;
                }
                if(from+p[1]<=5000){
                    memo[i+1][from+p[1]]=true;
                }
            }
        }
    }
    // WHATS(ps)
    // WHATS(ok)
    if(!memo[ps.size()][B])ok=false;
    if(ok){
        cout<<"YES"<<endl;
        vector<int>answers(N,0);
        int now_b=B;
        rest_A=A;
        for(int i=ps.size()-1;i>=0;--i){
            assert(memo[i+1][now_b]);
            bool flag=false;
            for(int j=0;j<2;++j){
                if(now_b>=ps[i][j]&&memo[i][now_b-ps[i][j]]){
                    for(auto use:usess[i]){
                        if(colors[use]==j){
                            answers[use]=2;
                        }else{
                            if(rest_A){
                                rest_A--;
                                answers[use]=1;
                            }else{
                                answers[use]=3;
                            }
                        }
                    }
                    flag=true;
                    now_b-=ps[i][j];
                    break;
                }
            }
            assert(flag);
        }
        for(int i=0;i<N;++i){
            printf("%d",answers[i]);
        }
        cout<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    
    return 0;
}
// 0 1 2 3 4  5  6  7
// 0 2 3 1 8  10 11 9
// 0 3 1 2 12 15 13 14