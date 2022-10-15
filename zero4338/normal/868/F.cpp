#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
int read()
{
    int ret=0;char c=getchar();
    while(c>'9'||c<'0')c=getchar();
    while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
    return ret;
}
const int maxn=1e5+5;
const int maxk=25;
int n,k;
int a[maxn],cnt[maxn];
ll f[maxn],g[maxn];
ll nv;int pl,pr;
void calc(int l,int r)
{
    while(pl>l)
    {
        pl--;nv+=cnt[a[pl]];
        cnt[a[pl]]++;
    }
    while(pr<r)
    {
        pr++;nv+=cnt[a[pr]];
        cnt[a[pr]]++;
    }
    while(pl<l)
    {
        nv-=cnt[a[pl]]-1;
        cnt[a[pl]]--;
        pl++;
    }
    while(pr>r)
    {
        nv-=cnt[a[pr]]-1;
        cnt[a[pr]]--;
        pr--;
    }
}
void solve(int l,int r,int nl,int nr)
{
    if(nl>nr)return;
    int mid=(nl+nr)>>1;
    int p=mid-1;ll mv=g[p];
    for(int i=l;i<=min(r,mid-1);i++)
    {
        calc(i+1,mid);
        if(nv+g[i]<mv)p=i,mv=nv+g[i];
    }
    f[mid]=mv;
    solve(l,p,nl,mid-1);solve(p,r,mid+1,nr);
}
int main()
{
    n=read();k=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++)
    {
        g[i]=g[i-1]+cnt[a[i]];
        cnt[a[i]]++;
    }
    pl=1;pr=n;nv=g[n];
    k--;
    while(k--)
    {
        solve(0,n-1,1,n);
        for(int i=1;i<=n;i++)g[i]=f[i],f[i]=0;
    }
    printf("%lld",g[n]);
    return 0;
}