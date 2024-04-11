#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

int n;

long long f[N],a[N];

vector<int>g[N];

long long mx=-1e18,cnt=0;

void dp(int x,int F)
{
    f[x]=a[x];
    for(auto v:g[x])
    {
        if(v==F)
            continue;
        dp(v,x);
        if(f[v]>0)
            f[x]+=f[v];
    }
}

void calc(int x,int F)
{
    f[x]=a[x];
    for(auto v:g[x])
    {
        if(v==F)
            continue;
        calc(v,x);
        if(f[v]>0)
            f[x]+=f[v];
    }
    if(f[x]==mx)
        cnt++,f[x]=0;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dp(1,0);
    mx=*max_element(f+1,f+n+1);
    calc(1,0);
    printf("%lld %lld\n",mx*cnt,cnt);
}