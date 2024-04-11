#include<bits/stdc++.h>
using namespace std;
int a[400000];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n;
   int ans=0;
   cin>>n;
   for(int i=1;i<=n;i++)
      cin>>a[i];
   for(int i=1;i<=n;i++)
      if(a[i]!=a[n]){
         ans=max(ans,n-i);
         break;
      }
   for(int i=n;i>=1;i--)
      if(a[i]!=a[1]){
         ans=max(ans,i-1);
         break;
      }
   cout<<ans<<endl;
}