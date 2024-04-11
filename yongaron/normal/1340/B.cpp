#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n, k;
string s;

int a[2222];
int dp[2222][2222];

int nums[] = {0b01110111, 0b00010010, 0b01011101, 0b01011011, 0b00111010, 0b01101011, 0b01101111, 0b01010010, 0b01111111, 0b01111011};

void print(int x)
{
  string s = "";
  for(int i = 0; i < 7; i++)
  {
    if(x&1)
    {
      s = '1'+s;
    }
    else
      s = '0'+s;
    x /= 2;
  }
  cout<<s<<endl;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin>>n>>k;
  for(int i = 0; i < n; i++)
  {
    cin>>s;
    int num = 0;
    for(int j = 0; j < 7; j++)
      num += (1<<(7-j-1))*(s[j]-'0');
    a[i] = num;
  }
  for(int i = 0; i <= n; i++)
    for(int j = 0; j <= k; j++)
      dp[i][j] = -1;
  dp[0][0] = 0;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j <= k; j++)
    {
      for(int f = 9; f >= 0; f--)
      {
        // cout<<i<<" "<<j<<" "<<f<<" "<<__builtin_popcount(nums[f]^a[n-i-1])<<endl;
        if((nums[f]&a[n-i-1]) == a[n-i-1] &&  __builtin_popcount(nums[f])-__builtin_popcount(a[n-i-1]) <= j)
        {
          if(dp[i][j-__builtin_popcount(nums[f]^a[n-i-1])] != -1)
          {
            dp[i+1][j] = f;
            break;
          }
        }
      }
    }
  }
  for(int i = n; i; i--)
  {
    // cout<<i<<" "<<k<<endl;
    cout<<dp[i][k];
    if(dp[i][k] == -1)
      break;
    k -= __builtin_popcount(nums[dp[i][k]]^(a[n-i]));
  }
  cout<<endl;
  return 0;
}