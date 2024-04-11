#include<bits/stdc++.h>
#define maxn 2050
#define maxm 10050
#define inf (1<<30)
using namespace std;
typedef long long LL;

int n,m;
int vs,vt;

int tot;
int cost[maxm];
int head[maxn],edge[maxm],nxt[maxm];

LL ans;

void join(int u,int v,int w)
{
    cost[tot]=w; edge[tot]=v; nxt[tot]=head[u]; head[u]=tot++;
    cost[tot]=0; edge[tot]=u; nxt[tot]=head[v]; head[v]=tot++;
}

void init()
{
    tot=0;
    memset(head,-1,sizeof(head));

    scanf("%d%d",&n,&m);
    vs=n+m+1,vt=n+m+2;
    for (int a,i=1;i<=n;++i)
        scanf("%d",&a),join(i,vt,a);
    for (int k=1;k<=m;++k)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        join(n+k,u,inf);
        join(n+k,v,inf);
        join(vs,n+k,w);
        ans+=w;
    }
}

int flow[maxn];

int cur[maxn],prt[maxn];
int d[maxn],gap[maxn];

int augment()
{
    int a=flow[vt];
    for (int i=vt;i!=vs;i=edge[prt[i]^1])
        cost[prt[i]]-=a,cost[prt[i]^1]+=a;
    return a;
}

void solve()
{
    for (int i=1;i<=vt;++i) cur[i]=head[i],++gap[d[i]=0];
    int i=vs;
    flow[i]=inf;
    while (d[vs]<vt)
    {
        if (i==vt)
        {
            ans-=augment();
            i=vs;
        }

        bool flag=0;
        for (int k=cur[i];~k;k=nxt[k])
        {
            int j=edge[k];
            if (cost[k]&&d[i]==d[j]+1)
            {
                flag=1;
                cur[i]=prt[j]=k;
                flow[j]=min(flow[i],cost[k]);
                i=j;
                break;
            }
        }

        if (flag)   continue;
        if (--gap[d[i]]==0) break;
        d[i]=vt;
        for (int k=head[i];~k;k=nxt[k])
            if (cost[k])
                d[i]=min(d[i],d[edge[k]]+1);
        ++gap[d[i]];
        cur[i]=head[i];
        if (i!=vs)
            i=edge[prt[i]^1];
    }
    printf("%lld\n",ans);
}

int main()
{
    init();
    solve();
    return 0;
}