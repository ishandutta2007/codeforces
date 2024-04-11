#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int dp[5001][5001];  //dp[i][j] ==> ij 
int sum[5001][5001];

int main () {
	int n,a,b,k;
	while (scanf("%d %d %d %d",&n,&a,&b,&k) != EOF) {
		memset(dp,0,sizeof(dp));
		memset(sum,0,sizeof(sum));
		dp[0][a] = 1;
		for (int x=1;n>=x;x++) sum[0][x] = sum[0][x-1] + dp[0][x];
		if (a<b) {
			for (int i=1;k>=i;i++) {
				for (int j=1;n>=j;j++) {
					int tmp=(b-j-1)/2;
					if (j==b) break;
					dp[i][j] = sum[i-1][j+tmp]-dp[i-1][j];
					if (dp[i][j] < 0)dp[i][j] += 1000000007;
					dp[i][j] %= 1000000007;
					sum[i][j] = sum[i][j-1] + dp[i][j];
					sum[i][j] %= 1000000007;
					//cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
				}
			}
		}
		else {
			for (int i=1;k>=i;i++) {
				for (int j=b+1;n>=j;j++) {
					int tmp=(j-b-1)/2;
					//if (j==b) break;
					dp[i][j] = sum[i-1][n]-sum[i-1][j-tmp-1]-dp[i-1][j];
					if (dp[i][j] < 0) dp[i][j] +=   1000000007;
					dp[i][j] %=                     1000000007;
					sum[i][j] = sum[i][j-1] + dp[i][j];
					if (sum[i][j] < 0) sum[i][j] += 1000000007;
					sum[i][j] %= 1000000007;
					//cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
				}
			}
		}
		long long ans=0;
		for (int x=1;n>=x;x++) {
			ans += dp[k][x];
			ans %= 1000000007;
		}
		if (ans<0) ans+=1000000007;
		printf("%I64d\n",ans);
	}
}