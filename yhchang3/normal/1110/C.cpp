#include<bits/stdc++.h>
using namespace std;

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int q,x,z;
   cin>>q;
   while(q--){
      cin>>x;
      z=floor(log2(x+0.5));
      z=1<<(z+1);
      if(x!=z-1)
         cout<<z-1<<endl;
      else{
         int b=ceil(sqrt(x));
         bool sw=0;
         for(int i=2;i<=b;i++){
            if(x%i==0){
               sw=1;
               cout<<x/i<<endl;
               break;
            }
         }
         if(sw==0)
            cout<<1<<endl;
      }
   }
}