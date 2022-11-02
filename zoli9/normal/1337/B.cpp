#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int test;
  cin>>test;
  while(test--)
  {
    ll x, n, m;
    cin>>x>>n>>m;
    while(x>=20 && n>0)
    {
      x=x/2+10;
      n--;
    }
    if(m*10>=x) cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
  }
  return 0;
}