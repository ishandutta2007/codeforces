#include<bits/stdc++.h>
#define maxn 300050
#define maxm 300050
#define modu 998244353
using namespace std;
typedef long long LL;

int n,m;

int tot;
int head[maxn],edge[maxm<<1],nxt[maxm<<1];

void join(int u,int v)
{
    edge[tot]=v; nxt[tot]=head[u]; head[u]=tot++;
    edge[tot]=u; nxt[tot]=head[v]; head[v]=tot++;
}

void init()
{
    tot=0;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i)
        head[i]=-1;
    while (m--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        join(u,v);
    }
}

int vis[maxn]={1};

LL c[2];

bool dfs(int i,int fa=0)
{
    if (~vis[i])    return vis[i]^vis[fa];
    vis[i]=vis[fa]^1;
    (c[vis[i]]*=2)%=modu;
    for (int k=head[i];~k;k=nxt[k])
    {
        int j=edge[k];
        if (fa==j)  continue;
        if (!dfs(j,i))
            return 0;
    }
    return 1;
}


void solve()
{
    for (int i=1;i<=n;++i)
        vis[i]=-1;

    LL ans=1;

    bool flag=1;
    for (int i=1;i<=n;++i)
        if (!~vis[i])
        {
            c[0]=c[1]=1;
            flag&=dfs(i);
            if (!flag)  break;
            ans=ans*(c[0]+c[1])%modu;
        }
        // for (int i=1;i<=n;++i)
        //     cout<<vis[i]<<" ";
        // cout<<endl;
    printf("%lld\n",flag?ans:0);
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        init();
        solve();
    }
    return 0;
}