#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int dp[9][9][2];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n,m,x,ans=0;
   cin>>n>>m;
   for(int i=1;i<=n;i++){
      cin>>x;
      a[x]++;
   }
   if(m==1){
      cout<<a[1]/3<<endl;
      return 0;
   }
   if(m==2){
      cout<<a[2]/3+a[1]/3<<endl;
      return 0;
   }
   for(int i=1;i<=m;i++){
      while(a[i]>8){
         ans++;
         a[i]-=3;
      }
   }
   dp[a[1]][a[2]][2]=0;
   for(int i=a[1];i>=0;i-=3)
      for(int j=a[2];j>=0;j-=3)
         dp[i][j][0]=(a[1]+a[2]-i-j)/3;
   for(int i=3;i<=m;i++){
      for(int j=0;j<=a[i-2];j++){
         for(int k=0;k<=a[i-1];k++){
            for(int l=min(min(j,k),a[i]);l>=0;l--){
               dp[k-l][a[i]-l][i%2]=max(dp[k-l][a[i]-l][i%2],dp[j][k][(i-1)%2]+l);
            }
         }
      }
      for(int j=0;j<=8;j++)
         for(int k=min(5,a[i]-3);k>=0;k--)
            dp[j][k][i%2]=max(dp[j][k][i%2],dp[j][k+3][i%2]+1);
   }
   int tmp=0;
   for(int i=0;i<=8;i++)
      for(int k=0;k<=8;k++)
         tmp=max(tmp,dp[i][k][m%2]);
   cout<<ans+tmp<<endl;
}