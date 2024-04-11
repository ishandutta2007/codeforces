#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

ll infi=1e18;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
      ll a, b, x, y, n;
      cin>>a>>b>>x>>y>>n;
      ll ans=infi;
      if(a-n>=x)
      {
        ans=min(ans, (a-n)*b);
      }
      else
      {
        ll m=n-(a-x);
        ll b1=max(y, b-m);
        ans=min(ans, x*b1);
      }
      if(b-n>=y)
      {
        ans=min(ans, (b-n)*a);
      }
      else
      {
        ll m=n-(b-y);
        ll a1=max(x, a-m);
        ans=min(ans, a1*y);
      }
      cout<<ans<<'\n';
    }


    return 0;
}