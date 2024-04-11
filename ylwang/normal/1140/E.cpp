#include <bits/stdc++.h>
using namespace std;

#define int long long
#define IOS ios::sync_with_stdio(false);
#define endl "\n"
#define MAX 200050
#define mod 998244353

///
int x[MAX];
int dp[MAX];
int dp_1=1,dp_1_sum=1;
int dp_2=1,dp_2_sum=1;
int ans[MAX];
///
signed main()
{
    IOS;

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }

    if(x[1]>0){
        dp[1]=0;
        dp_1=x[1],dp_1_sum=1;
    }
    else{
        dp[1]=1;
        dp_1=1,dp_1_sum=1;
    }

    for(int i=3;i<=n;i+=2){
        if(x[i]>0){
            if(x[i]==dp_1){
                dp_1_sum=(m-1)*dp[i-2]%mod;
            }
            else{
                dp_1_sum=((m-2)*dp[i-2]%mod+dp_1_sum)%mod;
            }
            dp_1=x[i];
        }
        else{
            dp[i]=((m-2)*dp[i-2]%mod+dp_1_sum)%mod;
            dp_1_sum=(m-1)*dp[i-2]%mod;
        }
    }

    ///
    if(x[2]>0){
        dp[2]=0;
        dp_2=x[2],dp_2_sum=1;
    }
    else{
        dp[2]=1;
        dp_2=1,dp_2_sum=1;
    }

    for(int i=4;i<=n;i+=2){
        if(x[i]>0){
            if(x[i]==dp_2){
                dp_2_sum=(m-1)*dp[i-2]%mod;
            }
            else{
                dp_2_sum=((m-2)*dp[i-2]%mod+dp_2_sum)%mod;
            }
            dp_2=x[i];
        }
        else{
            dp[i]=((m-2)*dp[i-2]%mod+dp_2_sum)%mod;
            dp_2_sum=(m-1)*dp[i-2]%mod;
        }
    }
    int ans;
    if(n%2==0){
        ans=(dp_1_sum+(m-1)*dp[n-1]%mod)*(dp_2_sum+(m-1)*dp[n]%mod)%mod;
    }
    else{
        ans=(dp_1_sum+(m-1)*dp[n]%mod)*(dp_2_sum+(m-1)*dp[n-1]%mod)%mod;
    }
    cout<<ans;
    return 0;
}