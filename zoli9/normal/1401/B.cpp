#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin>>test;
  while(test--)
  {
    ll x0, y0, x1, y1, x2, y2;
    cin>>x0>>x1>>x2;
    cin>>y0>>y1>>y2;
    ll sum=x0+x1+x2;
    ll v21=min(x2, y1);
    sum-=v21;
    ll ans=v21*2;
    x2-=v21;
    y1-=v21;
    ll pl=x1+y2-sum;
    if(pl>0)
    {
      ans-=(2*pl);
    }
    cout<<ans<<'\n';
  }
	return 0;
}