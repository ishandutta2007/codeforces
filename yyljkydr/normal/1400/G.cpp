#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=3e5+1e3+7,M=41,P=998244353;

int n,m;

int l[N],r[N],a[M],b[M],c[N];

int s[N][M];

int fac[N],inv[N];

int C(int n,int m)
{
    if(n<0||m<0||n<m)
        return 0;
    return fac[n]*inv[m]%P*inv[n-m]%P;
}

int qpow(int a,int b)
{
    int ret=1;
    while(b)
    {
        if(b&1)
            ret=ret*a%P;
        b>>=1;
        a=a*a%P;
    }
    return ret;
}

int vis[N];

signed main()
{
    scanf("%lld%lld",&n,&m);
    fac[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=fac[i-1]*i%P;
    inv[n]=qpow(fac[n],P-2);
    for(int i=n-1;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%P;
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&l[i],&r[i]),c[l[i]]++,c[r[i]+1]--;
    for(int i=1;i<=m;i++)
        scanf("%lld%lld",&a[i],&b[i]);
    for(int i=1;i<=n;i++)
    {
        c[i]+=c[i-1];
        for(int j=0;j<=m*2;j++)
            s[i][j]=(s[i-1][j]+C(c[i]-j,i-j))%P;
    }
    int ans=0;
    for(int S=0;S<(1<<m);S++)
    {
        int tot=0,L=1,R=n;
        for(int i=1;i<=m;i++)
            if(S&(1<<(i-1)))
            {
                tot+=!vis[a[i]],tot+=!vis[b[i]];
                vis[a[i]]=vis[b[i]]=1;
                L=max(L,l[a[i]]),R=min(R,r[a[i]]);
                L=max(L,l[b[i]]),R=min(R,r[b[i]]);
            }
        for(int i=1;i<=m;i++)
            vis[a[i]]=vis[b[i]]=0;
        if(L>R)
            continue;
        ans=(ans+(__builtin_popcount(S)&1?P-1:1)*(s[R][tot]-s[L-1][tot]+P)%P)%P;
    }
    printf("%lld\n",ans);
}