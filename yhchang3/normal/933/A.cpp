#include<bits/stdc++.h>
using namespace std;
int a[2001];
int dp[2001][4];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			dp[i][1]=dp[i-1][1];
			dp[i][3]=dp[i-1][3];
			dp[i][0]=dp[i-1][0]+1;
			dp[i][2]=max(dp[i-1][1],dp[i-1][2])+1;
		}
		else{
			dp[i][0]=dp[i-1][0];
			dp[i][2]=dp[i-1][2];
			dp[i][1]=max(dp[i-1][0],dp[i-1][1])+1;
			dp[i][3]=max(dp[i-1][2],dp[i-1][3])+1;
		}
	}
	int ans=0;
	for(int i=0;i<4;i++)
		ans=max(ans,dp[n][i]);
	cout<<ans<<endl;
}