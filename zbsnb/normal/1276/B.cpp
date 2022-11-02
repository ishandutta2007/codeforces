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

vector<int> e[200010];
int vis[200010];

void dfs(int u,int fa,int aim,int tag){
    // cout<<u<<" "<<fa<<" "<<aim<<endl;
    if(vis[u]&tag)return;
    vis[u]|=tag;

    if(u==aim)return;
    for(auto &v:e[u]){
        if(v==fa)continue;
        dfs(v,u,aim,tag);
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,m,a,b;cin>>n>>m>>a>>b;
        for(int i=1;i<=n;i++)e[i].clear(),vis[i]=0;
        for(int i=1;i<=m;i++){
            int a,b;cin>>a>>b;
            e[a].push_back(b);
            e[b].push_back(a);
        }
        dfs(a,0,b,1);
        dfs(b,0,a,2);
        int cnt1=0,cnt2=0;
        for(int i=1;i<=n;i++){
            // cout<<vis[i]<<" ";
            if((vis[i]&1)&&!(vis[i]&2))cnt1++;
            if((vis[i]&2)&&!(vis[i]&1))cnt2++;
        }
        // cout<<cnt1<<" "<<cnt2<<" "<<endl;
        cout<<1ll*cnt1*cnt2<<"\n";
    }
}