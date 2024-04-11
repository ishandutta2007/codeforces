#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int n, k;
string s, t;

int dp[209][209][209];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>n>>k;
    cin>>s;
    cin>>t;
    if(t[0]==t[1])
    {
      int cnt=0;
      for(int i=0; i<n; i++)
      {
        if(s[i]==t[0]) cnt++;
      }
      cnt=min(cnt+k, n);
      cout<<(cnt*(cnt-1))/2<<endl;
      return 0;
    }
    for(int i=n-1; i>=0; i--)
    {
      for(int j=0; j<=k; j++)
      {
        for(int before=0; before<=n; before++)
        {
          dp[i][j][before]=dp[i+1][j][before];
          if(j>0) dp[i][j][before]=max(dp[i][j][before], dp[i+1][j-1][before+1]);
          if(j>0) dp[i][j][before]=max(dp[i][j][before], before+dp[i+1][j-1][before]);
          if(s[i]==t[0])
          {
            dp[i][j][before]=max(dp[i][j][before], dp[i+1][j][before+1]);
          }
          if(s[i]==t[1])
          {
            dp[i][j][before]=max(dp[i][j][before], before+dp[i+1][j][before]);
          }
        }
      }
    }
    int ans=0;
    for(int i=0; i<=k; i++) ans=max(ans, dp[0][i][0]);
    cout<<ans<<endl;
    
    


    return 0;
}