#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef vector<int> vi;
 
ll t[200009];
map<ll, ll> ma;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin>>n;
  t[0]=0;
  ma[0]=0;
  ll ans=0;
  ll mini=-1;
  for(ll i=1; i<=n; i++)
  {
    ll x;
    cin>>x;
    t[i]=t[i-1]+x;
    if(ma.find(t[i])!=ma.end())
    {
      mini=max(mini, ma[t[i]]);
    }
    ma[t[i]]=i;
    ans+=(i-mini-1);
  }
  cout<<ans<<endl;
  
  
  return 0;
}