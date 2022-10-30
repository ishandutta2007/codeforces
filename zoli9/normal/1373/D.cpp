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
    ll res=0;
    vll a(n);
    for(int i=0; i<n; i++)
    {
      cin>>a[i];
      if(i%2==0) res+=a[i];
    }
    vll w1;
    for(int i=1; i<n; i+=2)
    {
      w1.push_back(a[i]-a[i-1]);
    }
    ll w1max=0;
    ll w1min=0;
    ll w1sum=0;
    for(ll u: w1)
    {
      w1sum+=u;
      w1min=min(w1min, w1sum);
      w1max=max(w1max, w1sum-w1min);
    }
    vll w2;
    for(int i=2; i<n; i+=2)
    {
      w2.push_back(a[i-1]-a[i]);
    }
    ll w2max=0;
    ll w2min=0;
    ll w2sum=0;
    for(ll u: w2)
    {
      w2sum+=u;
      w2min=min(w2min, w2sum);
      w2max=max(w2max, w2sum-w2min);
    }
    res+=(max(w1max, w2max));
    cout<<res<<'\n';
  }
	return 0;
}