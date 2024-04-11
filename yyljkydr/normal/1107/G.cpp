#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=3e5+1e3+7;

int n,a;

int d[N],c[N],v[N],r[N];

struct Data{
    int fa;
    int lmx,rmx;
    int sum,ans;
}f[N];

int find(int x)
{
    return x==f[x].fa?x:f[x].fa=find(f[x].fa);
}

void merge(Data &x,Data &y)
{
    x.fa=y.fa;
    y.ans=max({y.ans,x.ans,y.lmx+x.rmx});
    y.lmx=max(y.lmx+x.sum,x.lmx);
    y.rmx=max(y.rmx,x.rmx+y.sum);
    y.sum=x.sum+y.sum;
}

bool cmp(int x,int y)
{
    return v[x]<v[y];
}

signed main()
{
    scanf("%lld%lld",&n,&a);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&d[i],&c[i]);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        f[i].fa=i;
        f[i].sum=f[i].lmx=f[i].rmx=f[i].ans=a-c[i];
        ans=max(ans,f[i].ans);
    }
    for(int i=1;i<n;i++)
        v[i]=d[i+1]-d[i],r[i]=i;
    sort(r+1,r+n,cmp);
    for(int i=1;i<n;i++)
    {
        int x=r[i],y=x+1;
        int fx=find(x),fy=find(y);
        merge(f[fx],f[fy]);
        ans=max(ans,f[fy].ans-v[x]*v[x]);
    }
    printf("%lld\n",ans);
}