#include<bits/stdc++.h>
#define maxm 7050
using namespace std;
typedef long long LL;

const int n=8,L=840;

LL m,a,dp[maxm];

int main()  {
    memset(dp,0x80,sizeof(dp));
    dp[0]=0;

    scanf("%lld",&m);
    for (int i=1;i<=n;++i)  {
        scanf("%lld",&a);
        int c=L/i;
        for (int j=maxm-1;~j;--j)
            for (int t=0;t<c&&t<=a&&t*i<=j;++t)
                dp[j]=max(dp[j],dp[j-t*i]+(a-t)/c);
    }
    LL ans=0;
    for (int j=0;j<maxm&&j<=m;++j)
        ans=max(ans,min((m-j)/L,dp[j])*L+j);
    printf("%lld\n",ans);
    return 0;
}