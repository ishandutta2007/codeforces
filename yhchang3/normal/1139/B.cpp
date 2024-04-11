#include<bits/stdc++.h>
using namespace std;
long long int a[200005];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin>>n;
   for(int i=1;i<=n;i++)
      cin>>a[i];
   long long int ans=0;
   long long int now=2e9;
   for(int i=n;i>=1;i--){
      now=min(now,a[i]);
      ans+=now;
      if(!now)
         break;
      now--;
   }
   cout<<ans<<endl;
}