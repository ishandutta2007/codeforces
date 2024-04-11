#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int n, dp[MAXN][MAXN][2];
pair <int, int> a[MAXN];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d %d", &a[i].first, &a[i].second);
	sort(a, a + n);

	for(int i = n; i >= 0; i--)
	for(int j = 0; j <= n; j++)
	for(int d = 0; d <= 1; d++){
		if(i == n)dp[i][j][d] = 0;
		else{
			int R = j == n ? -1 << 29 : a[j].first + d * a[j].second;
			if(a[i].first + a[i].second > R){
				dp[i][j][d] = dp[i + 1][i][1] + a[i].first + a[i].second - max(R, a[i].first);

				int m = -1;
				for(int k = i; k < n; k++)if(a[k].first > R){
					if(m != -1 && a[m].first + a[m].second > a[k].first){
						int l = a[m].first + a[m].second - max(R, a[k].first - a[k].second);
						dp[i][j][d] = max(dp[i][j][d], dp[k + 1][m][1] + l);
					}else{
						int l = a[k].first - max(R, a[k].first - a[k].second);
						dp[i][j][d] = max(dp[i][j][d], dp[k + 1][k][0] + l);
					}
					if(m == -1 || a[k].first + a[k].second > a[m].first + a[m].second)m = k;
				}
			}else dp[i][j][d] = dp[i + 1][j][d];
		}
	}
	printf("%d\n", dp[0][n][0]);

	return 0;
}