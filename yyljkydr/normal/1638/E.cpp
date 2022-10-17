#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e6+1e3+7;

int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int n,q;

struct T{
    int l,r,ls,rs;
    int tag,sum,col,tagc;
}t[N*2+1];

void update(int x)
{
    t[x].sum=(t[t[x].ls].sum+t[t[x].rs].sum);
    if(t[t[x].ls].col==-1||t[t[x].rs].col==-1||t[t[x].ls].col!=t[t[x].rs].col)
        t[x].col=-1;
    else
        t[x].col=t[t[x].ls].col;
}

void add(int x,int v)
{
    t[x].sum+=v;
    t[x].tag+=v;
}

void setc(int x,int c)
{
    t[x].col=c;
    t[x].tagc=c;
}

void pushdown(int x)
{
    if(t[x].tag)
    {
        add(t[x].ls,t[x].tag);
        add(t[x].rs,t[x].tag);
        t[x].tag=0;
    }
    if(t[x].tagc!=-1)
    {
        setc(t[x].ls,t[x].tagc);
        setc(t[x].rs,t[x].tagc);
        t[x].tagc=-1;
    }
}

int cnt;

int build(int l,int r)
{
    int x=++cnt;
    t[x].l=l,t[x].r=r;
    t[x].tagc=-1;
    if(l==r)
    {
        t[x].col=1;
        return x;
    }
    int mid=(l+r)>>1;
    t[x].ls=build(l,mid);
    t[x].rs=build(mid+1,r);
    update(x);
    return x;
}

int sc[N];

void change(int x,int l,int r,int c)
{
    if(l<=t[x].l&&t[x].r<=r)
    {
        if(t[x].col!=-1)
        {
            add(x,sc[t[x].col]-sc[c]);
            setc(x,c);
            return;
        }
    }
    pushdown(x);
    int mid=(t[x].l+t[x].r)>>1;
    if(l<=mid)
        change(t[x].ls,l,r,c);
    if(r>mid)
        change(t[x].rs,l,r,c);
    update(x);
}

int query(int x,int p)
{
    if(t[x].l==t[x].r)
        return t[x].sum+sc[t[x].col];
    pushdown(x);
    int mid=(t[x].l+t[x].r)>>1;
    if(p<=mid)
        return query(t[x].ls,p);
    else
        return query(t[x].rs,p);
}

char op[11];

signed main()
{
    n=read(),q=read();
    build(1,n);
    while(q--)
    {
        scanf("%s",op);
        if(op[0]=='C')
        {
            int l=read(),r=read(),c=read();
            change(1,l,r,c);
        }
        if(op[0]=='A')
        {
            int c=read(),x=read();
            sc[c]+=x;
        }
        if(op[0]=='Q')
        {
            int x=read();
            printf("%lld\n",query(1,x));
        }
    }
}