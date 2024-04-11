#include<iostream>
#include<cstdio>
#include<cstdlib>
#define ll long long
using namespace std;
int read()
{
    int ret=0;char c=getchar();
    while(c>'9'||c<'0')c=getchar();
    while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
    return ret;
}
const int maxn=5e5+10;
const int inf=1e9+10;
int n,k;
ll ans;
int a[maxn],b[maxn];
struct cho{int ap,bp;};
const cho min(const cho &x,const cho &y){return a[x.ap]+b[x.bp]<a[y.ap]+b[y.bp]?x:y;}
struct segment
{
    #define L(u) u<<1
    #define R(u) u<<1|1
    struct node{cho va,vb,vc;int aa,ab,ba,bb,vm,tag;}t[maxn<<3];
    void update(int u)
    {
        t[u].va=min(cho{t[L(u)].aa,t[R(u)].ab},min(t[L(u)].va,t[R(u)].va));
        t[u].vc=min(cho{t[R(u)].aa,t[L(u)].ab},min(t[L(u)].vc,t[R(u)].vc));
        t[u].aa=a[t[L(u)].aa]<a[t[R(u)].aa]?t[L(u)].aa:t[R(u)].aa;
        t[u].ab=b[t[L(u)].ab]<b[t[R(u)].ab]?t[L(u)].ab:t[R(u)].ab;
        t[u].vb=min(t[L(u)].vb,t[R(u)].vb);
        t[u].vm=min(t[L(u)].vm,t[R(u)].vm);
        if(t[L(u)].vm<t[R(u)].vm)
        {
            t[u].vb=min(t[u].vb,min(t[R(u)].vc,cho{t[R(u)].aa,t[L(u)].bb}));
            t[u].ba=t[L(u)].ba;
            t[u].bb=b[t[L(u)].bb]<b[t[R(u)].ab]?t[L(u)].bb:t[R(u)].ab;
        }
        else if(t[L(u)].vm>t[R(u)].vm)
        {
            t[u].vb=min(t[u].vb,min(t[L(u)].vc,cho{t[R(u)].ba,t[L(u)].ab}));
            t[u].ba=a[t[L(u)].aa]<a[t[R(u)].ba]?t[L(u)].aa:t[R(u)].ba;
            t[u].bb=t[R(u)].bb;
        }
        else if(t[L(u)].vm==t[R(u)].vm)
        {
            t[u].vb=min(t[u].vb,cho{t[R(u)].ba,t[L(u)].bb});
            t[u].ba=t[L(u)].ba;
            t[u].bb=t[R(u)].bb;
        }
    }
    void pushdown(int u)
    {
        if(t[u].tag)
        {
            t[L(u)].vm+=t[u].tag;t[L(u)].tag+=t[u].tag;
            t[R(u)].vm+=t[u].tag;t[R(u)].tag+=t[u].tag;
            t[u].tag=0;
        }
    }
    void build(int u,int l,int r)
    {
        if(l==r)
        {
            t[u].va=t[u].vc=cho{l,l};t[u].vb=cho{0,0};
            t[u].aa=t[u].ab=t[u].ba=l;return;
        }
        int mid=(l+r)>>1;
        build(L(u),l,mid);build(R(u),mid+1,r);
        update(u);
    }
    void change(int u,int l,int r,int nl,int nr,int x)
    {
        if(l>=nl&&r<=nr){t[u].vm+=x;t[u].tag+=x;return;}
        pushdown(u);
        int mid=(l+r)>>1;
        if(mid>=nl)change(L(u),l,mid,nl,nr,x);
        if(mid+1<=nr)change(R(u),mid+1,r,nl,nr,x);
        update(u);
    }
    void change(int u,int l,int r,int p)
    {
        if(l==r)return;
        pushdown(u);    
        int mid=(l+r)>>1;
        if(mid>=p)change(L(u),l,mid,p);
        else change(R(u),mid+1,r,p);
        update(u);
    }
}tr;
int main()
{
    n=read();k=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++)b[i]=read();
    a[0]=b[0]=inf;
    tr.build(1,0,n);
    while(k--)
    {
        cho now=min(tr.t[1].va,tr.t[1].vb);
        ans+=a[now.ap]+b[now.bp];
        if(now.ap>now.bp)tr.change(1,0,n,now.bp,now.ap-1,-1);
        if(now.ap<now.bp)tr.change(1,0,n,now.ap,now.bp-1,1);
        a[now.ap]=inf;tr.change(1,0,n,now.ap);
        b[now.bp]=inf;tr.change(1,0,n,now.bp);
    }
    printf("%lld",ans);
    return 0;
}