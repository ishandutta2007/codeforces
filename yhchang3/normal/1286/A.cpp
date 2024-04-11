#include<bits/stdc++.h>
using namespace std;

int odd,even;
int dp[101][101][101][2];
int p[105];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	odd=n/2+n%2;
	even=n/2;
	for(int i=0;i<=100;i++)
		for(int j=0;j<=100;j++)
			for(int k=0;k<=100;k++)
				dp[i][j][k][0]=dp[i][j][k][1]=10000;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	dp[0][0][0][0]=dp[0][0][0][1]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=n;j++)
			for(int k=0;k<=n;k++){
				if(p[i]==0){
					if(j>=1)
						dp[i][j][k][1]=min(dp[i-1][j-1][k][0]+1,dp[i-1][j-1][k][1]);
					if(k>=1)
						dp[i][j][k][0]=min(dp[i-1][j][k-1][0],dp[i-1][j][k-1][1]+1);
				}
				else{
					if(p[i]&1){
						if(j>=1)
							dp[i][j][k][1]=min(dp[i-1][j-1][k][0]+1,dp[i-1][j-1][k][1]);
					}
					else{
						if(k>=1)
							dp[i][j][k][0]=min(dp[i-1][j][k-1][0],dp[i-1][j][k-1][1]+1);
					}
				}
			}
	cout<<min(dp[n][odd][even][0],dp[n][odd][even][1]);
}