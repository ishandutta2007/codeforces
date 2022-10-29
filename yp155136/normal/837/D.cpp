#include <iostream>
#include <stdio.h>
#include <utility>
#include <cstring>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;

const int MAX_N = 206;
const int MAX_M = 27*206;

int dp[MAX_N][MAX_M];
pii p[MAX_N];

int main () {
	int n,k;
	scanf("%d %d",&n,&k);
	memset(dp,-1,sizeof(dp));
	for (int i=1;n>=i;i++) {
		LL x;
		scanf("%lld",&x);
		while (x%2==0) {
			x/=2;
			p[i].first++;
		}
		while (x%5==0) {
			x/=5;
			p[i].second++;
		}
	}
	int m=MAX_M-1;
	int ans=0;
	dp[0][0] = 0;
	for (int ii=1;n>=ii;ii++) {
		int _2=p[ii].first,_5=p[ii].second;
		for (int i=k;i>=1;i--) {
			for (int j=m;j>=0;j--) {
				if (j-_5 <0) break;
				if (j-_5 >= 0 && dp[i-1][j-_5] != -1) {
					dp[i][j] = max(dp[i][j],dp[i-1][j-_5] + _2);
					ans = max(ans,min(j,dp[i][j]));
				}
			}
		}
	}
	printf("%d\n",ans);
}