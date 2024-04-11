#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=5e3+1e2+7,P=998244353;

int n,a[N],cho[N];

int A[N][N],f[N][N],last[N],s[N][N],dw[N],idw[N],fac[N],inv[N];

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

signed main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        for(int j=0;j<=n;j++)
            if(a[j]*2<=a[i])
                cho[i]++,last[i]=j;
    A[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        A[i][0]=1;
        for(int j=1;j<=i;j++)
            A[i][j]=(A[i-1][j]+A[i-1][j-1]*j)%P;
    }
    dw[n]=n;
    for(int i=n-1;i>=0;i--)
        dw[i]=dw[i+1]*i%P;
    for(int i=0;i<=n;i++)
        idw[i]=qpow(idw[i],P-2);
    fac[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=fac[i-1]*i%P;
    for(int i=0;i<=n;i++)
        inv[i]=qpow(fac[i],P-2);
    f[0][0]=1;
    for(int j=0;j<=n;j++)
        s[0][j]=1;
    for(int j=0;j<=n;j++)
        s[0][j]=s[0][j]*fac[j]%P;
    for(int i=1;i<=n;i++)  
    {
        for(int j=1;j<=n;j++)
        {
            if(cho[j]<i)
                continue;
            // for(int p=0;p<=i-1;p++)
            //     f[i][j]=(f[i][j]+s[p][last[j]]*fac[last[j]-p])%P;
            f[i][j]=s[i-1][last[j]];
            f[i][j]=f[i][j]*inv[last[j]+1-i]%P;
        }
        s[i][0]=f[i][0];
        for(int j=1;j<=n;j++)
            s[i][j]=(s[i][j-1]+f[i][j])%P;
        for(int j=0;j<=n;j++)
            if(j+1-i-1>=0)
                s[i][j]=(s[i-1][j]+s[i][j]*fac[j+1-i-1]%P)%P;
    }
    printf("%lld\n",f[n][n]);
}
//(cho[j]-p-1)!/(cho[j]-i)!
//cho[j]>=i