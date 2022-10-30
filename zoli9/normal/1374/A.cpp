#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin>>test;
  while(test--)
  {
    ll x, y, n;
    cin>>x>>y>>n;
    ll mar=n%x;
    if(mar>=y)
    {
      cout<<n-(mar-y)<<'\n';
    }
    else
    {
      mar+=x;
      cout<<n-(mar-y)<<'\n';
    }
  }
	return 0;
}