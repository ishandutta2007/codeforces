#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n,d;
   cin>>n>>d;
   int l=0,r=0;
   long long int ans=0;
   for(int i=0;i<n;i++)
      cin>>a[i];
   while(r<n){
      if(a[r]-a[l]<=d){
         r++;
      }
      else{
         ans+=(long long int) (r-l-1)*(r-l-2)/2;
         l++;
      }
   }
   for(int i=l;i<n;i++)
      ans+=(long long int) (r-i-1)*(r-i-2)/2;
      cout<<ans<<endl;
}