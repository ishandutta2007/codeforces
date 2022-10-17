#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, a[N];
long long f[N][N][N];
char s[N];

long long dfs(int l, int r, int k) {
	if(l > r) return 0;
	if(f[l][r][k]) return f[l][r][k];
	f[l][r][k] = a[k] + dfs(l + 1, r, 1);
	for(int i = l + 1; i <= r; ++i) if(s[i] == s[l]) 
		f[l][r][k] = max(f[l][r][k], dfs(l + 1, i - 1, 1) + dfs(i, r, k + 1));
	return f[l][r][k];
}

int main() {
	scanf("%d%s", &n, s + 1);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	printf("%lld\n", dfs(1, n, 1));
	return 0;
}