#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
int n;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin>>test;
  while(test--)
  {
    cin>>n;
    vll a(n);
    vll b(n);
    ll asum=0;
    ll bsum=0;
    for(int i=0; i<n; i++)
    {
      cin>>a[i];
      asum+=a[i];
    }
    for(int i=0; i<n; i++)
    {
      cin>>b[(i+1)%n];
      bsum+=b[(i+1)%n];
    }
    if(asum>bsum)
    {
      cout<<"NO"<<'\n';
      continue;
    }
    bool ok=true;
    ll mini=0;
    ll sum=0;
    for(int i=0; i<2*n; i++) {
      sum-=b[i%n];
      if(sum-mini>0)
      {
        ok=false;
        break;
      }
      sum+=a[i%n];
      mini=min(mini, sum);
    }
    if(ok) cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
  }
	return 0;
}