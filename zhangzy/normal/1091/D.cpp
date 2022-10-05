#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 998244353
ll K(ll x,ll y=mod-2){
  ll t=1;
  for (;y;y>>=1,x=x*x%mod)
    if (y&1) t=t*x%mod;
  return t;
}

int n;
ll jc[1001000], inv[1001000];

ll C(int x,int y){
  return jc[x]*inv[y]%mod *inv[x-y]%mod;
}

int main(){
  cin>>n;
  jc[0]=1; for (int i=1;i<=n;++i) jc[i]=jc[i-1]*i%mod;
  inv[n]=K(jc[n]); for (int i=n;i>=1;--i) inv[i-1]=inv[i]*i%mod;

  ll ans=(jc[n]*n+1)%mod;
  for (int i=1;i<=n;++i){
    ans=(ans-C(n,i)*jc[n-i]%mod+mod)%mod;
  }
  cout<<ans<<endl;
}