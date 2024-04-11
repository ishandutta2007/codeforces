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
vector<int> e[2010];
int a[2010];
vector<int> vec[2010];
int sz[2010];
int ans[2010];
void dfs1(int u){
    sz[u]=1;
    for(auto &v:e[u]){
        dfs1(v);
        sz[u]+=sz[v];
    }
}

int n;
int nows;
void dfs2(int u,int val){
    if(ans[u]>=val)ans[u]++;
    for(auto &v:e[u]){
        dfs2(v,val);
    }
}
bool dfs(int u){
    // cout<<u<<endl;
    for(auto &v:e[u]){
        if(!dfs(v))return 0;
        for(auto &it:vec[v]){
            vec[u].push_back(it);
        }
    }

    if(a[u]>=sz[u]){
        return 0;
    }
    // cout<<"?"<<u<<endl;
    sort(vec[u].begin(),vec[u].end());
    int now=a[u]==0?(nows-=2*n):vec[u][a[u]-1]+1;
    // cout<<now<<endl;
    for(int i=a[u];i<vec[u].size();i++){
        vec[u][i]++;
    }

    // cout<<"x"<<u<<endl;

    dfs2(u,now);
    ans[u]=now;
    vec[u].push_back(now);
    // cout<<"now"<<u<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<ans[i]<<" ";
    // }
    // cout<<endl;

    return 1;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    nows=4*n*(n+10);
    int rt;
    for(int i=1;i<=n;i++){
        int x,y;cin>>x>>y;
        if(x==0)rt=i;
        else e[x].push_back(i);
        a[i]=y;
    }
    // cout<<rt<<endl;
    dfs1(rt);
    // for(int i=1;i<=n;i++){
    //     cout<<i<<" "<<sz[i]<<endl;
    // }
    if(!dfs(rt)){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}