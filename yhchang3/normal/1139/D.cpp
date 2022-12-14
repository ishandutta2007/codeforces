#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
const int mod=1e9+7;
long long int ex(long long int x,int y){
   long long int res=1;
   while(y){
      if(y&1)
         res=res*x%mod;
      x=x*x%mod;
      y/=2;
   }
   return res;
}
bool iscomposite[MAXN];
int mu[MAXN];
vector<int> prime;
void Mobius(){
   mu[1]=1;
   for(long long int i=2;i<MAXN;i++){
      if(!iscomposite[i]){
         prime.push_back(i);
         mu[i]=-1;
      }
      for(int j=0;j<prime.size()&&i*prime[j]<MAXN;j++){
         iscomposite[i*prime[j]]=true;
         if(i%prime[j]) mu[i*prime[j]]=-mu[i];
         else{
            mu[i*prime[j]]=0;
            break;
         }
      }
   }
}

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   Mobius();
   int m;
   cin>>m;
   if(m==1){
      cout<<1<<endl;
      return 0;
   }
   long long int inv=ex(m,mod-2),ans=0;
   for(int i=2;i<=m;i++){
      long long int a=m/i;
      ans=(ans-mu[i]*((a*(2*m-a)*inv%mod*ex(m-a,mod-2))%mod)+mod)%mod;
   }
   ans=(ans+inv)%mod;
   cout<<ans<<endl;
}