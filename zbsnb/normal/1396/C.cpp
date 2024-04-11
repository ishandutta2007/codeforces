#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
int x[1000010];
int y[1000010];
int dp[2][1000010];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,a,b,c,d;cin>>n>>a>>b>>c>>d;
    for(int i=1;i<=n;i++){
        int tmp;cin>>tmp;
        x[i]=tmp*min(a,c)+c;
        y[i]=min(b+min(a,c),tmp*min(a,c)+2*a);
        // cout<<i<<" "<<x[i]<<" "<<y[i]<<endl;
    }
    for(int i=1;i<=n;i++){
        if(i==1)dp[0][i]=x[i],dp[1][i]=y[i]+d;
        else{
            dp[0][i]=min(dp[0][i-1]+x[i],min(dp[0][i-1]+y[i]+2*d,dp[1][i-1]+y[i]+d))+d;
            dp[1][i]=dp[0][i-1]+y[i]+d+d;
        }
        // cout<<i<<" "<<dp[0][i]<<" "<<dp[1][i]<<endl;
    }
    ll ans=dp[0][n];
    for(int i=n-1;i<=n;i++){
        if(i==n-1){
            dp[0][i]=min(dp[0][i-1]+x[i],min(dp[0][i-1]+y[i]+d,dp[1][i-1]+y[i]+d))+d;
        }
        else{
            dp[0][i]=min(dp[0][i-1]+x[i],min(dp[0][i-1]+y[i]+2*d,dp[1][i-1]+y[i]+d))+d;
            dp[1][i]=dp[0][i-1]+y[i]+d+d;
        }
    }
    ans=min(ans,dp[0][n]);
    cout<<ans<<endl;
}