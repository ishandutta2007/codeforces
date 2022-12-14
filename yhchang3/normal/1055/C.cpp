#include<bits/stdc++.h>
using namespace std;
long long int GCD(long long int a,long long int b){
   if(a<b)
      swap(a,b);
   while((a%=b)&&(b%=a));
   return max(a,b);
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   long long int la,ra,ta,g;
   long long int lb,rb,tb;
   cin>>la>>ra>>ta>>lb>>rb>>tb;
   g=GCD(ta,tb);
   ra-=la/g*g;
   la%=g;
   rb-=lb/g*g;
   lb%=g;
   long long int ans=0;
   ans=max(ans,min(ra,rb)-max(la,lb)+1);
   if(la<=lb){
      la+=g;ra+=g;
   }
   else{
      lb+=g;rb+=g;
   }
   ans=max(ans,min(ra,rb)-max(la,lb)+1);
   cout<<ans<<endl;
}