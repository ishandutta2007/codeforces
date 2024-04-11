#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int b,k,ans=0;;
   cin>>b>>k;
   for(int i=0;i<k;i++){
      cin>>a[i];
      ans+=a[i];
   }
   if(b%2==0){
      if(a[k-1]%2==0)
         cout<<"even"<<endl;
      else
         cout<<"odd"<<endl;
   }else{
      if(ans%2==0)
         cout<<"even"<<endl;
      else
         cout<<"odd"<<endl;
   }
}