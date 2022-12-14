#include<bits/stdc++.h>
using namespace std;

int last[5005];
int dp[5005];
int sum[5005];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n,x;
   cin>>n;
   sum[0]=dp[0]=0;
   for(int i=1;i<=n;i++){
      cin>>x;
      sum[i]=sum[i-1]+x;
      dp[i]=last[i]=1e9;
   }
   for(int i=1;i<=n;i++)
      for(int j=0;j<i;j++)
         if(sum[i]-sum[j]>=last[j]&&dp[i]>=dp[j]+i-j-1){
            dp[i]=dp[j]+i-j-1;
            last[i]=min(last[i],sum[i]-sum[j]);
         }
   cout<<dp[n]<<endl;
}