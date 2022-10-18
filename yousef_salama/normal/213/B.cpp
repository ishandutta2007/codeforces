#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int MOD = 1000000007;

int n, a[10], C[MAXN][MAXN], dp[MAXN][15];
int main(){
	for(int i = 0; i < MAXN; i++)
	for(int j = 0; j < MAXN; j++){
		if(j == 0)C[i][j] = 1;
		else if(i == 0)C[i][j] = 0;
		else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
	}

	scanf("%d", &n);
	for(int i = 0; i < 10; i++)
		scanf("%d", &a[i]);

	int r = 0;
	for(int f = 0; f < n; f++){
		for(int d = 1; d < 10; d++){
			a[d]--;

			for(int j = 0; j <= 10; j++)
			for(int i = 0; i <= n - f - 1; i++){
				if(j == 0){
					if(i == 0)dp[i][j] = 1;
					else dp[i][j] = 0;
				}else{
					dp[i][j] = 0;
					for(int k = max(0, a[j - 1]); k <= i; k++)
						dp[i][j] = (dp[i][j] + 1LL * dp[i - k][j - 1] * C[i][k]) % MOD;
				}
			}
			r = (r + dp[n - f - 1][10]) % MOD;

			a[d]++;
		}
	}
	printf("%d\n", r);


	return 0;
}