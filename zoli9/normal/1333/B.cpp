#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef vector<int> vi;
vi a, b;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin>>test;
  while(test--)
  {
    int n;
    cin>>n;
    a.resize(n);
    b.resize(n);
    for(int i=0; i<n; i++)
    {
      cin>>a[i];
    }
    for(int i=0; i<n; i++)
    {
      cin>>b[i];
    }
    bool pp=false;
    bool mm=false;
    bool ans=true;
    for(int i=0; i<n; i++)
    {
      if(a[i]<b[i])
      {
        if(!pp)
        {
          ans=false;
          break;
        }
      }
      else if(a[i]>b[i])
      {
        if(!mm)
        {
          ans=false;
          break;
        }
      }
      if(a[i]>0) pp=true;
      if(a[i]<0) mm=true;
    }
    if(ans) cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
  }
  
  
  return 0;
}