#include<bits/stdc++.h>
using namespace std;
int n;
int a[5000001];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>n;
   for(int i=0;i<n;i++)
      cin>>a[i];
   sort(a,a+n);
   int l=0,r=n/2;
   int ans=n;
   while(l<n/2&&r<n){
      if(a[r]<2*a[l])
         r++;
      else{
         ans--;
         l++;r++;
      }
   }
   cout<<ans<<endl;
}