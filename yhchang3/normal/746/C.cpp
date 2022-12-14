#include<bits/stdc++.h>
using namespace std;

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int x1,x2,s,t1,t2,p,d,ans;
   cin>>s>>x1>>x2>>t1>>t2>>p>>d;
   int tt=abs(x2-x1)*t2;

   if(d==-1){
      x1=s-x1;
      x2=s-x2;
      p=s-p;
   }
   if(p<=x2){
      if(x1<=x2){
         if(x1<p){
            ans=min(tt,(s-p+s+x2)*t1);
         }
         else{
            ans=min(tt,(x2-p)*t1);
         }
      }
      else{
         ans=min(tt,(s-p+s-x2)*t1);
      }
   }
   else{
      if(x1<=x2)
         ans=min(tt,(s-p+s+x2)*t1);
      else
         ans=min(tt,(s-p+s-x2)*t1);
   }
   cout<<ans<<endl;
}