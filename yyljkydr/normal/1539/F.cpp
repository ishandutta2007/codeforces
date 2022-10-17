#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int n,a[N];

int cnt;

struct T{
    int l,r,ls,rs;
    int mx,mn,tag;
}t[N*2+1];

void add(int x,int v)
{
    t[x].mx+=v;
    t[x].mn+=v;
    t[x].tag+=v;
}

void update(int x)
{
    t[x].mx=max(t[t[x].ls].mx,t[t[x].rs].mx);
    t[x].mn=min(t[t[x].ls].mn,t[t[x].rs].mn);
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
    t[x].tag=0;
    if(l==r)
    {
        t[x].mx=-l;
        t[x].mn=-l;
        t[x].tag=0;
        return x;
    }
    int mid=(t[x].l+t[x].r)>>1;
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

int qmx(int x,int l,int r)
{
    if(l<=t[x].l&&t[x].r<=r)
        return t[x].mx;
    pushdown(x);
    int mid=(t[x].l+t[x].r)>>1;
    int ret=-n;
    if(l<=mid)
        ret=max(ret,qmx(t[x].ls,l,r));
    if(r>mid)
        ret=max(ret,qmx(t[x].rs,l,r));
    return ret;
}

int qmn(int x,int l,int r)
{
    if(l<=t[x].l&&t[x].r<=r)
        return t[x].mn;
    pushdown(x);
    int mid=(t[x].l+t[x].r)>>1;
    int ret=n;
    if(l<=mid)
        ret=min(ret,qmn(t[x].ls,l,r));
    if(r>mid)
        ret=min(ret,qmn(t[x].rs,l,r));
    return ret;
}

vector<int>v[N];

int ans[N];

void solve(int flag)
{
    cnt=0;
    build(1,n);
    for(int i=1;i<=n;i++)
    {
        for(auto x:v[i])
            change(1,x,n,2);
        for(auto x:v[i])
        {
            int vx=qmx(1,x,x);
            int vl=vx-min(qmn(1,1,x-1),0);
            int vr=qmx(1,x,n)-vx;
            int val=vl+vr;
            ans[x]=max(ans[x],(val+flag)/2);
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),v[a[i]].push_back(i);
    solve(-1);
    reverse(v+1,v+n+1);
    solve(0);
    for(int i=1;i<=n;i++)
        printf("%d%c",ans[i]," \n"[i==n]);
}