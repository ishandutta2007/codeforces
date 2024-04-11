#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int n,m,a,b;
long long int fac[1000001];
long long int inv[1000001];
long long int exp(long long int x,int y){
   if(y==0) return 1;
   if(y==1) return x;
   long long int tmp=exp(x,y/2);
   if(y%2)
      return (tmp*tmp%mod)*x%mod;
   else
      return tmp*tmp%mod;
}
long long int cal(int x){
   long long int res=fac[n-2];
   res=res*inv[n-2-x]%mod;
   res=res*exp(m,n-2-x)%mod;
   res=res*fac[m-1]%mod;
   res=res*inv[x]%mod;
   res=res*inv[m-1-x]%mod;
   if(n-x-3>=0){
      res=res*(x+2)%mod;
      res=res*exp(n,n-x-3)%mod;
   }
   return res;
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>n>>m>>a>>b;
   fac[0]=1;
   inv[0]=1;
   for(int i=1;i<=1000000;i++){
      fac[i]=fac[i-1]*i%mod;
      inv[i]=exp(fac[i],mod-2);
   }
   long long int ans=0;
   for(int i=0;i<=min(m-1,n-2);i++)
      ans=(ans+cal(i))%mod;
   cout<<ans<<endl;
}