#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
const ll inf=1e12;
const int maxn=2e5+30;
int n;
ll dp[maxn][2],val[maxn],h[maxn],ans;
vector<int> G[maxn];
void Min(ll &x,ll y){if (x>y)x=y;}
void dfs(int u,int fa){
    for (auto v:G[u]){
        if (v==fa) continue;
        dfs(v,u);
    }
    ll s=0;
    vector<ll> r,sum; r.clear();
    for (auto v:G[u]){
        if (v==fa) continue;
        s+=dp[v][0];
        r.pb(dp[v][1]-dp[v][0]);
    }
    sort(r.begin(),r.end());
    int m=r.size();
    sum.resize(m+1);
    sum[0]=0; for (int i=0;i<m;i++) sum[i+1]=sum[i]+r[i];
    if (!fa){
        dp[u][0]=inf;
        for (int i=0;i<=m;i++) Min(dp[u][0],s+sum[i]+val[u]*abs((m-i)-i));
    } else {
        dp[u][0]=inf; dp[u][1]=inf;
        for (int i=0;i<=m;i++){
            Min(dp[u][0],s+sum[i]+val[u]*abs((m-i)-(i+1)));
            Min(dp[u][1],s+sum[i]+val[u]*abs((m-i+1)-i));
        }
        if (h[u]<h[fa]) dp[u][0]=inf;
        if (h[u]>h[fa]) dp[u][1]=inf;
    }
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%lld",&val[i]);
    for (int i=1;i<=n;i++) scanf("%lld",&h[i]);
    for (int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        G[u].pb(v); G[v].pb(u);
        ans+=val[u]+val[v];
    }
    dfs(1,0);
    cout << (ans+dp[1][0])/2 << endl;
    return 0;
}