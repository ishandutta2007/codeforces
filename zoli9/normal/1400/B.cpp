#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int test;
    cin>>test;
    while(test--)
    {
      ll p, f, cs, cw, s, w;
      cin>>p>>f;
      cin>>cs>>cw;
      cin>>s>>w;
      if(s>w)
      {
        swap(w, s);
        swap(cw, cs);
      }
      ll ans=0;
      ll maxpc=p/s;
      ll maxfc=f/s;
      for(ll i=0; i<=cs; i++)
      {
        ll h1=min(i, maxpc);
        ll h2=min(cs-i, maxfc);
        ll pp=p-h1*s;
        ll ff=f-h2*s;
        ll cans=h1+h2;
        ll g1=pp/w;
        ll g2=ff/w;
        ll h3=min(g1+g2, cw);
        cans+=h3;
        ans=max(ans, cans);
      }
      cout<<ans<<'\n';
    }


    return 0;
}