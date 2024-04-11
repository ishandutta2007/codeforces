#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int maxn=3e5+3;
const int M=998244353;
vector <int> h[maxn];
bool ok[maxn],ban[maxn],flag,tmp[maxn];
int n,a[maxn],pre[maxn],s,t,dep[maxn],dp[maxn],m;
int l[maxn],r[maxn];
void dfs(int u,int fa){
    pre[u]=fa; ok[u]=1;
    dp[u]=0;
    for (auto v:h[u]){
        if (ban[v]||v==fa) continue;
        dep[v]=dep[u]+1; dfs(v,u);
        dp[u]=max(dp[u],dp[v]+1);
    }
}
void dfs2(int u,int fa,int len){
    int x=0,y=0,z=0;
    for (auto v:h[u]){
        if (v==fa) continue;
        if (dp[v]+1>x) z=y,y=x,x=dp[v]+1;
        else if (dp[v]+1>y) z=y,y=dp[v]+1;
        else if (dp[v]+1>z) z=dp[v]+1;
    }
    if (z>=m-1||(y>=m-1&&len>=m-1)) flag|=ok[u];
    for (auto v:h[u]){
        if (v==fa) continue;
        if (dp[v]+1==x) dfs2(v,u,max(y,len)+1); else dfs2(v,u,max(x,len)+1);
    }
}
void solve(){
    cin >> n >> s >> t;
    for (int i=1;i<=n;i++) h[i].clear();
    for (int i=1;i<n;i++){
        int u,v; cin >> u >> v;
        h[u].pb(v); h[v].pb(u);
    }
    dfs(s,0);
    m=1; a[1]=t;
    while (t!=s) t=pre[t],a[++m]=t;
    for (int i=1;i<=m;i++) ban[a[i]]=1;
    for (int i=1;i<=m;i++){
        dep[a[i]]=0;
        dfs(a[i],0);
    }
    l[0]=0; r[m+1]=0;
    for (int i=1;i<=m;i++) l[i]=max(l[i-1],dp[a[i]]-(i-1));
    for (int i=m;i>=1;i--) r[i]=max(r[i+1],dp[a[i]]-(m-i));
    int L=1,R=m;
    while (L<R&&(l[L]>m-R||r[R]>L-1)){
        if (l[L]>m-R) R=m-l[L]; else L=1+r[R];
    }
    if (L<R){
        memset(ok,0,sizeof(ok));
        for (int i=1;i<=L;i++) dfs(a[i],0);
        for (int i=R;i<=m;i++) dfs(a[i],0);
    } else {
        memset(ok,1,sizeof(ok));
    }
    memset(ban,0,sizeof(ban));
    memcpy(tmp,ok,sizeof(ok));
    dfs(1,0);
    memcpy(ok,tmp,sizeof(ok));
    flag=0;
    dfs2(1,0,0);
    if (flag) puts("YES"); else puts("NO");
}

int main(){
    int _; cin >> _;
    while (_--) solve();
}