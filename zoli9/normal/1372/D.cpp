#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  vector<ll> t(n+1);
  vector<ll> ff(n+1);
  vector<ll> bb(n+1);
  for(int i=1; i<=n; i++)
  {
    cin>>t[i];
  }
  if(n==1)
  {
    cout<<t[1]<<endl;
    return 0;
  }
  ff[1]=t[1];
  ff[2]=t[2];
  bb[n]=t[n];
  bb[n-1]=t[n-1];
  for(int i=3; i<=n; i++)
  {
    ff[i]=t[i]+ff[i-2];
  }
  for(int i=n-2; i>=1; i--)
  {
    bb[i]=t[i]+bb[i+2];
  }
  ll ans=bb[1];
  for(int i=2; i<=n; i++)
  {
    ans=max(ans, bb[i]+ff[i-1]);
  }
  cout<<ans<<endl;
  
	return 0;
}