#include<bits/stdc++.h>
#define maxn 300050
using namespace std;
typedef long long LL;

int n,m,r;

int tot;
LL cost[maxn<<1];
int head[maxn],edge[maxn<<1],nxt[maxn<<1],id[maxn<<1];

void join(int u,int v,int w,int i)
{
    id[tot]=i;  cost[tot]=w; edge[tot]=v; nxt[tot]=head[u]; head[u]=tot++;
    id[tot]=i;  cost[tot]=w; edge[tot]=u; nxt[tot]=head[v]; head[v]=tot++;
}

void init()
{
    tot=0;
    memset(head,-1,sizeof(head));

    scanf("%d%d%d",&n,&m,&r);
    for (int k=1;k<=m;++k)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        join(u,v,w,k);
    }
}

LL dis[maxn];

typedef pair<LL,int> pli;
priority_queue<pli> q;


void spfa()
{
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    q.push({-dis[1],1});
    while (!q.empty())
    {
        int i=q.top().second;
        if (q.top().first==-dis[i])
        {
            for (int k=head[i];~k;k=nxt[k])
            {
                int j=edge[k];
                if (dis[j]<=dis[i]+cost[k])  continue;
                dis[j]=dis[i]+cost[k];
                q.push({-dis[j],j});
            }
        }
        q.pop();
    }
}

int vis[maxn];

bool dfs(int i)
{
    if (vis[i])
        printf("%d ",vis[i]);
    if (!--r) return 0;
    for (int k=head[i];~k;k=nxt[k])
    {
        int j=edge[k];
        if (!vis[j]&&dis[j]==dis[i]+cost[k])
            if (vis[j]=id[k],!dfs(j))
                return 0;
    }
    return 1;
}

void solve()
{
    spfa();
    r=min(r,n-1);
    printf("%d\n",r++);
    dfs(1);
}

int main()
{
    init();
    solve();
    return 0;
}