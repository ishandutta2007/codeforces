#include<bits/stdc++.h>
using namespace std;
int dp[10][10];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        int sz=s.size();
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                dp[j][k]=0;
            }
        }
        int ans=0;
        for(int i=0;i<sz;i++){
            int now=s[i]-'0';
            for(int j=0;j<10;j++){
                dp[j][now]=dp[now][j]+1;
                if(j==now||dp[j][now]%2==0){
                    ans=max(ans,dp[j][now]);
                }
                // cout<<i<<" "<<j<<" "<<dp[j][now]<<endl;
            }
        }
        cout<<(sz-ans)<<endl;
    }
}