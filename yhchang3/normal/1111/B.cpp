#include<bits/stdc++.h>
using namespace std;
int a[100010];
long long int sum=0,n,k,m;;
double ans=0;
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   cin>>n>>k>>m;
   for(int i=0;i<n;i++){
      cin>>a[i];
      sum+=a[i];
   }
   sort(a,a+n);
   for(int i=0;i<n;i++){
      if(m-i<0)   break;
      if(m-i>k*(n-i))
         ans=max(ans,(sum+k*(n-i))/(double) (n-i));
      else
         ans=max(ans,(sum+m-i)/(double) (n-i));
      sum-=a[i];
   }
   cout<<fixed<<setprecision(30)<<ans<<endl;
}