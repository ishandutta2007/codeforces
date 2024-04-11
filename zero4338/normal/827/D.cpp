#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int read()
{
    int ret=0;char c=getchar();
    while(c>'9'||c<'0')c=getchar();
    while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
    return ret;
}
const int maxn=2e5+5;
const int inf=1e9+5;
int n,m;
struct edge
{
    int u,v,w;int num;
    const bool operator<(const edge &a)const{return w<a.w;}
}e[maxn];
int ans[maxn];
struct segment1
{
    #define L(u) u<<1
    #define R(u) u<<1|1
    struct node{int mx,tag;}t[maxn<<3];
    void update(int u){t[u].mx=max(t[L(u)].mx,t[R(u)].mx);}
    void pushdown(int u)
    {
        if(t[u].tag)
        {
            t[L(u)].mx=max(t[L(u)].mx,t[u].tag);
            t[L(u)].tag=max(t[L(u)].tag,t[u].tag);
            t[R(u)].mx=max(t[R(u)].mx,t[u].tag);
            t[R(u)].tag=max(t[R(u)].tag,t[u].tag);
            t[u].tag=0;
        }
    }
    void change(int u,int l,int r,int nl,int nr,int x)
    {
        if(l>=nl&&r<=nr)
        {
            t[u].mx=max(t[u].mx,x);
            t[u].tag=max(t[u].tag,x);
            return;
        }
        pushdown(u);
        int mid=(l+r)>>1;
        if(mid>=nl)change(L(u),l,mid,nl,nr,x);
        if(mid+1<=nr)change(R(u),mid+1,r,nl,nr,x);
        update(u);
    }
    int query(int u,int l,int r,int nl,int nr)
    {
        if(l>=nl&&r<=nr)return t[u].mx;
        pushdown(u);
        int mid=(l+r)>>1,ret=0;
        if(mid>=nl)ret=max(ret,query(L(u),l,mid,nl,nr));
        if(mid+1<=nr)ret=max(ret,query(R(u),mid+1,r,nl,nr));
        return ret;
    }
}tr1;
struct segment2
{
    #define L(u) u<<1
    #define R(u) u<<1|1
    struct node{int mi,tag;}t[maxn<<3];
    void update(int u){t[u].mi=min(t[L(u)].mi,t[R(u)].mi);}
    void pushdown(int u)
    {
        if(t[u].tag)
        {
            t[L(u)].mi=min(t[L(u)].mi,t[u].tag);
            if(t[L(u)].tag)t[L(u)].tag=min(t[L(u)].tag,t[u].tag);
            else t[L(u)].tag=t[u].tag;
            t[R(u)].mi=min(t[R(u)].mi,t[u].tag);
            if(t[R(u)].tag)t[R(u)].tag=min(t[R(u)].tag,t[u].tag);
            else t[R(u)].tag=t[u].tag;
            t[u].tag=0;
        }
    }
    void build(int u,int l,int r)
    {
        t[u].mi=inf;
        if(l==r)return;
        int mid=(l+r)>>1;
        build(L(u),l,mid);build(R(u),mid+1,r);
    }
    void change(int u,int l,int r,int nl,int nr,int x)
    {
        if(l>=nl&&r<=nr)
        {
            t[u].mi=min(t[u].mi,x);
            if(!t[u].tag)t[u].tag=x;
            else t[u].tag=min(t[u].tag,x);
            return;
        }
        pushdown(u);
        int mid=(l+r)>>1;
        if(mid>=nl)change(L(u),l,mid,nl,nr,x);
        if(mid+1<=nr)change(R(u),mid+1,r,nl,nr,x);
        update(u);
    }
    int query(int u,int l,int r,int nl,int nr)
    {
        if(l>=nl&&r<=nr)return t[u].mi;
        pushdown(u);
        int mid=(l+r)>>1,ret=inf;
        if(mid>=nl)ret=min(ret,query(L(u),l,mid,nl,nr));
        if(mid+1<=nr)ret=min(ret,query(R(u),mid+1,r,nl,nr));
        return ret;
    }
}tr2;
struct mst
{
    int pv[maxn],pnum[maxn];
    int head[maxn],ver[maxn<<1],nxt[maxn<<1],val[maxn<<1],num[maxn<<1],tot;
    void add(int x,int y,int z,int ord){ver[++tot]=y;val[tot]=z;num[tot]=ord;nxt[tot]=head[x];head[x]=tot;}
    void link(int x,int y,int z,int ord){add(x,y,z,ord);add(y,x,z,ord);}
    int siz[maxn],dfn[maxn],tim,top[maxn],dep[maxn],fa[maxn],son[maxn];
    void getson(int u,int la)
    {
        siz[u]=1;fa[u]=la;dep[u]=dep[la]+1;
        for(int i=head[u];i;i=nxt[i])
        {
            if(ver[i]==la)continue;
            pv[ver[i]]=val[i];pnum[ver[i]]=num[i];
            getson(ver[i],u);
            siz[u]+=siz[ver[i]];
            if(siz[ver[i]]>siz[son[u]])son[u]=ver[i];
        }
    }
    void getroad(int u,int la,int ance)
    {
        dfn[u]=++tim;top[u]=ance;
        tr1.change(1,1,n,dfn[u],dfn[u],pv[u]);
        if(son[u])getroad(son[u],u,ance);
        for(int i=head[u];i;i=nxt[i])
        {
            if(ver[i]==la||ver[i]==son[u])continue;
            getroad(ver[i],u,ver[i]);
        }
    }
    int lca(int x,int y)
    {
        while(top[x]!=top[y])
        {
            if(dep[top[x]]<dep[top[y]])swap(x,y);
            x=fa[top[x]];
        }
        return dep[x]<dep[y]?x:y;
    }
    int query(int x,int y,int v)
    {
        int lf=lca(x,y);
        int ret=0;
        while(top[x]!=top[lf])
        {
            ret=max(ret,tr1.query(1,1,n,dfn[top[x]],dfn[x]));
            tr2.change(1,1,n,dfn[top[x]],dfn[x],v);
            x=fa[top[x]];
        }
        if(x!=lf)
        {
            ret=max(ret,tr1.query(1,1,n,dfn[lf]+1,dfn[x]));
            tr2.change(1,1,n,dfn[lf]+1,dfn[x],v);
        }
        while(top[y]!=top[lf])
        {
            ret=max(ret,tr1.query(1,1,n,dfn[top[y]],dfn[y]));
            tr2.change(1,1,n,dfn[top[y]],dfn[y],v);
            y=fa[top[y]];
        }
        if(y!=lf)
        {
            ret=max(ret,tr1.query(1,1,n,dfn[lf]+1,dfn[y]));
            tr2.change(1,1,n,dfn[lf]+1,dfn[y],v);
        }
        return ret;
    }
}v;
struct dsu
{
    int fa[maxn];
    void prework(){for(int i=1;i<=n;i++)fa[i]=i;}
    int get(int x){return x==fa[x]?x:fa[x]=get(fa[x]);}
    void merge(int x,int y){fa[get(x)]=get(y);}
    bool check(int x,int y){return get(x)==get(y);}
}S;
bool chose[maxn];
int main()
{
    n=read();m=read();
    for(int i=1;i<=m;i++){e[i].u=read();e[i].v=read();e[i].w=read();e[i].num=i;}
    sort(e+1,e+m+1);
    S.prework();
    for(int i=1;i<=m;i++)
    {
        if(!S.check(e[i].u,e[i].v))
        {
            chose[i]=1;
            v.link(e[i].u,e[i].v,e[i].w,e[i].num);
            S.merge(e[i].u,e[i].v);
        }
    }
    tr2.build(1,1,n);
    v.getson(1,1);
    v.getroad(1,1,1);
    for(int i=1;i<=m;i++)
    {
        if(chose[i])continue;
        ans[e[i].num]=v.query(e[i].u,e[i].v,e[i].w)-1;
    }
    for(int i=2;i<=n;i++)ans[v.pnum[i]]=tr2.query(1,1,n,v.dfn[i],v.dfn[i])-1;
    for(int i=1;i<=m;i++)
    {
        if(ans[i]==inf-1)printf("-1 ");
        else printf("%d ",ans[i]);
    }
    return 0;
}