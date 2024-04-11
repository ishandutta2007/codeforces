#include<bits/stdc++.h>
#define maxh 17
#define maxn 50050
#define sq(x)   ((x)*(x))
using namespace std;
typedef long long LL;

struct fp  {
    LL s1,s2,tag;
    fp(LL _s1=0,LL _s2=0,LL _tag=0)    {
        s1=_s1,s2=_s2,tag=_tag;
    }
};

int sz,rt[maxn];
int ls[maxn*maxh*maxh],rs[maxn*maxh*maxh];
fp T[maxn*maxh*maxh];

int n,m,q;
LL C,c[maxn];

int col[maxn];
vector<int> G[maxn];

int dep[maxn],size[maxn];
int son[maxn];
int fa[maxn],top[maxn];

int N,id[maxn];

void init()
{
    scanf("%d%d%d%d",&n,&m,&q,&C);
    for (int i=1;i<=n;++i) scanf("%d",col+i);
    for (int i=2;i<=n;++i)
        scanf("%d",fa+i),G[fa[i]].push_back(i);
    for (int i=1;i<=m;++i)  scanf("%d",c+i);
}


int dfs1(int i)
{
    for (int j:G[i])
    {
        dep[j]=dep[i]+1;
        size[i]+=dfs1(j);
        if (size[son[i]]<size[j])
            son[i]=j;
    }
    return ++size[i];
}

void dfs2(int i,int tp)
{
    id[i]=++N,top[i]=tp;
    if (son[i])
        dfs2(son[i],tp);
    for (int j:G[i])
    {
        if (son[i]==j)    continue;
        dfs2(j,j);
    }
}

void update(int k,LL len)
{
    LL t=T[ls[k]].s1+T[rs[k]].s1;
    T[k].s1=t+T[k].tag*len;
    T[k].s2=T[ls[k]].s2+T[rs[k]].s2+t*T[k].tag*2+sq(T[k].tag)*len;
}

void change(int &k,int l,int r,int a,int b,LL d)
{
    if (!k) k=++sz;
    if (a<=l&&r<=b)
    {
        T[k].s2+=(T[k].s1*2+(r-l+1)*d)*d;
        T[k].s1+=d*(r-l+1);
        T[k].tag+=d;
    }
    else
    {
        int mid=(l+r)>>1;
        if (a<=mid)
            change(ls[k],l,mid,a,b,d);
        if (b>mid)
            change(rs[k],mid+1,r,a,b,d);
        update(k,r-l+1);
    }
}

void Change(int i,int c,LL d)
{
    for (;i;i=fa[top[i]])
        change(rt[c],1,n,id[top[i]],id[i],d);
}

void predo()
{
    dfs1(1);
    dfs2(1,1);
    for (int i=1;i<=n;++i)
        Change(i,col[i],1);
}

void solve()
{
    int op,x,w,k;
    while (q--)
    {
        scanf("%d",&op);
        if (op==1)
        {
            scanf("%d%d",&x,&w);
            Change(x,col[x],-1);
            Change(x,col[x]=w,1);
        } else
        {
            scanf("%d",&k);
            printf("%.9lf\n",(double)(sq(c[k])*T[rt[k]].s2+n*C*C-c[k]*T[rt[k]].s1*C*2)/n);
        }
    }
}

int main()
{
    init();
    predo();
    solve();
    return 0;
}