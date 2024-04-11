#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define vc vector
#define pb push_back
#define pii pair<int,int>
#define pll pait<ll,ll>
#define ft first
#define sd second
#define up(it,vec) for(auto it=vec.begin();it!=vec.end();it++)
#define dn(it,vec) for(auto it=vec.rbegin();it!=vec.rend();it++)
// #define int long long

ll mypow(ll a,ll b,ll mod){
    ll ret=1;
    while(b){
        if(b&1)ret=ret*a%mod;
        a=a*a%mod;b>>=1;
    }
    return ret;
}
int val[200010];
int ans[200010];
vector<int> e[200010];
int dp[200010];
void dfs1(int u,int fa){
    dp[u]=val[u];
    for(auto &v:e[u]){
        if(v==fa)continue;
        dfs1(v,u);
        dp[u]+=max(dp[v],0);
    }
}
void dfs2(int u,int fa){
    ans[u]=max(ans[fa]-max(dp[u],0),0)+dp[u];
    for(auto &v:e[u]){
        if(v==fa)continue;
        dfs2(v,u);
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int tmp;cin>>tmp;
        val[i]=tmp?1:-1;
    }
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs1(1,0);
    dfs2(1,0);
    // for(int i=1;i<=n;i++)cout<<dp[i]<<" ";cout<<endl;
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;
}