#include<bits/stdc++.h>
using namespace std;
int dp[50005][101],n;
string s,sans;
void trace(int pos,int l){
   if(l==0) return;
   if(l==1){
      sans+=s[pos];
      return;
   }
   if(dp[pos][l]==n){
      trace(pos,l-1);
      return;
   }
   if(s[pos]==s[dp[pos][l]]){
      sans+=s[pos];
      trace(pos+1,l-2);
      sans+=s[pos];
   }
   else{
      trace(pos+1,l);
   }
}
int nex[50005][26];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>s;
   n=s.size();
   for(int i=0;i<n;i++)
      dp[i][0]=i-1;
   for(int i=0;i<n;i++)
      dp[i][1]=i;
   for(int i=0;i<=100;i++)
      dp[n][i]=n;
   for(int i=0;i<26;i++){
      int occ=n;
      nex[n][i]=n;
      for(int j=n-1;j>=0;j--){
         nex[j][i]=occ;
         if(s[j]==i+'a')   occ=j;
      }
   }
   for(int i=n-1;i>=0;i--)
      for(int j=2;j<=100;j++){
         dp[i][j]=min(dp[i+1][j],nex[dp[i+1][j-2]][(int) s[i]-'a']);
         //cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
      }
   trace(0,100);
   cout<<sans<<endl;
}