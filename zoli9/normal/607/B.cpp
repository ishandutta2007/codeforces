#include <bits/stdc++.h>
using namespace std;
int n;
int t[509];
int dp[509][509];
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
    }
    for(int h=0; h<n; h++)
    {
        for(int i=1; i<=n-h; i++)
        {
            if(h==0)
            {
                dp[i][i]=1;
                continue;
            }
            if(h==1)
            {
                if(t[i]==t[i+1]) dp[i][i+1]=1;
                else dp[i][i+1]=2;
                continue;
            }
            dp[i][i+h]=1+dp[i+1][i+h];
            if(t[i]==t[i+h]) dp[i][i+h]=min(dp[i][i+h], dp[i+1][i+h-1]);
            if(t[i]==t[i+1]) dp[i][i+h]=min(dp[i][i+h], 1+dp[i+2][i+h]);
            for(int ind=i+2; ind<i+h; ind++)
            {
                if(t[ind]==t[i]) dp[i][i+h]=min(dp[i][i+h], dp[i+1][ind-1]+dp[ind+1][i+h]);
            }
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}