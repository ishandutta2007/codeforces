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

const int MAX_N=int(2e5)+3;
vector<vector<pair<int,pair<int,int>>>>memo(MAX_N,vector<pair<int,pair<int,int>>>(3,make_pair(0,make_pair(-1,-1))));

pair<int,pair<int,int>> dfs(int now,int from,const Graph&g){
   // WHATS(now)
    memo[now][1]=make_pair(0,make_pair(now,-1));
    memo[now][0]=make_pair(0,make_pair(now,-1));
    memo[now][2]=make_pair(0,make_pair(now,-1));

    for(auto e:g[now]){
        if(e==from)continue;
        else{
            auto de= dfs(e,now,g);
            de.first++;
            auto x=make_pair(de.first,make_pair(de.second.first,e));
            memo[now].push_back(x);
            sort(memo[now].begin(),memo[now].end(),greater<pair<int,pair<int,int>>>());
            memo[now].pop_back();
        }
    }
    return memo[now][0];
}
pair<int,vector<int>>answer(0,{-1,-1,-1});

void dfs2(int now,int from,const Graph&g,pair<int,int>up){

    {
        int sum_cost=up.first+memo[now][0].first+memo[now][1].first;
        if(sum_cost>answer.first){
            answer.first=sum_cost;
            answer.second=vector<int>{up.second,memo[now][0].second.first,memo[now][1].second.first};
        }
    }
    {
        int sum_cost=memo[now][0].first+memo[now][1].first+memo[now][2].first;
        if(sum_cost>answer.first){
            answer.first=sum_cost;
            answer.second=vector<int>{memo[now][2].second.first,memo[now][0].second.first,memo[now][1].second.first};
        }
    }
    
    for(auto e:g[now]){
        if(e==from)continue;
        auto cand=memo[now][0];
        if(cand.second.second==e){
            cand=memo[now][1];
        }
        auto n_up=make_pair(up.first+1,up.second);
        if(now==0)n_up=make_pair(1,0);
        if(n_up.first<cand.first+1){
            n_up=make_pair(cand.first+1,cand.second.first);
        }
        dfs2(e,now,g,n_up);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie();
    int N;cin>>N;
    Graph g(N);
    for(int i=0;i<N-1;++i){
        int a,b;cin>>a>>b;a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    //WHATS(g)
    dfs(0,-1,g);
    //WHATS(g)
    dfs2(0,-1,g,make_pair(0,-1));
    cout<<answer.first<<endl;
    sort(answer.second.begin(),answer.second.end());
    if(answer.second[0]==-1){
        for(int k=0;k<300;++k){
            bool ok=true;
            for(int j=1;j<3;++j){
                if(answer.second[j]==k)ok=false;
            }
            if(ok){
                answer.second[0]=k;;
                break;
            }
        }
    }
    for(int i=0;i<3;++i){
        cout<<answer.second[i]+1<<' ';
    }
    cout<<endl;
    return 0;


}