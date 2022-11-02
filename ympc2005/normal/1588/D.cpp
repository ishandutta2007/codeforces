#include <bits/stdc++.h>
using namespace std;

const int N = 10, M = 55;

int n, a[M<<2], c[N][M<<1], p[N][M<<1][2], len[N], f[M][1<<10], g[M][1<<10][2];

char s[M<<1], b[M];

void init_() {
	memset(p, -1, sizeof(p));
	memset(f, -1, sizeof(f));
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%s", s + 1);
		len[i] = strlen(s + 1);
		
		for (int j = 1; j <= len[i]; j++) {
			c[i][j] = a[s[j]];
			
			if (~p[i][c[i][j]][0]) {
				p[i][c[i][j]][1] = j;
			} else {
				p[i][c[i][j]][0] = j;
			}
		}
	}
}

void dfs_(int x, int s) {
	if (~f[x][s]) {
		return;
	}
	
	for (int i = 0; i < n; i++) {
		if (p[i][x][(s&(1<<i)) > 0] == -1) {
			f[x][s] = 0;
			g[x][s][0] = g[x][s][1] = 0;
			return;
		}
	}
	
	f[x][s] = 1;
	g[x][s][0] = g[x][s][1] = 0;
	
	for (int i = 0; i < 52; i++) {
		int t = 0, ok = 1;
		
		for (int j = 0; j < n; j++) {
			int k = p[j][x][(s&(1<<j)) > 0];
			
			if (p[j][i][0] > k) {
					
			} else if (p[j][i][1] > k) {
				t |= 1<<j;
			} else {
				ok = 0;
				break;
			}
		}
		
		if (ok) {
			dfs_(i, t);
			
			if (f[i][t] + 1 > f[x][s]) {
				f[x][s] = f[i][t] + 1;
				g[x][s][0] = i;
				g[x][s][1] = t;
			}
		}
	}
}

void work_() {
	int mx = 0;
	
	for (int i = 0; i < 52; i++) {
		dfs_(i, 0);
		
		if (f[i][0] > f[mx][0]) {
			mx = i;
		}
	}
	
	printf("%d\n", f[mx][0]);
	
	for (int i = f[mx][0], x = mx, y = 0, z; i; i--) {
		putchar(b[x]);
		
		if (i > 1) {
			z = g[x][y][1];
			x = g[x][y][0];
			y = z;
		}
	}
	
	puts("");
}

int main() {
	for (int i = 0; i < 26; i++) {
		a['a' + i] = i;
		b[i] = 'a' + i;
	}
	
	for (int i = 0; i < 26; i++) {
		a['A' + i] = i + 26;
		b[i + 26] = 'A' + i;
	}
	
	int T;
	
	scanf("%d", &T);
	
	while (T--) {
		init_();
		work_();
	}
	
	return 0;
}