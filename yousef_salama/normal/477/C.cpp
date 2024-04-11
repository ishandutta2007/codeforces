#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;
const int MAXM = 505;

char s[MAXN], p[MAXM];
int n, m, nxt[MAXN][26], match[MAXN], dp[MAXN][MAXN];

int main(){
	scanf("%s %s", s, p);
	n = strlen(s), m = strlen(p);

	for(int i = n; i >= 0; i--)
	for(int c = 0; c < 26; c++){
		if(i == n)nxt[i][c] = -1;
		else{
			if(s[i] - 'a' == c)nxt[i][c] = i;
			else nxt[i][c] = nxt[i + 1][c];
		}
	}

	for(int i = 0; i < n; i++){
		int k = i;
		for(int j = 0; j < m; j++){
			if(nxt[k][p[j] - 'a'] == -1){
				k = -1;
				break;
			}else k = nxt[k][p[j] - 'a'] + 1;
		}
		match[i] = k;
	}

	for(int i = n; i >= 0; i--)
	for(int j = 0; j <= n; j++){
		if(i == n){
			if(j == 0)dp[i][j] = 0;
			else dp[i][j] = 1 << 20;
		}else{
			dp[i][j] = dp[i + 1][j];
			if(match[i] != -1)
				dp[i][j] = min(dp[i][j], dp[match[i]][j - 1] + (match[i] - i - m));
		}
	}

	for(int i = 0; i <= n; i++){
		if(i > 0)printf(" ");

		int k = 0;
		for(int j = n; j >= 0; j--){
			if(n - i < m * j)continue;
			if(i < dp[0][j])continue;

			k = j;
			break;
		}
		printf("%d", k);
	}
	printf("\n");

	return 0;
}