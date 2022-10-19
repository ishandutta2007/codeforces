#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
struct DSU
{
    int fa[MAXN];
    void init(int n)
    {
        for(int i=1;i<=n;i++)fa[i]=i;
    }
    int find(int x)
    {
        return fa[x]==x ? x : fa[x]=find(fa[x]);
    }
    int merge(int x,int y)
    {
        x=find(x),y=find(y);
        if(x==y)return 0;
        return fa[x]=y,1;
    }
}dsu;
vector<int> e[MAXN];
int up[MAXN][19],dep[MAXN];
int jump(int u,int d)
{
    for(int i=0;i<19;i++)
        if(d>>i&1)u=up[u][i];
    return u;
}
int lca(int u,int v)
{
    if(dep[u]<dep[v])swap(u,v);
    u=jump(u,dep[u]-dep[v]);
    if(u==v)return u;
    for(int i=18;i>=0;i--)
        if(up[u][i]!=up[v][i])
            u=up[u][i],v=up[v][i];
    return up[u][0];
}
void dfs(int u,int fa)
{
    dep[u]=dep[fa]+1;
    up[u][0]=fa;
    for(int i=1;i<19;i++)
        up[u][i]=up[up[u][i-1]][i-1];
    for(auto v : e[u])
        if(v!=fa)dfs(v,u);
}
int cnt[MAXN];
void dfs2(int u,int fa)
{
    cnt[u]+=cnt[fa];
    for(auto v : e[u])
        if(v!=fa)dfs2(v,u);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    dsu.init(n);
    vector<pair<int,int>> que;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if(dsu.merge(u,v))
        {
            e[u].push_back(v);
            e[v].push_back(u);
        }
        else que.emplace_back(u,v);
    }
    dfs(1,0);
    for(auto& [u,v] : que)
    {
        if(dep[u]<dep[v])swap(u,v);
        int f=lca(u,v);
        if(f==v)
        {
            cnt[1]++;
            cnt[jump(u,dep[u]-dep[f]-1)]--;
            cnt[u]++;
        }
        else
        {
            cnt[u]++;
            cnt[v]++;
        }
    }
    dfs2(1,0);
    for(int i=1;i<=n;i++)
        printf("%d",cnt[i]==(int)que.size());
    return 0*printf("\n");
}
/*
4 4
1 2
2 3
3 4
1 4
*/