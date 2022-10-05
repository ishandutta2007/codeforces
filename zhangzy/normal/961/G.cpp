#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int n, k, x;
ll jc[202000], inv[202000], sum, ans;

ll K(ll x,int y=mod-2){
  return y? K(x*x%mod,y/2)*(y&1? x: 1)%mod: 1;
}
ll C(int x,int y){
  return x<y? 0: jc[x]*inv[y]%mod*inv[x-y]%mod;
}

ll doit(int n,int k){
  ll res=0;
  for (int i=1;i<=k;++i){
    res+= K(mod-1,k-i)*C(k,i)%mod*K(i,n)%mod;
  }
  res=res%mod*inv[k]%mod;
  return res;
}

int main(){
  cin>>n>>k;
  jc[0]=1; for (int i=1;i<=n;++i) jc[i]=jc[i-1]*i%mod;
  inv[n]=K(jc[n]); for (int i=n;i;--i) inv[i-1]=inv[i]*i%mod;
  for (int i=1;i<=n;++i){
    scanf("%d",&x); sum+=x;
  }
  sum%=mod;
  ans=doit(n,k)+doit(n-1,k)*(n-1)%mod;
  ans=ans*sum%mod;
  cout<<ans<<endl;
}