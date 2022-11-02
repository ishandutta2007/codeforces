#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s, z, w="";
ll mod=998244353, ans=0;
ll dp[3009][3009];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s>>z;
  int si=s.size();
  int zi=z.size();
  while(z.size()<s.size()) z+=".";
  for(int i=si-1; i>=0; i--) w+=s[i];
  for(int j=0; j<=si; j++) dp[si][j]=1;
  for(int j=0; j<si; j++)
  {
    if(w[si-1]==z[j] || z[j]=='.') dp[si-1][j]=2;
    else dp[si-1][j]=0;
  }
  for(int i=si-2; i>=0; i--)
  {
    for(int j=0; j<=i; j++)
    {
      int last=si-(i-j)-1;
      if(w[i]==z[j] || z[j]=='.') dp[i][j]=(dp[i][j]+dp[i+1][j+1])%mod;
      if(w[i]==z[last] || z[last]=='.') dp[i][j]=(dp[i][j]+dp[i+1][j])%mod;
    }
  }
  for(int i=0; i<=si-zi; i++) ans=(ans+dp[i][0])%mod;
  cout<<ans<<endl;	return 0;
}