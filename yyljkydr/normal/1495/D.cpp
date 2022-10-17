#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e3+1e2+7,P=998244353;

int n,m;

vector<int>g[N];

int d[N][N],to[N][N],vis[N];

queue<int>q;

ll ans[N][N];

void bfs(int S)
{
    q.push(S);
    fill(d[S]+1,d[S]+n+1,-1);
    d[S][S]=1;
    to[S][S]=1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(auto v:g[x])
            if(d[S][v]==-1)
                q.push(v),d[S][v]=d[S][x]+1,to[S][v]=to[S][x];
            else if(d[S][v]==d[S][x]+1)
                to[S][v]=min(to[S][v]+to[S][x],1000000);
    }
}

void dfs(int x,int y,int f)
{
    vis[x]=1;
    for(auto v:g[x])
        if(d[y][v]+1==d[y][x])
            dfs(v,y,f);
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        bfs(i);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(to[i][j]==1)
            {
                fill(vis+1,vis+n+1,0);
                vis[i]=vis[j]=1;
                dfs(i,j,0);
                ans[i][j]=1;
                for(int k=1;k<=n;k++)
                    if(!vis[k])
                    {
                        int tot=0;
                        for(auto v:g[k])
                            if(d[i][k]==d[i][v]+1&&d[j][k]==d[j][v]+1)
                                tot++;
                        ans[i][j]*=tot;
                        ans[i][j]%=P;
                    }
            }
    for(int i=1;i<=n;i++,puts(""))
        for(int j=1;j<=n;j++,putchar(' '))
            printf("%lld",ans[i][j]);
}