#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;

ll dp[3][1000010];
char s[1000010];
int main(){
    int n;cin>>n>>(s+1);
    ll cnt=1;
    for(int i=1;i<=n;i++){
        if(s[i]=='a'){
            dp[0][i]=(dp[0][i-1]+cnt)%mod;
            dp[1][i]=dp[1][i-1];
            dp[2][i]=dp[2][i-1];
        }
        if(s[i]=='b'){
            dp[0][i]=dp[0][i-1];
            dp[1][i]=(dp[1][i-1]+dp[0][i-1])%mod;
            dp[2][i]=dp[2][i-1];
        }
        if(s[i]=='c'){
            dp[0][i]=dp[0][i-1];
            dp[1][i]=dp[1][i-1];
            dp[2][i]=(dp[2][i-1]+dp[1][i-1])%mod;
        }
        if(s[i]=='?'){
            dp[0][i]=(3*dp[0][i-1]+cnt)%mod;
            dp[1][i]=(3*dp[1][i-1]+dp[0][i-1])%mod;
            dp[2][i]=(3*dp[2][i-1]+dp[1][i-1])%mod;
            cnt=cnt*3%mod;
        }
        // cout<<i<<" "<<dp[0][i]<<" "<<dp[1][i]<<" "<<dp[2][i]<<endl;
    }
    cout<<dp[2][n]<<endl;
}