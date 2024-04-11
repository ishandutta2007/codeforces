#include<bits/stdc++.h>
using namespace std;

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n,l1,r1,l2,r2;
   cin>>n;
   for(int i=0;i<n;i++){
      cin>>l1>>r1>>l2>>r2;
      if(l1==l2)
         cout<<l1<<' '<<r2<<endl;
      else
         cout<<l1<<' '<<l2<<endl;
   }
}