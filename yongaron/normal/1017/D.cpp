#include<fstream>
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int n, q, m;
int w[12345];
int s[12345];

int wus[12345][105];

int number(string s)
{
  int ans = 0;
  int po = 1;
  for(int i = 0; i < n; i++)
  {
    ans += (s[n-i-1]-'0')*po;
    po *= 2;
  }
  //cout<<"!"<<ans<<"!"<<endl;
  return ans;
}

int wu(int a, int b)
{
  int ans = 0;
  for(int i = 0; i < n; i++)
  {
    if(a%2 == b%2)
      ans += w[n-i-1];
    a /= 2;
    b /= 2;
  }
  return ans;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin>>n>>m>>q;
  string t;
  for(int i = 0; i < n; i++)
    cin>>w[i];
  for(int i = 0; i < m; i++)
  {
    cin>>t;
    s[number(t)]++;
  }
  for(int i = 0; i < 1<<n; i++)
  {
    for(int j = 0; j < 1<<n; j++)
    {
      if(s[j])
      {
        int x = wu(i, j);
        if(x < 101)
          wus[i][x]+= s[j];
      }
    }
    for(int j = 1; j < 102; j++)
      wus[i][j] += wus[i][j-1];
  }
  int k;
  for(int i = 0; i < q; i++)
  {
    cin>>t>>k;
    printf("%d\n", wus[number(t)][k]);
  }
  return 0;
}