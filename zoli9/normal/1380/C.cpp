#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin>>test;
  int n;
  ll x;
  while(test--)
  {
    cin>>n>>x;
    vector<ll> t(n);
    vector<ll> dp(n+1);
    for(int i=0; i<n; i++)
    {
      cin>>t[i];
    }
    sort(t.begin(), t.end());
    if(t[n-1]>=x) dp[n-1]=1;
    else dp[n-1]=0;
    dp[n]=0;
    for(int i=n-2; i>=0; i--)
    {
      dp[i]=dp[i+1];
      if(t[i]>=x)
      {
        dp[i]=1+dp[i+1];
      }
      else
      {
        ll hh=x/t[i];
        if(x%t[i]!=0) hh++;
        if(i+hh<=n)
        {
          dp[i]=max(dp[i], 1+dp[i+hh]);
        }
      }
    }
    cout<<dp[0]<<'\n';
  }
  
  
	return 0;
}