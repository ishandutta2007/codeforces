#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define vc vector
#define pb push_back
#define pii pair<int,int>
#define pll pait<ll,ll>
#define ft first
#define sd second
// #define int long long
 
ll mypow(ll a,ll b,ll mod){
    ll ret=1;
    while(b){
        if(b&1)ret=ret*a%mod;
        a=a*a%mod;b>>=1;
    }
    return ret;
}
 
pii a[500010];
pii b[1000010];
 
vector<int> e[500010];
 
int vis[500010];
bool dfs(int u,int fa){
    if(vis[u])return 0;
    vis[u]=1;
 
    for(auto &it:e[u]){
        if(it==fa)continue;
        if(!dfs(it,u))return 0;
    }
    return 1;
}
 
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].ft>>a[i].sd;
        b[a[i].ft]={i,1};
        b[a[i].sd]={i,-1};
    }
    int now=0;
    set<pair<int,int> > s;
    for(int i=1;i<=2*n;i++){
        // cout<<i<<" "<<b[i].ft<<" "<<b[i].sd<<endl;
        if(b[i].sd==1){
            for(auto &it:s){
                if(it.ft>=a[b[i].ft].sd)break;
                e[b[i].ft].pb(it.sd);
                e[it.sd].pb(b[i].ft);
                // cout<<b[i].ft<<" "<<it<<endl;
                now++;
 
                if(now>=n){
                    cout<<"NO"<<endl;
                    break;
                }
                
            }
            s.insert({a[b[i].ft].sd,b[i].ft});
        }
        else{
            s.erase({a[b[i].ft].sd,b[i].ft});
        }
        if(now>=n)break;
    }
 
    // cout<<now<<endl;
    // for(int i=1;i<=n;i++){
    //     for(auto &it:e[i]){
    //         cout<<i<<" "<<it<<endl;
    //     }
    // }
 
    int flg=1;
    for(int i=1;i<=n;i++){
        if(!vis[i])flg=dfs(i,0);
        if(!flg)break;
    }

    if(now==n-1){
        cout<<(flg?"YES":"NO")<<endl;
    }
    else if(now<n-1){
        cout<<"NO"<<endl;
    }
}
/*
4
1 8
2 5
3 6
4 7
*/