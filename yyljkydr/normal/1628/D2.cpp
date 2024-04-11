#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e6+1e3+7,P=1e9+7,iv2=(P+1)/2;

int T;

int n,m,k;

// int f[N][N];

int fac[N],inv[N];

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

void pre(int n)
{
    fac[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=fac[i-1]*i%P;
    inv[n]=qpow(fac[n],P-2);
    for(int i=n-1;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%P;
}

int C(int n,int m)
{
    if(n<m||n<0||m<0)
        return 0;
    return fac[n]*inv[m]%P*inv[n-m]%P;
}

signed main()
{
    pre(1e6);
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld%lld",&n,&m,&k);
        // for(int i=1;i<=n;i++)
        //     for(int j=0;j<=i;j++)
        //     {
        //         if(i==j)
        //             f[i][j]=(f[i-1][j-1]+k)%P;
        //         else if(j==0)
        //             f[i][j]=f[i-1][j];
        //         else
        //             f[i][j]=(f[i-1][j-1]+f[i-1][j])*iv2%P;
        //     }
        // printf("%lld\n",f[n][m]);
        int ans=0,ps=0;
        for(int i=1;i<=m;i++)
        {
            //go from(i,i) -> (n,m)
            ans=(ans+C(n-i,m-i)%P*qpow(iv2,n-i)%P*(k*i%P-(i-1)*k%P*iv2%P+P)%P)%P;
        }
        printf("%lld\n",ans);
    }
}