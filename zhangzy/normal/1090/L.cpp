#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll t, n, a, b, k;

bool chk(ll t){
  return t*k <= (n+1)/2*min(a,t) + n/2*min(b,t);
}

int main(){
  cin>>t>>n>>a>>b>>k;
  ll l=0, r=t, ans=0;
  for (;l<=r;){
    ll mid=l+r>>1;
    if (chk(mid)) ans=mid, l=mid+1;
    else r=mid-1;
  }
  cout<<ans<<endl;
}