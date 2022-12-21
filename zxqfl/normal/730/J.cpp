#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

void smax(int &x,int y) {
	if(y>x) x=y;
}

int main() {
	int n; scanf("%d",&n);
	static int a[120],b[120];
	for(int i=0;i<n;i++) scanf("%d",a+i);
	for(int i=0;i<n;i++) scanf("%d",b+i);

	int S=accumulate(a,a+n,0);
	priority_queue<int> pq;
	for(int i=0;i<n;i++) pq.push(b[i]);
	int K=0;
	int need=S;
	for(;need>0;) {
		need-=pq.top(); pq.pop(); ++K;
	}


	const int MX=1.1e4;
	static int dp[128][MX];
	const int inf=1e9+99;
	for(int i=0;i<=K;i++) for(int j=0;j<MX;j++) dp[i][j]=-inf;
	dp[0][0]=0;
	for(int i=0;i<n;i++) {
		for(int k=K;--k>=0;)
		for(int x=0;x<MX-b[i];x++) {
			if(dp[k][x]>-inf)
			smax(dp[k+1][x+b[i]],dp[k][x]+a[i]);
		}
	}

	int ans=-inf;
	for(int x=S;x<MX;x++) smax(ans,dp[K][x]);
	// for(int x=S;x<MX;x++) if(dp[K][x]>S) printf("dp[%d][%d]=%d\n",K,x,dp[K][x]);
	printf("%d %d\n",K,S-ans);
}