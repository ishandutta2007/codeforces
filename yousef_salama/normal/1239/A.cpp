#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MOD = 1000000007;

int n, m, dp[MAXN];

int main(){
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i <= max(n, m); i++){
		if(i == 0)dp[i] = 1;
		else dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}
	
	printf("%lld\n", (2LL * dp[n] + 2LL * dp[m] - 2LL) % MOD);
	
	return 0;
}