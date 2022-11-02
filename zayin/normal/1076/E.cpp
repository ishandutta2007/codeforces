#include<bits/stdc++.h>
#define maxn 300050
using namespace std;
typedef long long LL;
typedef pair<int,LL> pil;

int n,m;

int tot;
int head[maxn],edge[maxn<<1],nxt[maxn<<1];

vector<pil> val[maxn];

void join(int u,int v)
{
    edge[tot]=v; nxt[tot]=head[u]; head[u]=tot++;
    edge[tot]=u; nxt[tot]=head[v]; head[v]=tot++;
}

void init()
{
    tot=0;
    memset(head,-1,sizeof(head));

    scanf("%d",&n);
    for (int k=1;k<n;++k)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        join(u,v);
    }
    scanf("%d",&m);
    while (m--)
    {
        int v,d,x;
        scanf("%d%d%d",&v,&d,&x);
        val[v].push_back(pil(d,x));
    }
}

int dep[maxn]={0,1};
LL T[maxn];

LL ans[maxn];

int lowbit(int i)
{
    return i&(-i);
}

void add(int i,LL d)
{
    for (i=min(i,n);i;i-=lowbit(i))
        T[i]+=d;
}

LL query(int i)
{
    LL ans=0;
    for (;i<=n;i+=lowbit(i))
        ans+=T[i];
    return ans;
}

void dfs(int i,int fa=0)
{
    for (auto p:val[i])
        add(dep[i]+p.first,p.second);
    ans[i]=query(dep[i]);

    for (int k=head[i];~k;k=nxt[k])
    {
        int j=edge[k];
        if (fa==j)  continue;
        dep[j]=dep[i]+1;
        dfs(j,i);
    }
    for (auto p:val[i])
        add(dep[i]+p.first,-p.second);
}

void solve()
{
    dfs(1);
    for (int i=1;i<=n;++i)
        printf("%lld ",ans[i]);
}

int main()
{
    // freopen("c.in","r",stdin);
    init();
    solve();
    return 0;
}