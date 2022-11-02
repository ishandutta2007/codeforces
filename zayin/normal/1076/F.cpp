#include<bits/stdc++.h>
#define maxn 300050
#define inf (LL)0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long LL;

int n,m;

LL a[maxn][2];
LL dp[maxn][2];

void init()
{
    scanf("%d%d",&n,&m);
    for (int k=0;k<=1;++k)
        for (int i=1;i<=n;++i)
            scanf("%lld",&a[i][k]);
}

bool solve()
{
    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=dp[0][1]=0;
    for (int i=1;i<=n;++i)
    {
        for (int k=0;k<=1;++k)
        {
            for (int j=0;j<=1;++j)
            {
                if (dp[i-1][j]==inf)   continue;
                LL cnt=a[i][k]+(k==j?dp[i-1][j]:0),d=(cnt-1)/m,lim=a[i][k]*m-(k==j?0:dp[i-1][j]);
                if (d>a[i][k^1]||lim<a[i][k^1]) continue;
                if (d==a[i][k^1])
                    dp[i][k]=min(dp[i][k],cnt-d*m);
                else
                    dp[i][k]=min(dp[i][k],1LL);
            }
        }

        // printf("%d %d %d %d %d\n",i,dp[i][0],dp[i][1],a[i][0],a[i][1]);
        if (dp[i][0]==inf&&dp[i][1]==inf) 
            return 0;
    }
    return 1;
}

int main()
{
    // freopen("c.in","r",stdin);
    // freopen("c.out","w",stdout);
    init();
    puts(solve()?"YES":"NO");
    return 0;
}