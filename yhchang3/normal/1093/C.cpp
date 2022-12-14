#include<bits/stdc++.h>
using namespace std;
long long int b[100010],a[200010];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin>>n;
   for(int i=1;i<=n/2;i++)
      cin>>b[i];
   a[0]=0;a[n+1]=2e18;
   for(int i=1;i<=n/2;i++){
      if(b[i]-a[i-1]>a[n-i+2])
         a[i]=b[i]-a[n-i+2];
      else
         a[i]=a[i-1];
      a[n-i+1]=b[i]-a[i];
   }
   for(int i=1;i<=n;i++){
      if(i!=1) cout<<' ';
      cout<<a[i];
   }
   cout<<endl;
}