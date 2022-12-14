#include<bits/stdc++.h>
using namespace std;
long long int p[30];
int a[30];
int stp=0;
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   long long int n,b,tmp;
   cin>>n>>b;
   tmp=b;
   for(int i=2;i<=1000000;i++){
      if(tmp%i==0){
         p[stp]=i;
         while(tmp%i==0){
            a[stp]++;
            tmp/=i;
         }
         stp++;
      }
   }
   if(tmp!=1){
      p[stp]=tmp;
      a[stp]++;
      stp++;
   }
   long long int ans=1e18;
   for(int i=0;i<stp;i++){
      long long int now=n;
      tmp=0;
      while(now){
         tmp+=(now/p[i]);
         now/=p[i];
      }
      ans=min(ans,tmp/a[i]);
   }
   cout<<ans<<endl;
}