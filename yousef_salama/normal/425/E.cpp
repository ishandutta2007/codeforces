#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MAXN = 505;
const int MAXP = 505 * 505;

int n, k, dp[2][MAXN], pw2[MAXP];
int main(){
	scanf("%d %d", &n, &k);

	pw2[0] = 1;
	for(int i = 1; i < MAXP; i++){
		pw2[i] = pw2[i - 1] * 2;
	    if(pw2[i] >= MOD)pw2[i] -= MOD;
	}

	for(int j = 0; j <= k; j++)
	for(int i = n; i >= 0; i--){
		dp[j & 1][i] = 0;

		int s = 0;
		for(int z = i + 1; z <= n; z++){
			s += i;
			if(j > 0){
			    dp[j & 1][i] = dp[j & 1][i] + 1LL * pw2[s] * (pw2[z - i] - 1 + MOD) % MOD * dp[(j - 1) & 1][z] % MOD;
			    if(dp[j & 1][i] >= MOD)dp[j & 1][i] -= MOD;
			}
		}
		if(j == 0)dp[j & 1][i] = pw2[s];
	}
	printf("%d\n", dp[k & 1][0]);

	return 0;
}