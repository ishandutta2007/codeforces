#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll a, b;
int n;
string s;
ll dp[200009][2];
int test;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n>>a>>b;
        cin>>s;
        dp[0][0]=b;
        dp[0][1]=1e18;
        for(int i=0; i<n; i++)
        {
            dp[i+1][0]=1e18;
            dp[i+1][1]=1e18;
            if(s[i]=='0')
            {
                dp[i+1][0]=min(dp[i][0]+a, dp[i][1]+2*a)+b;
                dp[i+1][1]=min(dp[i][1]+a, dp[i][0]+2*a)+2*b;
            }
            else dp[i+1][1]=dp[i][1]+a+2*b;
        }
        cout<<dp[n][0]<<endl;
    }
    return 0;
}