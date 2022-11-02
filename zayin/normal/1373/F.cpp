#include<bits/stdc++.h>
#define maxn 1000050
using namespace std;
typedef long long LL;

int n;
LL a[maxn],b[maxn];

LL dp[maxn][2];

int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;++i)
            scanf("%lld",a+i);
        for (int i=1;i<=n;++i)
            scanf("%lld",b+i);
        
        LL ans=1e18;
        for (int c=0;c<=1;++c)  {
            // cout<<"c:"<<endl;
            if (c)  {//cut a1
                dp[1][0]=a[1];
                dp[1][1]=a[1]+b[1];
            } else  {
                dp[1][0]=a[1];
                dp[1][1]=b[1];
            }
            for (int i=2;i<=n;++i)  {
                dp[i][0]=min(dp[i-1][0],dp[i-1][1])+a[i];
                dp[i][1]=min(dp[i-1][0]+a[i],dp[i-1][1])+b[i];
            }

            // for (int i=1;i<=n;++i)
            //     cout<<"dp["<<i<<"]="<<dp[i][0]<<" "<<dp[i][1]<<endl;

            ans=min(ans,dp[n][1]);
            if (c)
                ans=min(ans,dp[n][0]);
        }

        for (int i=1;i<=n;++i) ans-=a[i];
        puts(ans<0?"NO":"YES");
    }
    return 0;
}