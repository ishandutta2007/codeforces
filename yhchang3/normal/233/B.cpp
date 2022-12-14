#include<bits/stdc++.h>
using namespace std;
long long int n,ans=1e18;
int s(long long int x){
   int tmp=0;
   while(x){
      tmp+=x%10;
      x/=10;
   }
   return tmp;
}
long long int solve(int dig){
   long long int zz=round(sqrt(dig*dig+4*n));
   if(zz*zz!=dig*dig+4*n)
      return -1;
   return (zz-dig)/2;
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=81;i++){
      if(solve(i)!=-1&&s(solve(i))==i)
         ans=min(ans,solve(i));
   }
   if(ans>1e17)
      cout<<-1<<endl;
   else
      cout<<ans<<endl;
}