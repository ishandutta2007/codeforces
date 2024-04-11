#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
  
  int test;
  cin>>test;
  while(test--)
  {
    int n;
    cin>>n;
    vector<ll> a(n);
    ll ans=0;
    for(int i=0; i<n; i++)
    {
      cin>>a[i];
      if(i>0 && a[i]<a[i-1])
      {
        ans+=(a[i-1]-a[i]);
      }
    }
    cout<<ans<<'\n';
  }
  
	return 0;
}