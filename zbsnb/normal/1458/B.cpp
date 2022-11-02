#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[105],b[105];
// ijk
int dp[105][105][105*105];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>b[i]>>a[i];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=10000;k++){
				if(i==0){
					dp[i][j][k]=i==0&&j==0&&k==0?0:-1e9;
					continue;
				}

				dp[i][j][k]=-1e9;
				if(k>=b[i]&&j>=1){
					dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k-b[i]]+2*a[i]);
				}
				dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i]);
			}
		}
	}
	for(int j=1;j<=n;j++){
		int ans=0;
		for(int k=0;k<=10000;k++){
			ans=max(ans,min(dp[n][j][k],2*k));
		}
		cout<<fixed<<setprecision(1)<<0.5*ans<<" ";
	}
}