#include<bits/stdc++.h>
#define maxs 4
#define maxn 100050
using namespace std;
typedef long long LL;

const char *S="hard";

int n,a[maxn];
char s[maxn];

LL dp[maxn][maxs+2];

int chr(char c)
{
    // cout<<"chr:"<<c<<endl;
    for (int i=0;i<4;++i)
        if (S[i]==c)
            return i+1;
    return -1;
}

int main()
{
    scanf("%d%s",&n,s+1);
    for (int i=1;i<=n;++i)
        scanf("%d",a+i);
    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=0;
    for (int i=1;i<=n;++i)
    {
        int c=chr(s[i]);
        memcpy(dp[i],dp[i-1],sizeof(dp[i]));

        // cout<<i<<" "<<c<<endl;
        if (~c)
        {
            dp[i][c-1]=dp[i][c-1]+a[i];
            dp[i][c]=min(dp[i-1][c-1],dp[i-1][c]);
        }

        // for (int s=0;s<maxs;++s)
        //     cout<<i<<" "<<s<<" "<<dp[i][s]<<endl;
    }

    LL ans=1LL<<60;
    for (int s=0;s<maxs;++s)
        ans=min(ans,dp[n][s]);
    printf("%lld\n",ans);
    return 0;
}