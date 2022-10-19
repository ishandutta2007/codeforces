#include<bits/stdc++.h>
using namespace std;

const int N=6e5+1e3+7;

int n,q;

struct EDG{
    int u,v,w;
}e[N];

bool cmp(const EDG &a,const EDG &b)
{
    return a.w<b.w;
}

int fa[N];

int find(int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}

int dep[N],anc[N][21],LOG[N];

int cn,val[N];

void merge(int x,int y,int w)
{
    ++cn;
    val[cn]=w;
    int fx=find(x),fy=find(y);
    fa[fx]=cn,fa[fy]=cn;
    anc[fx][0]=cn,anc[fy][0]=cn;
}

void pre()
{
    for(int i=n*2-1;i>=1;i--)
        dep[i]=dep[anc[i][0]]+1;
    LOG[0]=-1;
    for(int i=1;i<=n*2;i++)
        LOG[i]=LOG[i>>1]+1;
    int mxd=*max_element(dep+1,dep+n*2);
    for(int j=1;j<=LOG[mxd];j++)
        for(int i=1;i<=n*2-1;i++)
            anc[i][j]=anc[anc[i][j-1]][j-1];
}

int lca(int x,int y)
{
    if(dep[x]<dep[y])
        swap(x,y);
    for(int i=LOG[dep[x]-dep[y]];i>=0;i--)
        if(dep[x]-(1<<i)>=dep[y])
            x=anc[x][i];
    if(x==y)
        return x;
    for(int i=LOG[dep[x]];i>=0;i--)
        if(anc[x][i]!=anc[y][i])
            x=anc[x][i],y=anc[y][i];
    return anc[x][0];
}

int cnt;

struct T{
    int l,r,ls,rs;
    int lca,rlca,tag;
}t[N*2+1];

void update(int x)
{
    if(!t[t[x].ls].rlca)
        t[x].rlca=t[t[x].rs].rlca;
    else if(!t[t[x].rs].rlca)
        t[x].rlca=t[t[x].ls].rlca;
    else
        t[x].rlca=lca(t[t[x].ls].rlca,t[t[x].rs].rlca);
}

void add(int x,int v)
{
    t[x].tag=v;
    t[x].rlca=v?t[x].lca:0;
}

void pushdown(int x)
{
    if(t[x].tag!=-1)
    {
        add(t[x].ls,t[x].tag);
        add(t[x].rs,t[x].tag);
        t[x].tag=-1;
    }
}

int build(int l,int r)
{
    int x=++cnt;
    t[x].l=l,t[x].r=r;
    t[x].tag=-1;
    if(l==r)
    {
        t[x].lca=t[x].l;
        return x;
    }
    int mid=(l+r)>>1;
    t[x].ls=build(l,mid);
    t[x].rs=build(mid+1,r);
    t[x].lca=lca(t[t[x].ls].lca,t[t[x].rs].lca);
    update(x);
    return x;
}

void change(int x,int l,int r,int v)
{
    if(l<=t[x].l&&t[x].r<=r)
    {
        add(x,v);
        return;
    }
    int mid=(t[x].l+t[x].r)>>1;
    pushdown(x);
    if(l<=mid)
        change(t[x].ls,l,r,v);
    if(r>mid)
        change(t[x].rs,l,r,v);
    update(x);
}

int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<n;i++)
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    for(int i=1;i<=n*2-1;i++)
        fa[i]=i;
    sort(e+1,e+n,cmp);
    cn=n;
    for(int i=1;i<n;i++)
    {
        auto [x,y,w]=e[i];
        merge(x,y,w);
    }
    pre();
    build(1,n);
    while(q--)
    {
        int op;
        scanf("%d",&op);
        if(op==1||op==2)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            change(1,l,r,(op^3)-1);
        }
        else
        {
            int x;
            scanf("%d",&x);
            int p=t[1].rlca;
            if(!p||p==x)
                puts("-1");
            else
                printf("%d\n",val[lca(p,x)]);
        }
    }
}