#include<bits/stdc++.h>
using namespace std;
int GCD(int x,int y){
   if(x<y)  swap(x,y);
   while((x%=y)&&(y%=x));
   return max(x,y);
}
int a[100010];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n,k,ans,x;
   cin>>n>>k;
   ans=k;
   for(int i=1;i<=n;i++){
      cin>>x;
      ans=GCD(ans,x);
   }
   cout<<k/ans<<endl;
   for(int i=0;i*ans<k;i++){
      if(i!=0) cout<<' ';
      cout<<i*ans;
   }
   cout<<endl;

}