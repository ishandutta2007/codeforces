#include <bits/stdc++.h>
using namespace std;

const int MAXN = 25;
const int MAXM = 55;

int n, dp[2][1 << 20];
char g[MAXN][MAXN];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%s", g[i]);

	int m = 2 * n - 2;

	for(int i = m; i >= 0; i--){
		int st = max(0, i - n + 1);
		int en = min(n - 1, i);

		for(int mask = 0; mask < (1 << (en - st + 1)); mask++){
			if(i == m){
				dp[i & 1][mask] = 0;
			}else{
				int ms[26] = {0};
				for(int k = st; k <= en; k++)if(mask & (1 << (k - st))){
					int j = i - k;
					if(j < 0 || j >= n)continue;

					if(k + 1 < n){
						if(i >= n - 1)ms[g[k + 1][j] - 'a'] |= 1 << (k - st);
						else ms[g[k + 1][j] - 'a'] |= 1 << (k - st + 1);
					}
					if(j + 1 < n){
						if(i >= n - 1)ms[g[k][j + 1] - 'a'] |= 1 << (k - st - 1);
						else ms[g[k][j + 1] - 'a'] |= 1 << (k - st);
					}
				}

				if(i % 2 == 1){
					dp[i & 1][mask] = -1 << 20;
					for(int c = 0; c < 26; c++)if(ms[c])
						dp[i & 1][mask] = max(dp[i & 1][mask], (c == 0) - (c == 1) - dp[(i + 1) & 1][ms[c]]);
				}else{
					dp[i & 1][mask] = -1 << 20;
					for(int c = 0; c < 26; c++)if(ms[c])
						dp[i & 1][mask] = max(dp[i & 1][mask], -(c == 0) + (c == 1) - dp[(i + 1) & 1][ms[c]]);
				}
			}
		}
	}

	int res = -dp[0][1] + (g[0][0] == 'a') - (g[0][0] == 'b');

	if(res > 0)printf("FIRST\n");
	else if(res < 0)printf("SECOND\n");
	else printf("DRAW\n");

	return 0;
}