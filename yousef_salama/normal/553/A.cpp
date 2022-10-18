#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int MOD = 1000000007;

int n, ci, C[MAXN][MAXN];
int main(){
	for(int i = 0; i < MAXN; i++)
	for(int j = 0; j < MAXN; j++){
		if(j == 0)C[i][j] = 1;
		else if(i == 0)C[i][j] = 0;
		else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
 	}

	scanf("%d", &n);

	int r = 1, t = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &ci);

		r = (1LL * r * C[t + ci - 1][ci - 1]) % MOD;
		t += ci;
	}
	printf("%d\n", r);

	return 0;
}