#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;
#define ll long long
#define int ll

int a[200010];
int sum[200010];
int dp[200010];
signed main(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];

    for(int i=1;i<=m;i++)dp[i]=dp[i-1]+a[i];
    for(int i=m+1;i<=n;i++){
        dp[i]=dp[i-m]+sum[i];
    }
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<" ";
    }cout<<endl;
}