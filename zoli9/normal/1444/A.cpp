#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//(double)clock() / CLOCKS_PER_SEC;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    ll p, q;
    while(test--)
    {
      ll ans=1;
      cin>>p>>q;
      if(p%q!=0)
      {
        cout<<p<<'\n';
        continue;
      }
      ll n=q;
      for(ll i=2; i*i<=n; i++) {
        if(n%i!=0) continue;
        ll cnt=0;
        while(n%i==0)
        {
          n/=i;
          cnt++;
        }
        ll m=p;
        while(m%i==0) {
          m/=i;
        }
        for(ll cnt2=1; cnt2<=cnt-1; cnt2++)
        {
          m*=i;
        }
        ans=max(ans, m);
      }
      if(n>1)
      {
        ll m=p;
        while(m%n==0) {
          m/=n;
        }
        ans=max(ans, m);
      }
      cout<<ans<<'\n';
    }
    return 0;
}