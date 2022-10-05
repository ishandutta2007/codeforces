#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
ll n, f[444], g[444], t;

int main(){
  std::cin>>n; f[0]=f[1]=1;
  for (ll m=1;m<n;++m){
    memset(g,0,sizeof g);
    for (ll i=0;i<=n;++i)
      for (ll j=0;j<=i&&i+j+m<=n+1;++j)
        if (t=f[i]*f[j]%mod){
          g[i+j+1]+=t<<(i!=j);
          g[i+j]+=t*(i+i+j+j+1)<<(i!=j);
          if (i|j) g[i+j-1]+=t*(i+j)*(i+j-1)<<(i!=j);
        }
    for (ll i=0;i<=n;++i) f[i]=g[i]%mod;
  }
  std::cout<<f[1]%mod;
}