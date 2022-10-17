#include <bits/stdc++.h>
using namespace std;

const int INF=1000000000;

int dp[32][32][52];

int main(){
	for(int i=1;i<=30;i++){
		for(int j=1;j<=30;j++){
			for(int k=0;k<=50;k++){
				if(k==0||k==i*j)dp[i][j][k]=0;
				else {
					dp[i][j][k]=INF;
					for(int s=1;s<=j-1;s++){
						for(int t=0;t<=k;t++){
							dp[i][j][k]=min(dp[i][j][k],dp[i][s][t]+dp[i][j-s][k-t]+i*i);
						}
					}
					for(int s=1;s<=i-1;s++){
						for(int t=0;t<=k;t++){
							dp[i][j][k]=min(dp[i][j][k],dp[s][j][t]+dp[i-s][j][k-t]+j*j);
						}
					}
				}
			}
		}
	}
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		printf("%d\n",dp[n][m][k]);
	}
}