#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n,q,l[N],r[N];

char s[N],f[N];

int cnt;

struct T{
    int l,r,ls,rs;
    int sum,tag;
}t[N*2+1];

void update(int x)
{
    t[x].sum=t[t[x].ls].sum+t[t[x].rs].sum;
}

void pushdown(int x)
{
    if(t[x].tag!=-1)
    {
        t[t[x].ls].tag=t[x].tag;
        t[t[x].ls].sum=t[x].tag*(t[t[x].ls].r-t[t[x].ls].l+1);
        t[t[x].rs].tag=t[x].tag;
        t[t[x].rs].sum=t[x].tag*(t[t[x].rs].r-t[t[x].rs].l+1);
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
        t[x].sum=f[l]-'0';
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
        t[x].sum=v*(t[x].r-t[x].l+1);
        t[x].tag=v;
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

int query(int x,int l,int r)
{
    if(l<=t[x].l&&t[x].r<=r)
        return t[x].sum;
    pushdown(x);
    int mid=(t[x].l+t[x].r)>>1;
    int ret=0;
    if(l<=mid)
        ret+=query(t[x].ls,l,r);
    if(r>mid)
        ret+=query(t[x].rs,l,r);
    return ret;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&q);
        scanf("%s",s+1);
        scanf("%s",f+1);
        for(int i=1;i<=q;i++)
            scanf("%d%d",&l[i],&r[i]);
        cnt=0;
        build(1,n);
        int ok=1;
        for(int i=q;i>=1;i--)
        {
            int sum=query(1,l[i],r[i]);
            int len=r[i]-l[i]+1;
            if(sum<len-sum)
                change(1,l[i],r[i],0);
            else if(len-sum<sum)
                change(1,l[i],r[i],1);
            else
            {
                ok=0;
                break;
            }
        }
        for(int i=1;i<=n;i++)
            ok&=query(1,i,i)==s[i]-'0';
        puts(ok?"YES":"NO");
    }
}