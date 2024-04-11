#include<bits/stdc++.h>
#define maxn 1000050
#define modu 998244353
using namespace std;
typedef long long LL;

int n;

LL F[maxn]={1},I[maxn];

LL pw(LL a,LL k)
{
    LL ans=1;
    for (;k;k>>=1)
    {
        if (k&1)
            ans=(ans*a)%modu;
        a=a*a%modu;
    }
    return ans;
}

LL A(int n,int m)
{
    return F[n]*I[n-m]%modu;
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        F[i]=F[i-1]*i%modu;
    I[n]=pw(F[n],modu-2);
    for (int i=n;i;--i)
        I[i-1]=I[i]*i%modu;
    
    // LL ans=n*F[n]%modu;
    // for (int i=1;i<=n;++i)
    // {
    //     cout<<i<<" "<<(F[n-i-1]*(n-i-1)%modu*(n-i)+F[n-i])%modu<<endl;
    //     ans=(ans-((F[n-i-1]*(n-i-1)%modu*(n-i)+F[n-i])%modu*i)%modu+modu)%modu;
    // }
    LL ans=F[n];
    for (int i=1;i<n;++i)
        ans=(ans+A(n,i)*(F[n-i]-1))%modu;
    printf("%lld\n",ans);
    return 0;
}