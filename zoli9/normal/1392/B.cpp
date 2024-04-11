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
    ll k;
    cin>>n>>k;
    vector<ll> a(n);
    ll maxi;
    for(int i=0; i<n; i++)
    {
      cin>>a[i];
      if(i==0) maxi=a[0];
      else maxi=max(maxi, a[i]);
    }
    ll d;
    for(int i=0; i<n; i++)
    {
      a[i]=maxi-a[i];
      if(i==0) d=a[0];
      else d=max(d, a[i]);
    }
    k--;
    for(int i=0; i<n; i++)
    {
      if(k%2==0) cout<<a[i]<<" ";
      else cout<<d-a[i]<<" ";
    }
    cout<<'\n';
  }
  
	return 0;
}