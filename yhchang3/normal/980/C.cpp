#include<bits/stdc++.h>
using namespace std;
int a[256];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n,k,x,j;
   cin>>n>>k;
   memset(a,-1,sizeof a);
   for(int i=1;i<=n;i++){
      if(i!=1) cout<<' ';
      cin>>x;
      if(a[x]!=-1){
         cout<<x-a[x];
         continue;
      }
      for(j=x;j>=max(0,x-k+1);j--){
         if(a[j]!=-1){
            if(j-a[j]>=x-k+1)
               j=j-a[j]-1;
            break;
         }
      }
      for(int z=j+1;z<=x;z++)
         a[z]=z-j-1;
      cout<<x-a[x];
   }
   cout<<endl;
}