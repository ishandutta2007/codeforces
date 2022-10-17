#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T;

int n,k,a[N],last[N],f[N][21];

map<int,int>vis;

int cnt;

struct T{
    int l,r,ls,rs;
    pair<int,int> mx;
}t[N*2+1];

#define fs first
#define sd second

void cmx(pair<int,int> &a,pair<int,int>b)
{
    if(b.fs>a.fs)
        swap(b.fs,a.fs);
    a.sd=max(a.sd,max(b.fs,b.sd));
}

void update(int x)
{
    cmx(t[x].mx,t[t[x].ls].mx);
    cmx(t[x].mx,t[t[x].rs].mx);
}

int build(int l,int r)
{
    int x=++cnt;
    t[x].l=l,t[x].r=r;
    t[x].mx=make_pair(0,0);
    if(l==r)
    {
        t[x].mx.fs=last[l];
        return x;
    }
    int mid=(l+r)>>1;
    t[x].ls=build(l,mid);
    t[x].rs=build(mid+1,r);
    update(x);
    return x;
}

pair<int,int> query(int x,int l,int r)
{
    if(l<=t[x].l&&t[x].r<=r)
        return t[x].mx;
    int mid=(t[x].l+t[x].r)>>1;
    pair<int,int> ret=make_pair(0,0);
    if(l<=mid)
        cmx(ret,query(t[x].ls,l,r));
    if(r>mid)
        cmx(ret,query(t[x].rs,l,r));
    return ret;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        vis.clear();
        cnt=0;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            for(int j=2;j*j<=a[i];j++)
                while(a[i]%(j*j)==0)
                    a[i]/=j*j;
            last[i]=vis[a[i]];
            vis[a[i]]=i;
        }
        build(1,n);
        for(int i=0;i<=n;i++)
            for(int j=0;j<=k;j++)
                f[i][j]=0;
        multiset<int>s;
        s.insert(0);
        for(int i=1;i<=n;i++)
        {
            s.insert(last[i]);
            auto it=s.end();
            for(int j=0;j<=k;j++)
                f[i][j]=n+1;
            for(int j=0;j<=min(i,k);j++)
            {
                --it;
                int x=*it;
                for(int t=j;t<=min(i,k);t++)
                    f[i][t]=min(f[i][t],f[x][t-j]+1);
            }
        }
        int ans=1e9;
        for(int i=0;i<=k;i++)
            ans=min(ans,f[n][i]);
        printf("%d\n",ans);
    }
}