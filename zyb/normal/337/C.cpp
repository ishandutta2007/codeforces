#include<stdio.h>
#define inf 1000000009
using namespace std;
long long n,m,k,ans;
struct syf
{
    long long f[2][2];
    long long n,m;
    friend inline syf operator * (syf a,syf b)
    {
        syf c;c.n=a.n;c.m=a.m;
        c.f[0][0]=c.f[0][1]=c.f[1][0]=c.f[1][1]=0;
        for (long long i=0;i<a.n;i++)
        for (long long j=0;j<b.m;j++)
        for (long long k=0;k<a.m;k++)
        c.f[i][j]=(c.f[i][j]+a.f[i][k]*1ll*b.f[k][j])%inf;
        return c;
    }
}a,b;
inline long long quick(long long dxe,long long o,long long p)
{
    syf a;a.f[0][0]=1;a.n=1;a.m=2;
    a.f[0][1]=0;
    syf b;b.n=b.m=2;
    b.f[0][0]=1;b.f[0][1]=p;
    b.f[1][0]=0;b.f[1][1]=o;
    while (dxe)
    {
        if (dxe&1)
        a=a*b;
        dxe/=2;
        b=b*b;
    }
    return a.f[0][1];
}
inline long long work(long long m,long long o,long long p)
{
    if (m==0)
    return 0;
    return (quick(m+1,o,p)-k+inf)%inf;
}
int main()
{
    scanf("%I64d%I64d%I64d",&n,&m,&k);
    long long b=n-m;
    n=n-b*k;
    if (n<0)
    {
        printf("%d\n",m);
        return 0;
    }
    m=m-b*(k-1);
    ans=work(m/k,2,k);
    ans=(ans+m%k)%inf;
    ans=(ans+b*(k-1))%inf;
    printf("%I64d\n",ans);
}