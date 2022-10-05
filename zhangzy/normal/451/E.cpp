#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;

ll n, s, a[22], ans, inv;

ll K(ll x,ll y=mod-2){ return y? K(x*x%mod,y/2)*(y&1? x: 1)%mod: 1; }

ll C(ll x){
  if (x<0) return 0;
  ll res=inv;
  for (int i=1;i<n;++i) res=res*(x+i)%mod;
  return res;
}

int main(){
  cin>>n>>s;
  inv=1; for (int i=1;i<n;++i) inv=inv*i%mod; inv=K(inv);
  for (int i=0;i<n;++i) cin>>a[i];
  for (int i=0;i<1<<n;++i){
    ll l=s;
    for (int j=0;j<n;++j)
      if (i>>j&1) l-=a[j]+1;
    ans+= (__builtin_popcount(i)&1? -1: 1)* C(l%mod);
  }
  cout<<(ans%mod+mod)%mod<<endl;
}