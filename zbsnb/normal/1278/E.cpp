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

vector<int> e[500010];
int f[500010],s[500010],sz[500010];
void dfs(int u,int fa,int now){

    for(auto v:e[u]){
        if(v!=fa){
            f[v]=now++;
        }
    }
    s[u]=now++;
    dn(it,e[u]){
        int v=*it;
        if(v!=fa){
            dfs(v,u,now);
            now+=2*sz[v]-1;
        }
    }
}

void dfs1(int u,int fa){
    sz[u]=1;
    for(auto &v:e[u]){
        if(v!=fa){
            dfs1(v,u);
            sz[u]+=sz[v];
        }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    int n;cin>>n;
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        e[a].pb(b),e[b].pb(a);
    }
    dfs1(1,0);
    dfs(1,0,2);
    f[1]=1;
    for(int i=1;i<=n;i++){
        cout<<f[i]<<" "<<s[i]<<"\n";
    }
}