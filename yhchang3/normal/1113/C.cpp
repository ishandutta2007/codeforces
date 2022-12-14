#include<bits/stdc++.h>
using namespace std;
long long int a[1200000];
long long int b[1200000];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
   int n;
   long long int ans=0;
   int tmp=0,x;
   cin>>n;
   a[0]++;
   for(int i=0;i<n;i++){
      cin>>x;
      tmp^=x;
      if(i%2)
         a[tmp]++;
      else
         b[tmp]++;
   }
   for(int i=0;i<=1100000;i++){
      //cout<<i<<' '<<a[i]<<' '<<b[i]<<endl;
      ans+=a[i]*(a[i]-1)/2;
      ans+=b[i]*(b[i]-1)/2;
   }
   cout<<ans<<endl;
}