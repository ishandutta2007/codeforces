#include <bits/stdc++.h>

const int kN = 2e3 + 5;

int n, a_max, a[kN], f[kN], g[kN][kN]; bool b[kN][kN];

int main() {
	memset(f, 0x3f, sizeof(f));
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i);
	for(int i = 1; i <= n; ++i)
		b[i][i] = true, g[i][i] = a[i];
	for(int len = 1; len <= n; ++len)
		for(int i = 1; i + len <= n; ++i) {
			int j = i + len;
			for(int k = i; k < j; ++k)
				if(b[i][k] && b[k + 1][j] && g[i][k] == g[k + 1][j]) {
					b[i][j] = true; g[i][j] = g[i][k] + 1;
					break;
				}
		}
	f[0] = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= i; ++j)
			if(b[j][i])
				f[i] = std::min(f[j - 1] + 1, f[i]);
	printf("%d", f[n]);
	return 0;
}