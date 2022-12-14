#include<bits/stdc++.h>
using namespace std;

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n,cnt1=0,cnt2=0,x;
   cin>>n;
   int ans=(n+1)/2;
   for(int i=0;i<n;i++){
      cin>>x;
      if(x>0)  cnt1++;
      if(x<0)  cnt2++;
   }
   if(cnt1>=ans){
      cout<<1<<endl;
      return 0;
   }
   if(cnt2>=ans){
      cout<<-1<<endl;
      return 0;
   }
   cout<<0<<endl;
}