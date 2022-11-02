#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef vector<int> vi;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin>>test;
  while(test--)
  {
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
      for(int j=1; j<=m; j++)
      {
        if(i==1 && j==1) cout<<"W";
        else cout<<"B";
      }
      cout<<'\n';
    }
  }
  
  
  return 0;
}