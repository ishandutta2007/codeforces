#include<bits/stdc++.h>
using namespace std;
long long int ans=0,lleft=0;
long long int a[400000];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
      cin>>a[i];
   for(int i=0;i<n;i++){
      long long int tmp=min(lleft,a[i]/2);
      ans+=tmp;
      lleft-=tmp;
      a[i]-=tmp*2;
      lleft+=a[i]%3;
      ans+=a[i]/3;
   }
   cout<<ans<<endl;
}