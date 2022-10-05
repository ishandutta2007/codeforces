#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007

ll n, k, f[5050][5050], ans;

ll K(ll x,ll y){ return y? K(x*x%mod,y/2)*(y&1?x:1)%mod: 1; }

ll S(int x,int y){
  if (f[x][y]) return f[x][y];
  return f[x][y]= x<y||y<2? x>=y: (S(x-1,y-1)+S(x-1,y)*y)%mod;
}

int main(){
  std::cin>>n>>k;
  for (ll i=1,c=1;i<=k;++i){
    c=c*(n-i+1)%mod;
    ans=(ans+ S(k,i) *c%mod *K(2,n-i)%mod)%mod;
  }
  std::cout<<ans;
}