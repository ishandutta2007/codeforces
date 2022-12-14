#include<bits/stdc++.h>
using namespace std;
int n,x;
int a[2][100001];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>n;
   for(int i=1;i<=2*n;i++){
      cin>>x;
      if(a[0][x])
         a[1][x]=i;
      else
         a[0][x]=i;
   }
   long long int ans=0;
   int l=1,r=1;
   for(int i=1;i<=n;i++)
      if(a[0][i]>a[1][i])
         swap(a[0][i],a[1][i]);
   for(int i=1;i<=n;i++){
      ans+=abs(l-a[0][i])+abs(r-a[1][i]);
      l=a[0][i];
      r=a[1][i];
   }
   cout<<ans<<endl;
}