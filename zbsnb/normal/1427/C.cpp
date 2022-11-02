#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dp[100010];
int mx[100010];
int t[100010],x[100010],y[100010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int r,n;cin>>r>>n;
    t[0]=0;
    x[0]=1;
    y[0]=1;
    for(int i=1;i<=n;i++){
        cin>>t[i]>>x[i]>>y[i];
        dp[i]=-1e9;
        for(int j=i-1;j>=0;j--){
            if(t[i]-t[j]>1000){
                dp[i]=max(dp[i],mx[j]+1);
                // cout<<"?1 "<<i<<" "<<j<<endl;
                break;
            }
            if(abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j]){
                // cout<<"?2 "<<i<<" "<<j<<endl;
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        mx[i]=max(mx[i-1],dp[i]);
        // cout<<i<<" "<<mx[i]<<" "<<dp[i]<<endl;
    }
    cout<<mx[n]<<endl;
}