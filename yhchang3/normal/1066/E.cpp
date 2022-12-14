#include<bits/stdc++.h>
using namespace std;
int n,m;
long long int ans=0;
long long int MOD=998244353;
long long int now=0;
long long int exp(int x){
   if(x==0) return 1;
   if(x==1) return 2;
   long long int y=exp(x/2);
   y=(y*y)%MOD;
   if(x%2)
      y=y*2%MOD;
   return y;
}
string sn,sm;
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>n>>m>>sn>>sm;
   for(int i=1;i<=m;i++){
      if(n-i>=0&&sn[n-i]=='1')
            now=(now+exp(i-1))%MOD;
      if(sm[m-i]=='1')
         ans=(ans+now)%MOD;
   }
   cout<<ans<<endl;
}