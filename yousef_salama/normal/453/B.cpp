#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int n, a[MAXN];

int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}, mi[60], ci[60];
bool isprime[60];

int dp[MAXN][1 << 10][10], path[MAXN][1 << 10][10];

int main(){
	isprime[1] = false;
	for(int i = 2; i <= 58; i++){
		isprime[i] = true;
		for(int j = 2; j < i; j++)
			if(i % j == 0)isprime[i] = false;
	}

	for(int i = 0; i < 10; i++)
	for(int j = 1; j <= 58; j++)
		if(j % p[i] == 0)mi[j] |= 1 << i;

	for(int x = 1, c = 0; x <= 58; x++){
		if(x > 30 && isprime[x])ci[x] = ++c;
		else ci[x] = 0;
	}

	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for(int i = n; i >= 0; i--)
	for(int m = 0; m < (1 << 10); m++)
	for(int k = 0; k < 10; k++){
		if(i == n)dp[i][m][k] = 0;
		else{
			dp[i][m][k] = 1 << 20;
			for(int x = 1; x <= 58; x++){
				if((mi[x] & m) != 0)continue;
				if(ci[x] != 0 && k >= ci[x])continue;

				if(dp[i + 1][m | mi[x]][max(k, ci[x])] + abs(x - a[i]) < dp[i][m][k]){
					path[i][m][k] = x;
					dp[i][m][k] = dp[i + 1][m | mi[x]][max(k, ci[x])] + abs(x - a[i]);
				}
			}
		}
	}

	int i = 0, m = 0, k = 0;
	while(i != n){
		int x = path[i][m][k];

		if(i > 0)printf(" ");
		printf("%d", x);

		i = i + 1;
		m = m | mi[x];
		k = max(k, ci[x]);
	}
	printf("\n");

    return 0;
}