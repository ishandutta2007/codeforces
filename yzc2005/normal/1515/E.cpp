#include<bits/stdc++.h>
using namespace std;
const int N=405;
int n,p,dp[N][N],fac[N],ifac[N],p2[N];
inline int power(int a,int b){
  int res=1;
  for(;b;b>>=1,a=1ll*a*a%p)
    if(b&1)res=1ll*res*a%p;
  return res;
}
int main(){
  scanf("%d%d",&n,&p);
  fac[0]=p2[0]=1;for(int i=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%p,p2[i]=p2[i-1]*2%p;
  ifac[n]=power(fac[n],p-2);for(int i=n-1;~i;--i)ifac[i]=1ll*ifac[i+1]*(i+1)%p;
  dp[0][0]=1;
  for(int i=1;i<=n;++i)
    for(int j=1;j<=i;++j)
      for(int k=1;k<=j;++k){
        if(k==i-1)continue;
        int pre=max(0,i-k-1);
        dp[i][j]=(dp[i][j]+1ll*dp[pre][j-k]*p2[k-1]%p*ifac[k]%p)%p;
      }
  int ans=0;
  for(int i=1;i<=n;++i)ans=(ans+1ll*fac[i]*dp[n][i])%p;  
  return printf("%d\n",ans),0;
}