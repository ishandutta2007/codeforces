#include<bits/stdc++.h>
using namespace std;
long long int a[500001];
long long int b[500001];
long long int n,r,k,x;
bool check(long long int t){
   long long int now = 0,ans=0;
   memset(b,0,sizeof b);
   for(int i=0;i<n;i++){
      now+=b[i];
      if(a[i]+now<t){
         ans+=(t-now-a[i]);
         if(ans>k)   return false;
         if(i+2*r+1<=n-1)
            b[i+2*r+1]-=(t-now-a[i]);
         now=t-a[i];
      }
   }
   return ans<=k;
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   cin>>n>>r>>k;
   for(int i=0;i<n;i++){
      cin>>x;
      if(i-r<0)
         a[0]+=x;
      else
         a[i-r]+=x;
      if(i+r+1<=n-1)
         a[i+r+1]-=x;
   }
   long long int left=a[0],right=3000000000000000000LL;
   for(int i=1;i<n;i++){
      a[i]+=a[i-1];
      left=min(left,a[i]);
   }
   while(left<right){
      long long int mid=(left+right+1)/2;
      if(check(mid))
         left=mid;
      else
         right=mid-1;
   }
   cout<<left<<endl;
}