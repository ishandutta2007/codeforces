#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[300000];
bool pack(int x){
   int cnt=1,now=k;
   for(int i=x;i<=n;i++){
      if(a[i]>k)  return 0;
      if(a[i]<=now)  now-=a[i];
      else{
         cnt++;
         now=k-a[i];
      }
   }
   return cnt<=m;
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>n>>m>>k;
   for(int i=1;i<=n;i++)
      cin>>a[i];
   int left=1,right=n+1;
   while(left<right){
      int mid=(left+right)/2;
      if(pack(mid)) right=mid;
      else left=mid+1;
   }
   cout<<n+1-left<<endl;
}