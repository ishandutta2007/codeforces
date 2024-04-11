#include <map>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define reg register int
#define isdigit(x) ('0' <= (x)&&(x) <= '9')
template<typename T>
inline T Read(T Type)
{
    T x = 0,f = 1;
    char a = getchar();
    while(!isdigit(a)) {if(a == '-') f = -1;a = getchar();}
    while(isdigit(a)) {x = (x << 1) + (x << 3) + (a ^ '0');a = getchar();}
    return x * f;
}
const int MAXN = 100010;
vector<int> G[MAXN];
int dp[MAXN],size[MAXN];
int dfn[MAXN],dep[MAXN],fa[MAXN][20],poi[MAXN],st[MAXN],top,cnt;
bool vis[MAXN];
inline void add(int u,int v) {G[u].push_back(v);G[v].push_back(u);}
inline void dfs(int x,int f)
{
    dfn[x] = ++cnt;
    for(reg i = 0;i < G[x].size();i++)
    {
        int v = G[x][i];
        if(v == f) continue;
        dep[v] = dep[x] + 1,fa[v][0] = x;
        dfs(v,x);
    }
}
inline void adjust(int &u,int val)
{
    for(reg i = 18;i >= 0;i--)
        if(dep[fa[u][i]] >= val)
            u = fa[u][i];
}
inline int lca(int u,int v)
{
    if(dep[u] > dep[v]) adjust(u,dep[v]);
    if(dep[v] > dep[u]) adjust(v,dep[u]);
    if(u == v) return v;
    for(reg i = 18;i >= 0;i--)
        if(fa[u][i] != fa[v][i])
            u = fa[u][i],v = fa[v][i];
    return fa[u][0];
}
bool cmp(int a,int b) {return dfn[a] < dfn[b];}
inline void BuildTree(int m)
{
    top = 1,st[1] = 1,G[1].clear();
    for(reg i = 1;i <= m;i++)
    {
        if(poi[i] == 1) continue;
        int lc = lca(poi[i],st[top]);
        if(lc != st[top])
        {
            while(dfn[st[top - 1]] > dfn[lc]) add(st[top - 1],st[top]),top--;
            if(lc != st[top - 1]) G[lc].clear(),add(lc,st[top]),st[top] = lc;
            else add(lc,st[top--]);
        }
        G[poi[i]].clear(),st[++top] = poi[i];
    }
    for(reg i = 1;i < top;i++) add(st[i],st[i + 1]);
}
inline void dfs2(int x,int f)
{
    dp[x] = size[x] = 0;
    for(reg i = 0;i < G[x].size();i++)
    {
        int v = G[x][i];
        if(v == f) continue;
        dfs2(v,x);
        dp[x] += dp[v],size[x] += size[v]; 
    }
    if(vis[x]) dp[x] += size[x],size[x] = 1;
    else if(size[x] > 1) dp[x]++,size[x] = 0;
}
int main()
{
    int n = Read(1);
    for(reg i = 1;i < n;i++)
    {
        int u = Read(1),v = Read(1);
        add(u,v);
    }
    dep[1] = 1,dfs(1,0);
    for(reg i = 1;i <= 18;i++)
        for(reg j = 1;j <= n;j++)
            fa[j][i] = fa[fa[j][i - 1]][i - 1];
    int T = Read(1);
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        int m = Read(1);
        for(reg i = 1;i <= m;i++)
        {
            poi[i] = Read(1);
            vis[poi[i]] = 1;
        }
        bool able = 0;
        for(reg i = 1;i <= m;i++)
            if(vis[fa[poi[i]][0]]&&poi[i] != 1)
            {
                printf("-1\n");
                able = 1;
                break;
            }
        if(able) continue;
        sort(poi + 1,poi + 1 + m,cmp);
        BuildTree(m);
        dfs2(1,0);
        printf("%d\n",dp[1]); 
    }
    return 0;
}