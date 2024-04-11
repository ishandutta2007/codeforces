#include<bits/stdc++.h>
#define maxn 505050

using namespace std;
typedef long long ll;
const ll INF=2e9;
vector <ll> h[maxn];
ll n,mn[maxn],a[maxn],ans;

void dfs(int u){
    mn[u]=INF;
    for (int i=0;i<h[u].size();i++){
        int v=h[u][i];
        dfs(v); mn[u]=min(mn[u],mn[v]);
    }
    if (a[u]!=-1&&a[u]>mn[u]){
        puts("-1");exit(0);
    }
    if (a[u]!=-1) mn[u]=min(mn[u],a[u]);
}

void dfs2(int u,ll val){
    ll res;
    if (mn[u]==INF) res=0; else res=mn[u]-val;
    ans+=res;
    for (int i=0;i<h[u].size();i++){
        int v=h[u][i];
        dfs2(v,val+res);
    }
}

int main(){
    cin >> n;
    for (int i=2;i<=n;i++){
        int u; scanf("%d",&u);
        h[u].push_back(i);
    }
    for (int i=1;i<=n;i++) scanf("%I64d",&a[i]);
    dfs(1); dfs2(1,0);
    cout << ans << endl;
    return 0;
}