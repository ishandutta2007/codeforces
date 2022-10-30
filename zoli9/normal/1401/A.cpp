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
    ll n, k;
    cin>>n>>k;
    if(k>n)
    {
      cout<<(k-n)<<'\n';
    }
    else
    {
      if(k%2==n%2) cout<<0<<'\n';
      else cout<<1<<'\n';
    }
  }
	return 0;
}