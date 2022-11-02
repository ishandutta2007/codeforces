#include<bits/stdc++.h>
#define maxn 1000050
using namespace std;
typedef long long LL;

LL n,m;
LL F[maxn]={1};

int main()  {
    scanf("%lld%lld",&n,&m);
    for (int i=1;i<maxn;++i) F[i]=F[i-1]*i%m;

    LL ans=0;
    for (int i=1;i<=n;++i)  {
        ans=(ans+F[i]*F[n-i]%m*(n-i+1)%m*(n-i+1)%m)%m;
    }
    printf("%lld\n",ans);
    return 0;
}