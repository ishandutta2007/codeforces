#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

string s;

int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin>>test;
  while(test--)
  {
    int n;
    cin>>n;
    ll k;
    cin>>k;
    ll a;
    map<ll, int> ma;
    ll ans=0;
    for(int i=0; i<n; i++)
    {
      cin>>a;
      if(a%k==0) continue;
      a=(k-a%k);
      ma[a]++;
      ans=max(ans, (ma[a]-1)*k+a+1);
    }
    cout<<ans<<'\n';
  }
	return 0;
}