#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int r, n;

int x[123456], y[123456], t[123456], dp[123456], ma[123456];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>r>>n;
  x[0] = y[0] = 1;
  for(int i = 1; i <= n; i++)
  {
    cin>>t[i]>>x[i]>>y[i];
    dp[i] = -1e9;
    int j = i-1;
    while(j >= 0 && t[i]-t[j] <= 2*r)
    {
      if(abs(x[j]-x[i])+abs(y[j]-y[i]) <= t[i]-t[j])
      {
        dp[i] = max(dp[i], dp[j]+1);
      }
      j--;
    }
    if(j >= 0)
      dp[i] = max(dp[i], ma[j]+1);
    ma[i] = max(ma[i-1], dp[i]);
  }
  cout<<ma[n]<<endl;
  return 0;
}