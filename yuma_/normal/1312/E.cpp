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

vector<int>v;
int memo2[501][501];

int tk(int l,int r){
    if(memo2[l][r])return memo2[l][r];
    vector<int>nums(1030);
    for(int x=l;x<r;++x)nums[v[x]]++;
    for(int i=0;i<1020;++i){
        nums[i+1]+=nums[i]/2;
        nums[i]%=2;
    }
    if(count(nums.begin(),nums.end(),1)==1){
        return memo2[l][r]=find(nums.begin(),nums.end(),1)-nums.begin();
    }else{
        return memo2[l][r]=-1;
    }
}
int memo[501][501];
int solve(int l,int r){
    if(memo[l][r])return memo[l][r];
    if(l==r)return 0;
    else{
        if(l+1==r)return memo[l][r]=1;
        int ans=100000;
        for(int m=l+1;m<r;++m){
            int l_sum=solve(l,m);
            int r_sum=solve(m,r);

            if(l_sum==1&&r_sum==1&&tk(l,m)!=-1&&tk(l,m)==tk(m,r)){
                ans=1;
            }else{
                ans=min(ans,l_sum+r_sum);
            }
        }
        return memo[l][r]=ans;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();
    int N;cin>>N;v.resize(N);
    for(int i=0;i<N;++i)cin>>v[i];
    int ans=solve(0,N);
    cout<<ans<<endl;
    return 0;


}