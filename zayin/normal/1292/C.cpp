#include<bits/stdc++.h>
#define maxn 3050
using namespace std;
typedef long long LL;

int n;
vector<int> G[maxn];

int dis[maxn][maxn];

LL dp[maxn][maxn];
LL sz[maxn][maxn];

struct path {
    int u,v;
    path(int _u=0,int _v=0) {
        u=_u,v=_v;
    }
} ;

vector<path> P[maxn];

int rt;
void dfs(int i,int fa,int dep)  {
    dis[rt][i]=dep;
    for (int j:G[i])    {
        if (fa==j) continue;
        dfs(j,i,dep+1);
        sz[rt][i]+=sz[rt][j];
    }
    ++sz[rt][i];
}

void upd(int x,int y,LL a)  {
    dp[x][y]=max(dp[x][y],a);
    dp[y][x]=max(dp[y][x],a);
}

int main()  {
    scanf("%d",&n);
    for (int k=1;k<n;++k)   {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (rt=1;rt<=n;++rt)
        dfs(rt,0,0);
    for (int i=1;i<=n;++i)
        for (int j=1;j<i;++j)
            P[dis[i][j]].push_back(path(i,j));
    
    auto val=[&](int i,int j)   {
        return (LL)sz[i][j]*sz[j][i];
    };
    for (path p:P[1])
        upd(p.u,p.v,sz[p.u][p.v]*sz[p.v][p.u]);
    for (int d=2;d<=n;++d)  {
        for (path p:P[d-1]) {
            for (int j:G[p.v])  {
                if (dis[p.u][j]<dis[p.u][p.v]) continue;
                upd(p.u,j,dp[p.u][p.v]+val(p.u,j));
            }
            for (int j:G[p.u])  {
                if (dis[p.v][j]<dis[p.v][p.u]) continue;
                upd(p.v,j,dp[p.u][p.v]+val(p.v,j));
            }
        }
    }
    
    LL ans=0;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            ans=max(ans,dp[i][j]);
    printf("%lld\n",ans);
    return 0;
}