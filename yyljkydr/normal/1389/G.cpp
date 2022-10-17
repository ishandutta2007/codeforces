#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=3e5+1e3+7;

int n,m,k;

int v[N],w[N],c[N];

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

vector<pii>g[N],ng[N];

int dc,dfn[N],low[N],ecc,bel[N];

stack<int>st;

int hav[N],is[N],inst[N];

ll f[N],sc[N],sw[N];

set<int>bri[N];

void tarjan(int x,int f)
{
    dfn[x]=low[x]=++dc;
    for(auto [v,w]:g[x])
    {
        if(v==f)
            continue;
        if(!dfn[v])
        {
            tarjan(v,x);
            if(low[v]>dfn[x])
                bri[x].insert(v); 
            low[x]=min(low[x],low[v]);
        }
        else
            low[x]=min(low[x],dfn[v]);
    }
}

int vis[N];

void getp(int x,int f,int rt)
{
    bel[x]=rt;
    sc[rt]+=c[x];
    hav[bel[x]]|=is[x];
    vis[x]=1;
    for(auto [v,w]:g[x])
    {
        if(v==f||vis[v])
            continue;
        if(bri[x].count(v)||bri[v].count(x))
            continue;
        getp(v,x,rt);
    }
}

void dp(int x,int F)
{
    f[x]=sc[x];
    for(auto [v,w]:ng[x])
    {
        if(v==F)
            continue;
        dp(v,x);
        hav[x]|=hav[v];
        sw[v]=hav[v]?w:0;
        if(f[v]>sw[v])
            f[x]+=f[v]-sw[v];
    }
}

ll ans[N];

void gans(int x,int F,int fw)
{
    ans[x]=f[x];
    if(F)
    {
        ll scf=ans[F];
        if(f[x]>sw[x])
            scf-=f[x]-sw[x];
        if(scf>sw[x])
            ans[x]+=scf-sw[x];
    }
    for(auto [v,w]:ng[x])
    {
        if(v==F)
            continue;
        gans(v,x,w);
    }
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++)
        scanf("%d",&v[i]),is[v[i]]=1;
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&w[i]);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(mp(v,w[i]));
        g[v].push_back(mp(u,w[i]));
    }
    int r=v[1];
    tarjan(r,0);
    for(int i=1;i<=n;i++)
        if(!vis[i])
            getp(i,0,++ecc);
    for(int i=1;i<=n;i++)
        for(auto [v,w]:g[i])
            if(bel[v]!=bel[i])
                ng[bel[i]].push_back(mp(bel[v],w));
    dp(bel[r],0);
    gans(bel[r],0,0);
    for(int i=1;i<=n;i++)
        printf("%lld%c",ans[bel[i]]," \n"[i==n]);
}