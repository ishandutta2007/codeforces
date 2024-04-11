#include <bits/stdc++.h>
using namespace std;
int n;
long long dp[2][100009];
long long t[2][100009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<2; i++) for(int j=1; j<=n; j++) cin>>t[i][j];
    for(int j=1; j<=n; j++)
    {
        for(int i=0; i<2; i++)
        {
            dp[i][j]=t[i][j];
            if(j>1)
            {
                dp[i][j]+=dp[1-i][j-1];
            }
            if(j>2)
            {
                dp[i][j]=max(dp[i][j], t[i][j]+dp[1-i][j-2]);
            }
        }
    }
    cout<<max(dp[0][n], dp[1][n])<<endl;


    return 0;
}