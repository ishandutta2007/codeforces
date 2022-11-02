#include<bits/stdc++.h>
#define maxn 300050
using namespace std;
typedef long long LL;

int n;
LL w[maxn];

int tot;
LL cost[maxn<<1];
int head[maxn],edge[maxn<<1],nxt[maxn<<1];

LL ans,dp[maxn];

void join(int u,int v,LL w)
{
    cost[tot]=w; edge[tot]=v; nxt[tot]=head[u]; head[u]=tot++;
    cost[tot]=w; edge[tot]=u; nxt[tot]=head[v]; head[v]=tot++;
}

void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%lld",&w[i]);
    for (int k=1;k<n;++k)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        join(u,v,w);
    }
}

void dfs(int i,int fa=0)
{
    ans=max(ans,dp[i]=w[i]);
    for (int k=head[i];~k;k=nxt[k])
    {
        int j=edge[k];
        if (fa==j)  continue;
        dfs(j,i);
        ans=max(ans,dp[i]+dp[j]-cost[k]);
        dp[i]=max(dp[i],dp[j]+w[i]-cost[k]);
    }
}

void solve()
{
    dfs(1);
    printf("%lld\n",ans);
}

int main()
{
    init();
    solve();
    return 0;
}