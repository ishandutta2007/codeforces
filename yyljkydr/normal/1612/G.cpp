#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e6+1e3+7,D=1e6,P=1e9+7,iv2=(P+1)/2;

int n,a[N],c[N];

int m;

int ans,ways,fac[N];

signed main()
{
    scanf("%lld",&n);
    fac[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=fac[i-1]*i%P;
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]),m+=a[i];
    for(int i=1;i<=n;i++)
    {
        c[-(a[i]-1)+D]++;
        c[a[i]+1+D]--;
    }
    for(int i=-D;i<=D;i++)
        c[i+D]+=c[i-2+D];
    ways=1;
    for(int i=D;i>=-D;i--)
    {
        ans=(ans+(m+(m-c[i+D]+1))%P*c[i+D]%P*iv2%P*i%P+P)%P;
        m-=c[i+D];
        ways=ways*fac[c[i+D]]%P;
    }
    printf("%lld %lld\n",ans,ways);
}