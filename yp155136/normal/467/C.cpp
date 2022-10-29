#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

typedef long long LL;
const int MAX_N = 5e3 +6;

LL dp[MAX_N][MAX_N];
LL a[MAX_N];
LL pre[MAX_N];

int main () {
	int n,m,k;
	while (scanf("%d %d %d",&n,&m,&k) != EOF) {
		for (int i=1;n>=i;i++) {
			scanf("%I64d",&a[i]);
			pre[i] = pre[i-1] + a[i];
		}
		LL ans = -1;
		for (int i=1;k>=i;i++) {
			LL mx = -1;
			for (int j=i*m;n>=j;j++) {
				//select k last j
				mx = max(mx,dp[i-1][j-m]);
				dp[i][j] = mx + pre[j] - pre[j-m];
				if (i==k) ans = max(ans,dp[i][j]);
			}
		}
		printf("%I64d\n",ans);
	}
}