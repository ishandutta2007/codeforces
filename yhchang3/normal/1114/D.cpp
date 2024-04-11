#include<bits/stdc++.h>
using namespace std;
int a[5000];
int dp[2][5000][5001];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
      cin>>a[i];
   for(int i=0;i<n;i++)
      for(int j=i;j<n;j++)
         dp[0][i][j]=dp[1][i][j]=10000;
   /*for(int i=0;i<n;i++)
      dp[i][i]=0;
   for(int l=2;l<=n;l++){
      for(int i=0;i+l-1<n;i++){
         int j=i+l-1;
         dp[i][j]=min(dp[i][j],(a[i]==a[i+1]||a[i]==a[j])?dp[i+1][j]:dp[i+1][j]+1);
         dp[i][j]=min(dp[i][j],(a[j]==a[j-1]||a[i]==a[j])?dp[i][j-1]:dp[i][j-1]+1);
      }
   }
   cout<<dp[0][n-1]<<endl;*/
   dp[0][0][n-1]=dp[1][0][n-1]=0;
   for(int l=n-1;l>=1;l--){
      for(int i=0;i+l-1<n;i++){
         int j=i+l-1;
         if(i-1>=0){
            dp[0][i][j]=min(dp[0][i][j],a[i]==a[i-1]?dp[0][i-1][j]:dp[0][i-1][j]+1);
            dp[1][i][j]=min(dp[1][i][j],a[j]==a[i-1]?dp[0][i-1][j]:dp[0][i-1][j]+1);
         }
         if(j+1<n){
            dp[0][i][j]=min(dp[0][i][j],a[i]==a[j+1]?dp[1][i][j+1]:dp[1][i][j+1]+1);
            dp[1][i][j]=min(dp[1][i][j],a[j]==a[j+1]?dp[1][i][j+1]:dp[1][i][j+1]+1);
         }
      }
   }
   int ans=10000;
   for(int i=0;i<n;i++)
      ans=min(ans,dp[0][i][i]);
   cout<<ans<<endl;
}