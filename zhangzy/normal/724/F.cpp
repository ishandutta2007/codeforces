#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, mod, f[1010][11][1010], inv[12];

void U(int &x,int y){
  x+=y; if (x>=mod) x-=mod;
}
int cal(int n,int d,int k){
  k=min(k,n-1);
  if (~f[n][d][k]) return f[n][d][k];
  if (n==1) return d==m-1||!d;
  if (!k) return 0;
  int res=cal(n,d,k-1), t=cal(k,m-1,k-1), s=1;
  for (int i=1;i<=d&&i*k<n;++i){
    s=(ll)s*(t+i-1)%mod*inv[i]%mod;
    U(res,(ll)s*cal(n-i*k,d-i,k-1)%mod);
  }
  return f[n][d][k]=res;
}

int main(){
  cin>>n>>m>>mod;
  if (n==1) return puts("1"),0;
  inv[1]=1;
  for (int i=2;i<12;++i)
    inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
  memset(f,-1,sizeof f);
  int ans=cal(n,m,n-1>>1);
  if (n%2==0){
    ll e=cal(n/2,m-1,n-1>>1);
    U(ans,e*(e+1)/2%mod);
  }
  cout<<ans<<endl;
}