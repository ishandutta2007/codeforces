#include<bits/stdc++.h>
#define maxn 500050
#define inf (1LL<<50)
using namespace std;
typedef long long LL;

int n,m;
LL a[maxn];

LL dp[maxn];

void init()
{
    scanf("%d",&n);
    m=n>>1;
    for (int i=1;i<=m;++i)
        scanf("%lld",&a[i]);
}

bool solve()
{
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for (int i=1;i<=m;++i)
    {
        for (LL x=1;x*x<a[i];++x)
        {
            if (a[i]%x) continue;
            LL y=a[i]/x;
            if ((x^y)&1)    continue;
            LL p=(y-x)>>1,q=(x+y)>>1;
            if (p*p>dp[i-1])
                dp[i]=min(dp[i],q*q);
        }
    }

    if (dp[m]>inf)
        puts("No");
    else
    {
        puts("Yes");
        for (int i=1;i<=m;++i)
            printf("%lld %lld ",dp[i]-dp[i-1]-a[i],a[i]);
    }
}

int main()
{
    init();
    solve();
    return 0;
}