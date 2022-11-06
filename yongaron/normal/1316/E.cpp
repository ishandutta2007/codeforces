#include<iostream>
#include<vector>
#include<algorithm>

#define ll long long

using namespace std;

const int N = 1e5+5;

int n, p, k;

pair<ll, int> a[N];

ll dp[N][128];
ll s[N][8];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin>>n>>p>>k;
  for(int i = 0; i < n; i++)
  {
    cin>>a[i].first;
    a[i].second = i;
  }
  sort(a, a+n, [](pair<ll, int> x, pair<ll, int> y){return x.first > y.first;});
  for(int i = 0; i < n; i++)
    for(int j = 0; j < p; j++)
      cin>>s[i][j];
  dp[0][0] = 1;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < (1<<p); j++)
    {
      if(!dp[i][j])
        continue;
      dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
      int ones = 0;
      for(int l = 0; l < p; l++)
      {
        if((j&(1<<l)) == 0)
          dp[i+1][j|(1<<l)] = max(dp[i+1][j|(1<<l)], dp[i][j]+s[a[i].second][l]);
        else
          ones++;
      }
      if(i-ones < k)
        dp[i+1][j] = max(dp[i+1][j], dp[i][j]+a[i].first);
    }
  }
  ll ans = 0;
  for(int i = 0; i <= n; i++)
    ans = max(ans, dp[i][(1<<p)-1]);
  cout<<ans-1<<endl;
  return 0;
}