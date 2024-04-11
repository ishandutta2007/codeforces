#include <bits/stdc++.h>
#define lg2 std::__lg

typedef long long ll;
const int N = 40;

int mod;
int n;
int f[N][N];

inline void add(int &x, const int y) {x += y - mod, x += x >> 31 & mod;}

void work() {
	int i, j, k, L, ans = 0;
	scanf("%d%d", &n, &mod), L = lg2(n) + 1;
	memset(f, 0, sizeof f), f[0][0] = 1;
	for (i = 0; i < L; ++i)
		for (j = 0; j < L; ++j) if (f[i][j]) {
			for (k = j + 1; k < L; ++k)
				add(f[i + 1][k], ((ll)f[i][j] << (k - 1)) % mod);
			add(f[i + 1][L], f[i][j] * (n - (1 << (L - 1)) + 1ll) % mod);
		}
	for (i = 1; i <= L; ++i)
		for (j = 1; j <= L; ++j)
			add(ans, f[i][j]);
	printf("%d\n", ans);
}

int main() {
	int T;
	for (scanf("%d", &T); T; --T) work();
	return 0;
}