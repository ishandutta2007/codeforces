#include <bits/stdc++.h>
using namespace std;

const int N = 100006;
const int INF = 1000000007;

int cnt[N],cnt2[N];
int h[506];
int dp[506][5006];

int solve(int num,int k)
{
    int n=cnt[num],m = cnt2[num];
    for (int i=0;n>=i;i++)
    {
        for (int j=0;m>=j;j++)
        {
            dp[i][j] = -INF;
        }
    }
    dp[0][m] = 0;
    int ret=0;
    for (int i=1;n>=i;i++)
    {
        for (int j=0;m>=j;j++)
        {
            for (int kk=0;k>=kk;kk++)
            {
                if (j + kk > m) break;
                dp[i][j] = max(dp[i][j],dp[i-1][j + kk] + h[kk]);
                ret = max(ret,dp[i][j]);
            }
        }
    }
    return ret;
}

int main ()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for (int i=1;n*k>=i;i++)
    {
        int x;
        scanf("%d",&x);
        cnt2[x]++;
    }
    for (int i=1;n>=i;i++)
    {
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }
    for (int i=1;k>=i;i++)
    {
        scanf("%d",&h[i]);
    }
    int ans=0;
    for (int i=1;100000>=i;i++)
    {
        if (cnt[i] && cnt2[i]) ans += solve(i,k);
    }
    printf("%d\n",ans);
}