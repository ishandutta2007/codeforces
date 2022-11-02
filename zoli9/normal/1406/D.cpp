#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n;
ll m[1000009];

void adding(int cs, int k, int v, int x, int y, ll pls)
{
  if(v<x || y<k) return;
  if(x<=k && v<=y)
  {
    m[cs]+=(pls);
    return;
  }
  adding(2*cs, k, (k+v)/2, x, y, pls);
  adding(2*cs+1, (k+v)/2+1, v, x, y, pls);
}

ll ask(int cs, int k, int v, int x)
{
  if(x<k || v<x) return 0;
  if(k==v) return m[cs];
  ll res=m[cs];
  res+=ask(2*cs, k, (k+v)/2, x);
  res+=ask(2*cs+1, (k+v)/2+1, v, x);
  return res;
}

ll d4(ll x)
{
  if(x%4==0) return x/4;
  else if(x<0) return x/4;
  else return x/4+1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    ll dfsum=0;
    ll last;
    for(int i=0; i<n; i++)
    {
      ll x;
      cin>>x;
      adding(1, 0, n-1, i, i, x);
      if(i>0) dfsum+=(abs(x-last));
      last=x;
    }
    cout<<d4(dfsum+ask(1, 0, n-1, 0)+ask(1, 0, n-1, n-1))<<'\n';
    int test;
    cin>>test;
    while(test--)
    {
      int k, v;
      ll d;
      cin>>k>>v>>d;
      k--;
      v--;
      ll ak=ask(1, 0, n-1, k);
      ll av=ask(1, 0, n-1, v);
      if(k>0)
      {
        ll ak1=ask(1, 0, n-1, k-1);
        dfsum-=(abs(ak-ak1));
        dfsum+=(abs(ak+d-ak1));
      }
      if(v<n-1)
      {
        ll av1=ask(1, 0, n-1, v+1);
        dfsum-=(abs(av-av1));
        dfsum+=(abs(av+d-av1));
      }
      adding(1, 0, n-1, k, v, d);
      cout<<d4(dfsum+ask(1, 0, n-1, 0)+ask(1, 0, n-1, n-1))<<'\n';
    }    
    return 0;
}