#include<bits/stdc++.h>
using namespace std;

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   long long int ans=0,x,s,dp0=1,dp1=0,a,b;
   cin>>s>>x;
   if(x==0&&s%2==0){
      cout<<1<<endl;
      return 0;
   }
   if(s==x)
      ans-=2;
   if(x>s){
      cout<<0<<endl;
      return 0;
   }
   while(s){
      a=s%2;
      b=x%2;
      s/=2;
      x/=2;
      if(a==b){
         if(a==0){
            dp0=dp0;
            dp1=dp0;
         }
         else{
            dp0=2*dp0;
            dp1=0;
         }
      }
      else{
         if(b==0){
            dp0=dp1;
            dp1=dp1;
         }
         else{
            dp0=0;
            dp1=2*dp1;
         }
      }
   }
   if(!dp0)
      cout<<0<<endl;
   else
      cout<<ans+dp0<<endl;
}