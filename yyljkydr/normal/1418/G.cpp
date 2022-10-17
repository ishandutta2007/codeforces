#include<bits/stdc++.h>
using namespace std;

const int N=5e5+1e3+7;

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

int cnt;

struct T{
    int l,r,ls,rs;
    pii mx;
    int tag;
}t[N*2+1];

int n,vis[N],nx[N];

vector<int>pos[N];

void update(int x)
{
    t[x].mx.fs=max(t[t[x].ls].mx.fs,t[t[x].rs].mx.fs);
    t[x].mx.sd=(t[x].mx.fs==t[t[x].ls].mx.fs)*t[t[x].ls].mx.sd+(t[x].mx.fs==t[t[x].rs].mx.fs)*t[t[x].rs].mx.sd;
}

void pushdown(int x)
{
    if(t[x].tag)
    {
        t[t[x].ls].tag+=t[x].tag;
        t[t[x].rs].tag+=t[x].tag;
        t[t[x].ls].mx.fs+=t[x].tag;
        t[t[x].rs].mx.fs+=t[x].tag;
        t[x].tag=0;
    }
}

int build(int l,int r)
{
    int x=++cnt;
    t[x].l=l,t[x].r=r;
    if(l==r)
    {
        t[x].mx=mp(0,1);
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
        t[x].mx.fs+=v;
        t[x].tag+=v;
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

int a[N];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        vis[i]=n+1;
    for(int i=n;i>=1;i--)
        nx[i]=vis[a[i]],vis[a[i]]=i;
    build(1,n);
    for(int i=1;i<=n;i++)
        vis[i]=0;
    int col=0;
    for(int i=1;i<=n;i++)
        if(!vis[a[i]])
        {
            vis[a[i]]=1;
            ++col;
            if(i-1>=1)
                change(1,1,i-1,1);
            pos[a[i]].push_back(0);
        }
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        if(pos[a[i]].size()==4)
        {
            change(1,pos[a[i]][0]+1,pos[a[i]][1],-1);
            pos[a[i]].erase(pos[a[i]].begin());
        }
        if(pos[a[i]].back()+1<=i-1)
            change(1,pos[a[i]].back()+1,i-1,-1);
        pos[a[i]].push_back(i);
         if(pos[a[i]].size()==4)
            change(1,pos[a[i]][0]+1,pos[a[i]][1],1);
        if(pos[a[i]].back()+1<=nx[i]-1)
            change(1,pos[a[i]].back()+1,nx[i]-1,1);
        if(t[1].mx.fs==col)
            ans+=t[1].mx.sd;
    }
    printf("%lld\n",ans);
}