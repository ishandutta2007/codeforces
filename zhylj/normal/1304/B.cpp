#include <bits/stdc++.h>

const int kMaxN = 105;

char s[kMaxN][kMaxN]; int n, m, st[kMaxN], top = 0, mid = 0;
bool vis[kMaxN];

bool rev(int i, int j) {
	for(int k = 1; k <= m; ++k) if(s[i][k] != s[j][m - k + 1]) return false;
	return true;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%s", s[i] + 1);
	}
	//printf()
	for(int i = 1; i <= n; ++i) {
		if(vis[i]) continue;
		for(int j = i + 1; j <= n; ++j)
			if(rev(i, j) && !vis[j]) {
				st[++top] = i;
				vis[i] = vis[j] = true;
			}
	}
	for(int i = 1; i <= n; ++i)
		if(!vis[i] && rev(i, i)) { mid = i; break; }
	printf("%d\n", (2 * top + (mid != 0)) * m);
	for(int i = 1; i <= top; ++i)
		printf("%s", s[st[i]] + 1);
	if(mid) printf("%s", s[mid] + 1);
	for(int i = top; i; --i)
		for(int j = m; j; --j)
			printf("%c", s[st[i]][j]);
	return 0;
}