#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll dp[2][2][100010];
int main(){
    dp[0][0][1]=1;dp[0][0][2]=1;
    dp[0][1][1]=1;dp[0][1][2]=1;
    dp[1][0][1]=0;dp[1][0][2]=1;
    dp[1][1][1]=0;dp[1][1][2]=1;
    for(int i=3;i<=100000;i++){
        dp[0][0][i]=dp[1][0][i-1];
        dp[1][1][i]=dp[0][1][i-1];
        dp[0][1][i]=(dp[1][0][i-1]+dp[0][0][i-1])%mod;
        dp[1][0][i]=(dp[0][1][i-1]+dp[1][1][i-1])%mod;
    }
    int n,m;cin>>n>>m;
    ll ans=dp[0][0][n]+dp[0][0][m]
        +dp[0][1][n]+dp[0][1][m]
        +dp[1][0][n]+dp[1][0][m]
        +dp[1][1][n]+dp[1][1][m]
        -2;
    cout<<ans%mod<<endl;
}