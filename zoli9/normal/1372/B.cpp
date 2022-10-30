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
    ll n;
    cin>>n;
    bool ok=false;
    for(ll i=2; i*i<=n; i++)
    {
      if(n%i==0)
      {
        ll x=n/i;
        cout<<x<<" "<<((n/x)-1)*x<<'\n';
        ok=true;
        break;
      }
    }
    if(!ok)
    {
      cout<<1<<" "<<n-1<<'\n';
    }
  }
	return 0;
}