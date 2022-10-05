#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int n, m, k, f[1510], g[1510], p[1510], p0, np0, fz, fm, all;
ll jc[101000], inv[101000];

ll K(ll x,int y=mod-2){
  return y? K(x*x%mod,y/2)*(y&1?x:1)%mod: 1;
}
ll C(int x,int y){
  return x<y? 0: jc[x] *inv[y]%mod *inv[x-y]%mod;
}
inline void U(ll &x,ll y){
  x+=y; if (x>=mod) x-=mod;
}

int main(){
  cin>>n>>m>>fz>>fm>>k; p0=fz*K(fm)%mod; np0=(mod+1-p0)%mod;
  jc[0]=1; for (int i=1;i<=k;++i) jc[i]=jc[i-1]*i%mod;
  inv[k]=K(jc[k]); for (int i=k;i;--i) inv[i-1]=inv[i]*i%mod;
  
  for (int i=0;i<=m&&i<=k;++i){
    p[i]=C(k,i)*K(p0,i)%mod*K(np0,k-i)%mod;
  }
  //for (int i=0;i<=m;++i) cout<<p[i]<<endl;
  
  f[m]=1;
  for (int tim=n;tim--;){
    ll sp=p[0], sf=0;
    for (int i=1;i<=m;++i){
      g[i]=(g[i-1]+ ( (f[m]-f[m-i])*sp-sf )%mod *p[m-i] )%mod;
      if (g[i]<0) g[i]+=mod;
      U(sp,p[i]); U(sf,(ll)f[i]*p[i]%mod);
    }
    memcpy(f,g,sizeof (int)*(m+2));
  }
  cout<<f[m]<<endl;
}