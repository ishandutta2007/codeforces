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
void dfs(int now,int from,vector<int>&cs,Graph&g,vector<int>&maxs){
    int cnt=0;
    
    for(auto e:g[now]){
        if(e==from)continue;
        else{
            dfs(e,now,cs,g,maxs);
            cnt+=max(0,maxs[e]);
        }
    }
    if(cs[now])cnt++;
    else cnt--;
    maxs[now]=cnt;
}
void dfs2(int now,int from,vector<int>&cs,Graph&g,vector<int>&maxs,vector<int>&anss,int k){
    anss[now]=maxs[now]+k;
    for(auto e:g[now]){
        if(e==from)continue;
        else{
            int nk=k+max(-3,(maxs[now]-max(0,maxs[e])));
            nk=max(0,nk);
            dfs2(e,now,cs,g,maxs,anss,nk);
        }
    }
}
vector<int>solve(vector<int>cs,vector<vector<int>>g){
    int N=g.size();
    vector<int>maxs(N);
    dfs(0,-1,cs,g,maxs);
   // WHATS(maxs)
    vector<int>anss(N);
    dfs2(0,-1,cs,g,maxs,anss,0);
    return anss;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie();
    int N;cin>>N;
    vector<int>cs(N);
    Graph g(N);
    for(int i=0;i<N;++i){
        cin>>cs[i];
    }
    for(int i=0;i<N-1;++i){
        int a,b;cin>>a>>b;a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int>ans1,ans2;
    ans1=solve(cs,g);
    for(auto&x:cs)x=1-x;
    ans2=solve(cs,g);
    for(int i=0;i<N;++i)cout<<ans1[i]<<' ';
    cout<<endl;
    return 0;
}