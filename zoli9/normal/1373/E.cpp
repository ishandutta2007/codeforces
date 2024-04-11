#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

ll k;
int n;

int digsum(ll x)
{
  int res=0;
  while(x>0)
  {
    res+=(x%10);
    x/=10;
  }
  return res;
}

int sumup(ll x)
{
  int res=0;
  for(ll i=0; i<=k; i++)
  {
    res+=digsum(x+i);
  }
  return res;
}

bool checking(ll x)
{
  return sumup(x)==n;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin>>test;
  while(test--)
  {
    cin>>n>>k;
    bool ok=false;
    for(int i=0; i<1000; i++)
    {
      if(checking(i))
      {
        cout<<i<<'\n';
        ok=true;
        break;
      }
    }
    if(ok) continue;
    ll best=-1;
    for(int elso=1; elso<10; elso++)
    {
      for(int num9=0; num9<16; num9++)
      {
        for(int utolso=80; utolso<100; utolso++)
        {
          ll szam=elso;
          for(int u=1; u<=num9; u++)
          {
            szam*=10;
            szam+=9;
          }
          szam*=100;
          szam+=utolso;
          if(checking(szam))
          {
            if(best==-1 || szam<best)
            {
              best=szam;
            }
          }
        }
      }
    }
    if(best>=0) cout<<best<<'\n';
    else cout<<-1<<'\n';
  }
	return 0;
}