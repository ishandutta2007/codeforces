#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=601,INF=1e15;

int n,m,q,d[N][N],l[N][N],g[N][N];

int x[N*N],y[N*N],z[N*N];

signed main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j)
                d[i][j]=INF;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        x[i]=u,y[i]=v,z[i]=w;
        d[u][v]=d[v][u]=w;
    }
    scanf("%lld",&q);
    for(int i=1;i<=q;i++)
    {
        int u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        l[u][v]=l[v][u]=w;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                g[i][j]=max(g[i][j],l[i][k]-d[j][k]);
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        int ok=0;
        for(int u=1;u<=n;u++)
            if(d[u][x[i]]+z[i]<=g[u][y[i]]||d[u][y[i]]+z[i]<=g[u][x[i]])
                ok=1;
        if(ok)
            ans++;
    }
    printf("%lld\n",ans);
}
//d[u][x]+d[v][y]+dis<=l[u][v]
//d[u][x]+dis<=l[u][v]-d[y][v]=g[u][y]