#include<bits/stdc++.h>
using namespace std;
int a[1001],ans=0;
bool sw;
int main(){
   int n,r;
   cin>>n>>r;
   for(int i=1;i<=n;i++)
      cin>>a[i];
   for(int i=1;i<=n;i++){
      sw=0;
      for(int j=i+r-1;j>=i-r+1;j--){
         if(j>n)  continue;
         if(j<1)  break;
         if(a[j]){
            ans++;
            i=j+r-1;
            sw=1;
            break;
         }
      }
      if(!sw){
         cout<<-1<<endl;
         return 0;
      }
   }
   cout<<ans<<endl;
}