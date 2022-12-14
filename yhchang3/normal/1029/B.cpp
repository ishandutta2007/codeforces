#include<bits/stdc++.h>

using namespace std;

int dp[200010];
int ans=0,n;
int a[200010];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dp[1]=1;
    for(int i=2;i<=n;i++){
        if(a[i]<=2*a[i-1]){
            dp[i]=dp[i-1]+1;
        }
        else    dp[i]=1;
    }
    for(int i=1;i<=n;i++){
        if(ans<dp[i])   ans=dp[i];
    }
    cout<<ans<<endl;
}