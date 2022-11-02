#include <bits/stdc++.h>
using namespace std;
int n;
long long t[300009];
long long xmul;
long long dp[300009][4];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>xmul;
    for(int i=1; i<=n; i++) cin>>t[i];
    dp[n+1][0]=0;
    dp[n+1][1]=0;
    dp[n+1][2]=0;
    dp[n+1][3]=0;
    for(int i=n; i>=1; i--)
    {
        dp[i][3]=max(t[i]+dp[i+1][3], 0ll);
        dp[i][2]=max(t[i]*xmul+dp[i+1][2], t[i]+dp[i+1][3]);
        dp[i][2]=max(0ll, dp[i][2]);
        dp[i][1]=max(t[i]+dp[i+1][1], t[i]*xmul+dp[i+1][2]);
        dp[i][1]=max(0ll, dp[i][1]);
        dp[i][0]=max(dp[i+1][0], t[i]+dp[i+1][1]);
        dp[i][0]=max(dp[i][0], t[i]*xmul+dp[i+1][2]);
    }
    cout<<dp[1][0]<<endl;
    return 0;
}