#include <bits/stdc++.h>
using namespace std;

const int MAXN = 305;

int n, g[MAXN][MAXN], dp[MAXN][MAXN][MAXN];
bool vis[MAXN][MAXN][MAXN];

int di[] = {1, 0};
int dj[] = {0, 1};

int solve(int i, int j, int x, int y){
	if(vis[i][j][x])return dp[i][j][x];
	if(i == n - 1 && j == n - 1)return g[i][j];

	int c = g[i][j] + g[x][y];
	if(i == x && j == y)c -= g[i][j];

	int r = -1 << 20;
	for(int d1 = 0; d1 < 2; d1++)
	for(int d2 = 0; d2 < 2; d2++){
		int ni = i + di[d1], nj = j + dj[d1];
		int nx = x + di[d2], ny = y + dj[d2];

		if(ni > n - 1 || nj > n - 1)continue;
		if(nx > n - 1 || ny > n - 1)continue;

		r = max(r, solve(ni, nj, nx, ny));
	}

	vis[i][j][x] = true;
	return dp[i][j][x] = r + c;
}
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	for(int j = 0; j < n; j++)
		scanf("%d", &g[i][j]);

	printf("%d\n", solve(0, 0, 0, 0));

	return 0;
}