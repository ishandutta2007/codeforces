#include<bits/stdc++.h>
#define maxn 2050
#define modu 998244353
using namespace std;
typedef long long LL;

int n,m,k;
LL dp[maxn][maxn];

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=n;++i)
    {
        dp[i][0]=m;
        for (int j=1;j<i&&j<=k;++j)
            dp[i][j]=(dp[i-1][j-1]*(m-1)+dp[i-1][j])%modu;
    }
    printf("%lld\n",dp[n][k]);
    return 0;
}