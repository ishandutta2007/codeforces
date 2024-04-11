#include <bits/stdc++.h>
using namespace std;
const int P = 1000350647, base = 2333;
int n, pw[300005];
int f[300005][20], g[300005][20];
int st[300005], top, nxt[300005];
char s[300005];
void link(int x, int y, int c) {
	f[x][0] = y, g[x][0] = c;
	for (int i = 1; i < 20; ++i) {
		f[x][i] = f[f[x][i - 1]][i - 1];
		g[x][i] = (1ll * g[x][i - 1] * pw[1 << (i - 1)] + g[f[x][i - 1]][i - 1]) % P;
	}
}
void copy(int x, int y) {
	memcpy(f[x], f[y], 80);
	memcpy(g[x], g[y], 80);
}
bool cmp(int x, int y) {
	for (int i = 19; ~i; --i) {
		if (f[x][i] && f[y][i] && g[x][i] == g[y][i]) {
			x = f[x][i];
			y = f[y][i];		
		}
	}
	return g[x][0] < g[y][0];
}
int main() {
	pw[0] = 1;
	for (int i = 1; i <= 300000; ++i)
		pw[i] = 1ll * pw[i - 1] * base % P;
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = n; i; --i) {
		if (s[i] == '(') {
			if (top) nxt[i] = st[top--] + 1;
		} else {
			st[++top] = i;
		}
	}
	for (int i = n; i; --i) {
		link(i, i + 1, s[i]);
		if (nxt[i] && cmp(nxt[i], i)) copy(i, nxt[i]);
	}
	for (int cur = 1; cur <= n && cur; cur = f[cur][0])
		if (g[cur][0] == '(' || g[cur][0] == ')')printf("%c", g[cur][0]);
	return 0;
}