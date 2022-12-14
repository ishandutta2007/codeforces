#include<bits/stdc++.h>
using namespace std;
bool good(long long int a,long long int b){
   if(b==0) return true;
   if(b==1) return false;
   bool shouldgo=good(b,a%b);
   if(shouldgo)   return false;
   if(b&1){
      if((a/b)&1)
         return true;
      else
         return false;
   }
   // long long int tmp=-(a%b);
   // while(a){
   //    tmp+=a%b;
   //    a/=b;
   // }
   // if(tmp&1)
   //    return true;
   // else
   //    return false;
   long long int tmp=a/b%(b+1);
   if(tmp==0||tmp%2==0)
      return false;
   else
      return true;
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int t;
   cin>>t;
   long long int a,b;
   while(t--){
      cin>>a>>b;
      if(a<b)
         swap(a,b);
      if(good(a,b))
         cout<<"Second"<<endl;
      else
         cout<<"First"<<endl;
   }
}