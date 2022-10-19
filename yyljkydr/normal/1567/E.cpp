#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+1e3+7;

int n,a[N],Q;

struct Data{

    int vl,vr;
    int sl,sr;
    int sum;
    int len;
};

Data operator +(const Data &a,const Data &b)
{
    Data ret;
    ret.len=a.len+b.len;
    ret.vl=a.vl;
    ret.vr=b.vr;
    if(a.sl==a.len&&a.vr<=b.vl)
        ret.sl=a.len+b.sl;
    else
        ret.sl=a.sl;
    if(b.sr==b.len&&a.vr<=b.vl)
        ret.sr=b.len+a.sr;
    else
        ret.sr=b.sr;
    ret.sum=a.sum+b.sum+(a.vr<=b.vl?a.sr*b.sl:0);
    return ret;
}

int cnt;

struct T{
    int ls,rs,l,r;
    Data v;
}t[N*2+1];

void Set(int x,int val)
{
    t[x].v.len=1;
    t[x].v.vl=t[x].v.vr=val;
    t[x].v.sl=t[x].v.sr=1;
    t[x].v.sum=1;
}

int build(int l,int r)
{
    int x=++cnt;
    t[x].l=l,t[x].r=r;
    if(l==r)
    {
        Set(x,a[l]);
        return x;
    }
    int mid=(l+r)>>1;
    t[x].ls=build(l,mid);
    t[x].rs=build(mid+1,r);
    t[x].v=t[t[x].ls].v+t[t[x].rs].v;
    return x;
}

void change(int x,int p,int val)
{
    if(t[x].l==t[x].r)
    {
        Set(x,val);
        return;
    }
    int mid=(t[x].l+t[x].r)>>1;
    if(p<=mid)
        change(t[x].ls,p,val);
    else
        change(t[x].rs,p,val);
    t[x].v=t[t[x].ls].v+t[t[x].rs].v;
}

Data query(int x,int l,int r)
{
    if(l<=t[x].l&&t[x].r<=r)
        return t[x].v;
    int mid=(t[x].l+t[x].r)>>1;
    Data ret;
    ret.len=-1;
    if(l<=mid)
        ret=query(t[x].ls,l,r);
    if(r>mid)
        ret=(ret.len==-1?query(t[x].rs,l,r):ret+query(t[x].rs,l,r));
    return ret;
}

signed main()
{
    scanf("%lld%lld",&n,&Q);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    build(1,n);
    while(Q--)
    {
        int op;
        scanf("%lld",&op);
        if(op==1)
        {
            int x,y;
            scanf("%lld%lld",&x,&y);
            change(1,x,y);
        }
        else
        {
            int l,r;
            scanf("%lld%lld",&l,&r);
            printf("%lld\n",query(1,l,r).sum);
        }
    }
}