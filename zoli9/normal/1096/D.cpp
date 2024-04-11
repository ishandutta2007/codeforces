#include <bits/stdc++.h>
using namespace std;
int n;
char s[100009];
long long amb[100009];
long long dp[100009][5];
string hard="hard";
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>s[i];
    }
    for(int i=1; i<=n; i++)
    {
        cin>>amb[i];
    }
    for(int i=n; i>=1; i--)
    {
        for(int j=0; j<4; j++)
        {
            if(s[i]==hard[j])
            {
                if(j==3)
                {
                    dp[i][j]=amb[i]+dp[i+1][j];
                }
                else
                {
                    dp[i][j]=min(amb[i]+dp[i+1][j], dp[i+1][j+1]);
                }
            }
            else
            {
                dp[i][j]=dp[i+1][j];
            }
        }
    }
    cout<<dp[1][0]<<endl;
    return 0;
}