#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

string s;

int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
  
  int test;
  cin>>test;
  while(test--)
  {
    int n;
    cin>>n;
    cin>>s;
    vector<int> a(n);
    for(int i=0; i<n; i++)
    {
      if(s[(i+1)%n]=='L')
      {
        if(s[i]=='R' || s[(i+n-1)%n]=='R')
        {
          a[i]=1;
        }
        else
        {
          a[i]=0;
        }
      }
      else
      {
        if(s[i]=='L' || s[(i+n-1)%n]=='L')
        {
          a[i]=1;
        }
        else
        {
          a[i]=0;
        }
      }
    }
    int start=0;
    bool existsGood=false;
    for(start=0; start<n; start++)
    {
      if(a[start]==1)
      {
        existsGood=true;
        break;
      }
    }
    if(!existsGood)
    {
      int ans=n/3;
      if(n%3!=0) ans++;
      cout<<ans<<'\n';
      continue;
    }
    int ans=0;
    int cur=0;
    int cnt=start+1;
    while(cnt!=start)
    {
      if(a[cnt]==0)
      {
        cur++;
      }
      else
      {
        ans+=(cur/3);
        if(cur%3!=0) ans++;
        cur=0;
      }
      cnt=(cnt+1)%n;
    }
    ans+=(cur/3);
    if(cur%3!=0) ans++;
    cur=0;
    cout<<ans<<'\n';
  }
  
	return 0;
}