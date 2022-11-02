#include<bits/stdc++.h>
using namespace std;
#define ll long long
char s[10010],t[10010];
int dp[5010][5010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;cin>>n>>m;
    cin>>(s+1)>>(t+1);
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i]==t[j]){
                dp[i][j]=max(0,dp[i-1][j-1])+2;
                ans=max(ans,dp[i][j]);
            }
            else{
                dp[i][j]=0;
                dp[i][j]=max(dp[i][j],dp[i-1][j]-1);
                dp[i][j]=max(dp[i][j],dp[i][j-1]-1);
            }
        }
    }
    cout<<ans<<endl;
}