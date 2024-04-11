#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 5;
char s[N]; 
int a[N][N], e[N][N], mat[N], vis[N], n, m;
int dfs(int u) {
	for(int v = 1; v < m; v++) {
		if(e[u][v] && !vis[v]) {
			vis[v] = 1; 
			if(!mat[v] || dfs(mat[v])) return mat[v] = u, 1; 
		}
	}
	return 0;
}
int solve() {
	int ans = 0; 
	for(int i = 1; i < n; i++)
		memset(vis, 0, sizeof(vis)), ans += dfs(i); 	
	return ans;
}
int main() {
	scanf("%d %d", &n, &m); 
	for(int i = 1; i <= n; i++) {
		scanf("%s", s + 1);
		for(int j =	1; j <= m; j++)
			a[i][j] = s[j] == 'B';
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			a[i][j] ^= a[i][j + 1] ^ a[i + 1][j] ^ a[i + 1][j + 1], cnt += a[i][j] == 1;
	for(int i = 1; i < n; i++)
		for(int j = 1; j < m; j++) 
			if(a[i][j] && a[n][j] && a[i][m])
				e[i][j] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) 
			fprintf(stderr, "%d%c", a[i][j], " \n"[j == m]);
	int mat = solve(), ans = cnt - mat;
//	cerr << mat << ' ' << ans << endl; 
	if(mat % 2 == 1 && a[n][m]) printf("%d\n", ans - 1);
	else if(mat % 2 == 1 && !a[n][m]) printf("%d\n", ans + 1);
	else printf("%d\n", ans);
	return 0;	
}