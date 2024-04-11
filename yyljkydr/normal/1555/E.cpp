#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int n,m;

struct Seg{
    int l,r,w;
}a[N];

bool cmp(const Seg &a,const Seg &b)
{
    return a.w<b.w;
}

struct T{
    int l,r,ls,rs;
    int tag,mn;
}t[N*2+1];

void update(int x)
{
    t[x].mn=min(t[t[x].ls].mn,t[t[x].rs].mn);
}

void add(int x,int v)
{
    t[x].mn+=v;
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

int cnt;

int build(int l,int r)
{
    int x=++cnt;
    t[x].l=l,t[x].r=r;
    if(l==r)
        return x;
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

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].w);
    sort(a+1,a+n+1,cmp);
    build(1,m);
    change(1,1,1,1);
    int ans=1e9;
    for(int i=1,j=1;i<=n;i++)
    {
        while(j<=n&&t[1].mn==0)
            change(1,a[j].l+1,a[j].r,1),j++;
        if(t[1].mn)
            ans=min(ans,a[j-1].w-a[i].w);
        change(1,a[i].l+1,a[i].r,-1);
    }
    printf("%d\n",ans);
}