#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, t;

ll a[33][33];

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n;
  for(int i = 0; i < n; i++)
    a[i][0] = a[n-1][i] = 0;
  for(int i = n-2; i >= 0; i--)
  {
    for(int j = 1; j < n; j++)
    {
      ll s = 0;
      for(int k = j-1; k < n; k++)
        s += a[i+1][k];
      for(int k = i+2; k < n; k++)
        s += a[k][n-1];
      for(int k = i+1; k < n; k++)
        s -= a[k][j];
      a[i][j] = s+1;
    }
  }
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
      cout<<a[i][j]<<" ";
    cout<<endl;
  }
  cin>>t;
  ll k;
  while(t--)
  {
    cin>>k;
    int x = 0;
    int y = 0;
    while(x < n-1 || y < n-1)
    {
      k -= a[x][y];
      cout<<x+1<<" "<<y+1<<endl;
      if(y == n-1)
      {
        x++;
        continue;
      }
      ll s = 0;
      for(int k = x; k < n; k++)
        s += a[k][y+1];
      if(s <= k)
        y++;
      else
        x++;
    }
    cout<<x+1<<" "<<y+1<<endl;
  }
  return 0;
}