#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
using namespace std;
#define ll long long

int dp[2][200010];
int a[200010],b[200010];
int main(){
    int n,c;cin>>n>>c;
    for(int i=1;i<n;i++)cin>>a[i];
    for(int i=1;i<n;i++)cin>>b[i];
    dp[0][0]=0,dp[1][0]=c;
    for(int i=1;i<n;i++){
        dp[0][i]=min(dp[1][i-1]+b[i],dp[0][i-1]+a[i]);
        dp[1][i]=min(dp[1][i-1]+b[i],dp[0][i-1]+a[i]+c);
    }
    for(int i=0;i<n;i++){
        cout<<dp[0][i]<<" ";
    }cout<<endl;
}