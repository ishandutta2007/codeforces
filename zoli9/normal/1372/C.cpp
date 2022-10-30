#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin>>test;
  while(test--)
  {
    int n;
    cin>>n;
    vector<int> t(n+1);
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
      cin>>t[i];
      if(i==t[i]) cnt++;
    }
    if(cnt==n)
    {
      cout<<0<<'\n';
      continue;
    }
    if(cnt==0)
    {
      cout<<1<<'\n';
      continue;
    }
    int mini=0;
    int maxi=0;
    for(int i=1; i<=n; i++)
    {
      if(t[i]!=i)
      {
        mini=i;
        break;
      }
    }
    for(int i=n; i>=1; i--)
    {
      if(t[i]!=i)
      {
        maxi=i;
        break;
      }
    }
    bool oke=true;
    for(int i=mini; i<=maxi; i++)
    {
      if(t[i]==i)
      {
        oke=false;
        break;
      }
    }
    if(oke) cout<<1<<'\n';
    else cout<<2<<'\n';
    
  }
	return 0;
}