#include <bits/stdc++.h>
using namespace std;

const int N = 20;

int n, m, g[N][N], f[1 << N];
char s[100005];

int main() {
	scanf("%d%d%s", &m, &n, s + 1);
	for(int i = 2; i <= m; ++i) ++g[s[i] - 'a'][s[i - 1] - 'a'], ++g[s[i - 1] - 'a'][s[i] - 'a'];
	memset(f, 0x3f, sizeof(f)); f[0] = 0;
	for(int s = 0; s < 1 << n; ++s) {
		int delta = 0;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				if((s >> i & 1) && !(s >> j & 1)) delta += g[i][j];
		for(int i = 0; i < n; ++i)
			f[s | (1 << i)] = min(f[s | (1 << i)], f[s] + delta);
	}
	printf("%d\n", f[(1 << n) - 1]);
}