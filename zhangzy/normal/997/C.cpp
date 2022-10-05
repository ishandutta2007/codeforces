#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;

ll n, ans;

ll K(ll x,ll y=mod-2){
  ll t=1;
  for (;y;y>>=1, x=x*x%mod)
    if (y&1) t=t*x%mod;
  return t;
}

int main(){
  cin>>n;
  ans= K(3,n*n)-K(K(3,n)-3,n);
  for (ll i=0, c=1;i<=n;++i){
    ll bas=K(3,n-i);
    ll res= c*(K(bas,n)-K(bas-(i==0? 3: 1)+mod,n))%mod;
    if (i) res=res*3%mod;
    ans+= i&1? -res: res;
    c= c *(n-i)%mod *K(i+1)%mod;
  }
  cout<<(ans%mod+mod)%mod<<endl;
}