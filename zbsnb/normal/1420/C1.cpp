#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[2][1000010];
int main(){
    int t;cin>>t;
    while(t--){
        int n,q;cin>>n>>q;
        dp[1][0]=0,dp[0][0]=-1e18;
        for(int i=1;i<=n;i++){
            int tmp;cin>>tmp;
            dp[0][i]=max(dp[0][i-1],dp[1][i-1]+tmp);
            dp[1][i]=max(dp[1][i-1],dp[0][i-1]-tmp);
        }
        cout<<max(dp[1][n],dp[0][n])<<endl;
    }
}