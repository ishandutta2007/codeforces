#include<bits/stdc++.h>
using namespace std;
bool notprime[100010];
int dp[11][11][11][11][11],dig[5];
void solve(int x){
   int ans=0;
   int tmp=x;
   for(int i=0;i<5;i++){
      dig[i]=tmp%10;
      tmp/=10;
   }
   if(x>=10000){
      for(int a=0;a<10;a++)
         for(int b=0;b<10;b++)
            for(int c=0;c<10;c++)
               for(int d=0;d<10;d++)
                  for(int e=0;e<10;e++)
                     for(int f=0;f<10;f++)
                        ans+=dp[dig[3]][10][a][b][c]*dp[dig[2]][a][10][d][e]*dp[dig[1]][b][d][10][f]*dp[dig[0]][c][e][f][10];
   }
   else if(x>=1000){
      for(int a=0;a<10;a++)
         for(int b=0;b<10;b++)
            for(int c=0;c<10;c++)
               ans+=dp[0][dig[2]][10][a][b]*dp[0][dig[1]][a][10][c]*dp[0][dig[0]][b][c][10];
   }
   else if(x>=100){
      for(int a=0;a<10;a++)
         ans+=dp[0][0][dig[1]][10][a]*dp[0][0][dig[0]][a][10];
   }
   else
      ans+=dp[0][0][0][dig[0]][10];
   cout<<ans<<endl;
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);

   for(int i=2;i<=9999;i++){
      if(!notprime[i])
         for(int j=i*i;j<=99999;j+=i)
            notprime[j]=true;
   }
   for(int i=2;i<=99999;i++){
      if(!notprime[i]){
         dp[10][i%10000/1000][i%1000/100][i%100/10][i%10]++;
         dp[i/10000][10][i%1000/100][i%100/10][i%10]++;
         dp[i/10000][i%10000/1000][10][i%100/10][i%10]++;
         dp[i/10000][i%10000/1000][i%1000/100][10][i%10]++;
         dp[i/10000][i%10000/1000][i%1000/100][i%100/10][10]++;
      }
   }
   int t,x;
   cin>>t;
   for(int i=1;i<=t;i++){
      cin>>x;
      solve(x);
   }
}