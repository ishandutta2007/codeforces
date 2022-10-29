#include <bits/stdc++.h>
using namespace std;

const int N = 3006;

int dp[4][N];

int s[N];
int c[N];

int main ()
{
    memset(dp,-1,sizeof(dp));
    int n;
    scanf("%d",&n);
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&s[i]);
    }
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&c[i]);
        dp[1][i] = c[i];
    }
    for (int i=2;3>=i;i++)
    {
        for (int j=1;n>=j;j++)
        {
            int mn = 1234567890;
            for (int k=1;j>k;k++)
            {
                if (s[j] > s[k] && dp[i-1][k] != -1)
                {
                    mn = min(mn,dp[i-1][k] + c[j]);
                }
            }
            if (mn != 1234567890) dp[i][j] = mn;
        }
    }
    int ans = -1;
    for (int i=1;n>=i;i++)
    {
        if (dp[3][i] != -1)
        {
            if (ans == -1) ans = dp[3][i];
            else ans = min(ans,dp[3][i]);
        }
    }
    printf("%d\n",ans);
}