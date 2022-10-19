#include<bits/stdc++.h>
using namespace std;

const int N=5e5+1e3+7;

int n,q;

struct Edge{
    int u,v,w;
    int type;
}e[N];

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

vector<pii>g[N];

int d[N];

int fa[N];

int find(int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}

int dfn[N],dc,st[N],ed[N];

int anc[N][21],dep[N];

void dfs(int x,int f)
{
    dfn[x]=++dc;
    st[x]=dc;
    anc[x][0]=f;
    dep[x]=dep[f]+1;
    for(int j=1;j<=18;j++)
        anc[x][j]=anc[anc[x][j-1]][j-1];
    for(auto [v,w]:g[x])
    {
        if(v==f)
            continue;
        d[v]=d[x]^w;
        dfs(v,x);
    }
    ed[x]=dc;
}

int lca(int x,int y)
{
    if(dep[x]<dep[y])
        swap(x,y);
    for(int i=18;i>=0;i--)
        if(dep[x]-(1<<i)>=dep[y])
            x=anc[x][i];
    if(x==y)
        return x;
    for(int i=18;i>=0;i--)
        if(anc[x][i]!=anc[y][i])
            x=anc[x][i],y=anc[y][i];
    return anc[x][0];
}

int c[N];

void add(int x,int v)
{
    while(x<=n)
    {
        c[x]+=v;
        x+=x&-x;
    }
}

int qry(int x)
{
    int ret=0;
    while(x)
    {
        ret+=c[x];
        x-=x&-x;
    }
    return ret;
}

int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        int fu=find(e[i].u),fv=find(e[i].v);
        if(fu==fv)
            continue;
        e[i].type=1;
        fa[fu]=fv;
        g[e[i].u].push_back(mp(e[i].v,e[i].w));
        g[e[i].v].push_back(mp(e[i].u,e[i].w));
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            dfs(i,0);
    for(int i=1;i<=q;i++)
    {
        if(e[i].type==1)
            puts("YES");
        else
        {
            if(d[e[i].u]^d[e[i].v]^e[i].w)
            {
                int p=lca(e[i].u,e[i].v);
                if(qry(dfn[e[i].u])+qry(dfn[e[i].v])-2*qry(dfn[p]))
                    puts("NO");
                else
                {
                    puts("YES");
                    int x=e[i].u;
                    while(x!=p)
                        add(st[x],1),add(ed[x]+1,-1),x=anc[x][0];
                    x=e[i].v;
                    while(x!=p)
                        add(st[x],1),add(ed[x]+1,-1),x=anc[x][0];
                }
            }
            else
                puts("NO");
        }
    }
}