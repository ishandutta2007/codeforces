#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=5e2+1e1+7,P=998244353;

int n,x,pw[N][N],fac[N],inv[N];

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

/*
f[i][j] i people maximum health x

f[i][j] = f[i - t][x - i * r] * C(i, t) * (i^t)
*/

int f[N][N];

signed main()
{
    scanf("%lld%lld",&n,&x);
    for(int i=0;i<=n;i++)
    {
        pw[i][0]=1;
        for(int j=1;j<=n;j++)
            pw[i][j]=pw[i][j-1]*i%P;
    }
    fac[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=fac[i-1]*i%P;
    inv[n]=qpow(fac[n],P-2);
    for(int i=n-1;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%P;
    f[0][0]=1;
    for(int i=2;i<=n;i++)
        for(int j=1;j<=x;j++)
        {
            if(j>i-1)
                f[i][j]=f[i][j-(i-1)];
            else
                f[i][j]=(pw[j][i]-pw[j-1][i]+P)%P;
            for(int t=1;t<=i-2;t++)
            {
                if(j>i-1)
                    f[i][j]=(f[i][j]+f[i-t][j-(i-1)]*fac[i]%P*inv[t]%P*inv[i-t]%P*pw[i-1][t])%P;
            }
        }
    int ans=0;
    for(int i=1;i<=x;i++)
        ans=(ans+f[n][i])%P;
    printf("%lld\n",ans);
}