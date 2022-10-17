#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7,P=1e9+7;

int fac[N],inv[N];

int qpow(int a,int b)
{
    int ret=1;
    while(b)
    {
        if(b&1)
            ret=1ll*ret*a%P;
        b>>=1;
        a=1ll*a*a%P;
    }
    return ret;
}

void pre(int n)
{
    fac[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=1ll*fac[i-1]*i%P;
    inv[n]=qpow(fac[n],P-2);
    for(int i=n-1;i>=0;i--)
        inv[i]=1ll*inv[i+1]*(i+1)%P;
}

int C(int n,int m)
{
    if(n<m||m<0||n<0)
        return 0;
    return 1ll*fac[n]*inv[m]%P*inv[n-m]%P;
}

int n,k;

int sz[N],ans;

vector<int>g[N];

void dfs(int x,int f)
{
    sz[x]=1;
    for(auto v:g[x])
    {
        if(v==f)
            continue;
        dfs(v,x);
        sz[x]+=sz[v];
    }
    int ways=0;
    for(auto v:g[x])
    {
        int SZ;
        if(v==f)
            SZ=n-sz[x];
        else
            SZ=sz[v];
        ways=(ways+C(SZ,k))%P;
    }
    for(auto v:g[x])
    {
        int SZ;
        if(v==f)
            SZ=n-sz[x];
        else
            SZ=sz[v];
        ans=(ans+1ll*SZ*C(n-SZ-1,k-1)%P*(n-SZ))%P;
        ans=(ans+1ll*SZ*(C(n-1-SZ,k)-(ways-C(SZ,k)))%P*(n-SZ)%P+P)%P;
    }
    ans=(ans+1ll*n*(C(n-1,k)-ways)%P+P)%P;
    ans=(ans+1ll*n*C(n-1,k-1)%P)%P;
}

int main()
{
    scanf("%d%d",&n,&k);
    pre(n);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    printf("%d\n",ans);
}