#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int n,q;

namespace ST{

    int cnt;

    struct T{
        int ls,rs,l,r;
        long long sum;
        int tag;
    }t[N*2+1];

    void update(int x)
    {
        t[x].sum=t[t[x].ls].sum+t[t[x].rs].sum;
    }

    void add(int x,int v)
    {
        t[x].sum+=1ll*v*(t[x].r-t[x].l+1);
        t[x].tag+=v;
    }

    void pushdown(int x)
    {
        if(t[x].tag)
        {
            add(t[x].ls,t[x].tag);
            add(t[x].rs,t[x].tag);
            t[x].tag=0;
        }
    }

    int build(int l,int r)
    {
        int x=++cnt;
        t[x].l=l,t[x].r=r;
        if(l==r)
        {
            t[x].sum=1;
            return x;
        }
        int mid=(l+r)>>1;
        t[x].ls=build(l,mid);
        t[x].rs=build(mid+1,r);    
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
        pushdown(x);
        int mid=(t[x].l+t[x].r)>>1;
        if(l<=mid)
            change(t[x].ls,l,r,v);
        if(r>mid)
            change(t[x].rs,l,r,v);
        update(x);
    }

    long long query(int x,int l,int r)
    {
        if(l<=t[x].l&&t[x].r<=r)
            return t[x].sum;
        pushdown(x);
        int mid=(t[x].l+t[x].r)>>1;
        long long ret=0;
        if(l<=mid)
            ret+=query(t[x].ls,l,r);
        if(r>mid)
            ret+=query(t[x].rs,l,r);
        update(x);
        return ret;
    }
}

namespace STB{

    int cnt;

    struct T{
        int ls,rs,l,r;
        int mx,cmx,smx;
    }t[N*2+1];

    void update(int x)
    {
        if(t[t[x].ls].mx>t[t[x].rs].mx)
        {
            t[x].mx=t[t[x].ls].mx;
            t[x].cmx=t[t[x].ls].cmx;
            t[x].smx=max(t[t[x].ls].smx,t[t[x].rs].mx);
        }
        else if(t[t[x].rs].mx>t[t[x].ls].mx)
        {
            t[x].mx=t[t[x].rs].mx;
            t[x].cmx=t[t[x].rs].cmx;
            t[x].smx=max(t[t[x].ls].mx,t[t[x].rs].smx);
        }
        else
        {
            t[x].mx=t[t[x].ls].mx;
            t[x].cmx=t[t[x].ls].cmx+t[t[x].rs].cmx;
            t[x].smx=max(t[t[x].ls].smx,t[t[x].rs].smx);
        }
    }

    int add(int x,int v,bool cf=0)
    {
        if(v<t[x].mx&&v>t[x].smx)
        {
            if(cf)
                ST::change(1,v+1,t[x].mx,-t[x].cmx);
            t[x].mx=v;
            return 1;
        }
        return 0;
    }

    void pushdown(int x)
    {
        add(t[x].ls,t[x].mx);
        add(t[x].rs,t[x].mx);
    }

    int build(int l,int r)
    {
        int x=++cnt;
        t[x].l=l,t[x].r=r;
        if(l==r)
        {
            t[x].mx=l;
            t[x].smx=-1e9;
            t[x].cmx=1;
            return x;
        }
        int mid=(l+r)>>1;
        t[x].ls=build(l,mid);
        t[x].rs=build(mid+1,r);    
        update(x);
        return x;
    }

    void change(int x,int l,int r,int v)
    {
        if(l<=t[x].l&&t[x].r<=r)
        {
            if(t[x].mx<=v)
                return;
            if(add(x,v,1))
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

    void setv(int x,int p,int v)
    {
        if(t[x].l==t[x].r)
        {
            ST::change(1,t[x].l,t[x].mx,-1);
            t[x].mx=v;
            t[x].smx=-1e9;
            t[x].cmx=1;
            ST::change(1,t[x].l,t[x].mx,1);
            return;
        }
        pushdown(x);
        int mid=(t[x].l+t[x].r)>>1;
        if(p<=mid)
            setv(t[x].ls,p,v);
        else
            setv(t[x].rs,p,v);
        update(x);
    }
}

int main()
{
    scanf("%d%d",&n,&q);
    STB::build(1,n);
    ST::build(1,n);
    while(q--)
    {
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        if(op==1)
        {
            STB::setv(1,x,y);
            if(x>1)
                STB::change(1,1,x-1,x-1);
        }
        else
            printf("%lld\n",ST::query(1,x,y));
    }
}