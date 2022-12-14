#include<bits/stdc++.h>
using namespace std;
int a[100001];
int dp[100001];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin>>n;
   int tmp=0,ans=0;
   for(int i=1;i<=n;i++){
      cin>>a[i];
      tmp=max(tmp,a[i]);
   }
   for(int i=1;i<=n;i++){
      dp[i]=(a[i]==tmp?dp[i-1]+1:0);
      ans=max(ans,dp[i]);
   }
   cout<<ans<<endl;
}