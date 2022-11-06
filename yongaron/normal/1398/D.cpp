#include<iostream>
#include<algorithm>

using namespace std;

int r, g, b;
int rs[222], gs[222], bs[222];

int dp[222][222][222];

int main(int argc, char const *argv[]) {
  cin>>r>>g>>b;
  for(int i = 0; i < r; i++)
    cin>>rs[i];
  for(int i = 0; i < g; i++)
    cin>>gs[i];
  for(int i = 0; i < b; i++)
    cin>>bs[i];
  sort(rs, rs+r);
  sort(gs, gs+g);
  sort(bs, bs+b);
  for(int i = 0; i <= r; i++)
  {
    for(int j = 0; j <= g; j++)
    {
      for(int l = 0; l <= b; l++)
      {
        dp[i+1][j][l] = max(dp[i+1][j][l], dp[i][j][l]);
        dp[i][j+1][l] = max(dp[i][j+1][l], dp[i][j][l]);
        dp[i][j][l+1] = max(dp[i][j][l+1], dp[i][j][l]);
        dp[i+1][j+1][l] = max(dp[i+1][j+1][l], dp[i][j][l]+rs[i]*gs[j]);
        dp[i+1][j][l+1] = max(dp[i+1][j][l+1], dp[i][j][l]+rs[i]*bs[l]);
        dp[i][j+1][l+1] = max(dp[i][j+1][l+1], dp[i][j][l]+gs[j]*bs[l]);
      }
    }
  }
  cout<<dp[r][g][b]<<endl;
  return 0;
}