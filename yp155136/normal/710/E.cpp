#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;
const int MAX_N = 1e7 + 3;

LL dp[2*MAX_N];

int main () {
	int n;
	LL a,b;
	while (scanf("%d %I64d %I64d",&n,&a,&b) != EOF) {
		dp[1]=a;
		for (int x=2;2*n>=x;x++) {
			if (x%2==0) dp[x] = min(dp[x-1]+a,dp[x/2]+b);
			else dp[x]=min(dp[x-1]+a,min(dp[(x+1)/2]+b+a,dp[x/2]+b+a));
		}
		LL ans=dp[n];
		for (int x=n+1;2*n>=x;x++) {
			ans = min(ans,dp[x]+a*x);
		}
		printf("%I64d\n",ans);
	}
}