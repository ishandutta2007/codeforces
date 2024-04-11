#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> e[100010];
ll sz[100010];
int p[100010];
void dfs(int u,int fa){
    sz[u]=1;
    for(auto &v:e[u]){
        if(v==fa)continue;
        dfs(v,u);sz[u]+=sz[v];
    }
}
const int mod=1e9+7;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=1;i<=n;i++){
            e[i].clear();
            sz[i]=0;
        }
        for(int i=2;i<=n;i++){
            int a,b;cin>>a>>b;
            e[a].push_back(b);
            e[b].push_back(a);
        }
        dfs(1,0);
        for(int i=2;i<=n;i++) sz[i]*=(n-sz[i]);
        sort(sz+2,sz+n+1);
        // for(int i=1;i<=n;i++)cout<<sz[i]<<" ";cout<<endl;
        int m;cin>>m;
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        while(m<n-1){
            p[++m]=1;
        }
        sort(p+1,p+m+1);
        while(m>n-1){
            p[m-1]=1ll*p[m]*p[m-1]%mod;
            m--;
        }
        ll ans=0;
        for(int i=1;i<=n-1;i++){
            sz[i+1]%=mod;
            ans+=sz[i+1]*p[i]%mod;
            // cout<<i<<" "<<sz[i+1]<<" "<<p[i]<<endl;
        }
        cout<<ans%mod<<endl;
    }
}