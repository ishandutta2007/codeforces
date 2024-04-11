#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
string s[MAXN][MAXN];
inline bool check(int i,int j,int k)
{
    assert(i!=j);
    if(i>j)swap(i,j);
    return s[i][j-i][k-1]=='1';
}
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
vector<int> tree[MAXN];
vector<pair<int,int>> tree_edge;
inline bool add_edge(int u,int v)
{
    if(!dsu.merge(u,v))return 0;
    tree_edge.emplace_back(u,v);
    tree[u].push_back(v);
    tree[v].push_back(u);
    return 1;
}
void dfs(int u,int fa,int n)
{
    for(int i=1;i<=n;i++)
    {
        if(i==u || i==fa)continue;
        if(!check(i,fa,u))continue;
        if(!add_edge(u,i))throw "invalid";
        dfs(i,u,n);
    }
}
int dis[MAXN];
void dfs2(int u,int fa)
{
    dis[u]=dis[fa]+1;
    for(auto v : tree[u])
        if(v!=fa)dfs2(v,u);
}
bool check_tree(int n)
{
    for(int rt=1;rt<=n;rt++)
    {
        dfs2(rt,0);
        for(int i=1;i<=n-1;i++)
            for(int j=1;j<=n-i;j++)
            {
                if(s[i][j][rt-1]=='0' && dis[i]==dis[i+j])return 0;
                if(s[i][j][rt-1]=='1' && dis[i]!=dis[i+j])return 0;
            }
    }
    return 1;
}
int solve()
{
    int n;
    scanf("%d",&n);
    tree_edge.clear();
    for(int i=1;i<=n;i++)
        tree[i].clear();
    for(int i=1;i<=n-1;i++)
        for(int j=1;j<=n-i;j++)
        {
            static char buf[MAXN];
            scanf("%s",buf);
            s[i][j]=buf;
        }
    vector<int> dep(n,n);
    for(int rt=1;rt<=n;rt++)
    {
        dsu.init(n);
        for(int i=1;i<=n-1;i++)
            for(int j=1;j<=n-i;j++)
                if(s[i][j][rt-1]=='1')
                    dep[rt-1]-=dsu.merge(i,i+j);
    }
    int mid=n+1;
    vector<int> can;
    for(int i=0;i<n;i++)
    {
        if(dep[i]<mid)mid=dep[i],can.clear();
        if(dep[i]==mid)can.push_back(i+1);
    }
    dsu.init(n);
    try
    {
        if(can.size()==1u)
        {
            for(int i=1;i<=n;i++)
            {
                if(dep[i-1]!=mid+1)continue;
                if(!add_edge(can[0],i))return 0*printf("No\n");
                dfs(i,can[0],n);
            }
        }
        else if(can.size()==2u)
        {
            add_edge(can[0],can[1]);
            dfs(can[0],can[1],n);
            dfs(can[1],can[0],n);
        }
        else return 0*printf("No\n");
    }
    catch (...)
    {
        return 0*printf("No\n");
    }
    if((int)tree_edge.size()<n-1 || !check_tree(n))
        return 0*printf("No\n");
    printf("Yes\n");
    for(auto& [u,v] : tree_edge)
        printf("%d %d\n",u,v);
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}