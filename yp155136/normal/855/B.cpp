#include <iostream>
#include <cstdio>
using namespace std;

typedef long long LL;
const int MAX_N = 1e5 +6;
const LL INF = 1e18 + 7;

LL a[MAX_N];
LL dp[4][MAX_N];

int main () {
	int n,p[4];
	scanf("%d %d %d %d",&n,&p[1],&p[2],&p[3]);
	for (int i=1;n>=i;i++) {
		scanf("%lld",&a[i]);
	}
	for (int j=0;n>=j;j++) {
		dp[0][j] = -INF;
	}
	for (int i=1;3>=i;i++) {
		for (int j=1;n>=j;j++) {
			if(i!=1)dp[i][j] = dp[i-1][j] + p[i]*a[j];
			else dp[i][j] = p[i]*a[j];
			if (j!=1) dp[i][j] = max(dp[i][j],dp[i][j-1]);
		}
	}
	printf("%lld\n",dp[3][n]);
}