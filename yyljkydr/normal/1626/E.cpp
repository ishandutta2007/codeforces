#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

int T;

int n,c[N];

vector<int>g[N],h[N];

int sz[N],ans[N],fa[N];

void dfs1(int x,int f)
{
    sz[x]=c[x];
    for(auto v:g[x])
    {
        if(v==f)
            continue;
        fa[v]=x;
        dfs1(v,x);
        sz[x]+=sz[v];
    }
}

void dfs2(int x)
{
    if(ans[x])
        return;
    ans[x]=1;
    for(auto v:h[x])
        dfs2(v);
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1,0);
    for(int i=1;i<=n;i++)
        for(auto v:g[i])
        {
            if(i==fa[v])
            {
                if(c[v]==1||sz[v]>=2)
                    h[v].push_back(i);
            }
            else
            {
                if(c[v]==1||sz[1]-sz[i]>=2)
                    h[v].push_back(i);
            }
        }
    for(int i=1;i<=n;i++)
        if(c[i])
            dfs2(i);
    for(int i=1;i<=n;i++)
        printf("%d%c",ans[i]," \n"[i==n]);
}