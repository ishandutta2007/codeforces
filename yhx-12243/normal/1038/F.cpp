#include <bits/stdc++.h>

typedef long long ll;
const int N = 54;
typedef ll mat[N][N], (*pmat)[N];

int n, T;
int f[N], d[N][2];
char s[N];
mat A, B;

inline void __builtin_matmul(pmat a, pmat b, pmat ret) {
	int i, j, k;
	for (i = 0; i < n; ++i) memset(ret[i], 0, n << 3);
	for (i = 0; i < n; ++i)	
		for (j = 0; j < n; ++j) if (a[i][j])
			for (k = 0; k < n; ++k) ret[i][k] += a[i][j] * b[j][k];
}

inline void matmul(pmat a, pmat b, pmat ret) {
	static mat tmp; __builtin_matmul(a, b, tmp);
	for (int i = 0; i < n; ++i) memcpy(ret[i], tmp[i], n << 3);
}

void matpow(pmat a, int n, pmat c) {
	static mat tmp;
	for (int i = 0; i < ::n; ++i) memcpy(tmp[i], a[i], ::n << 3);
	for (; n; n >>= 1, matmul(tmp, tmp, tmp)) if (n & 1) matmul(tmp, c, c);
}

int main() {
	int i, j, used[2]; ll ans;
	scanf("%d%s", &T, s), n = strlen(s);
	for (j = *f = -1, i = 0; i < n; f[++i] = ++j)
		for (s[i] &= 1; ~j && s[j] != s[i]; j = f[j]);
	for (i = 0; i < n; ++i) {
		*used = used[1] = -1;
		for (j = i; j >= 0; j = f[j])
			if (!~used[(int)s[j]])
				d[i][(int)s[j]] = j + 1, used[(int)s[j]] = i;
	}
	d[n][0] = d[n][1] = n;
	for (i = 0; i < n; ++i) ++A[i][ d[i][0] ], ++A[i][ d[i][1] ], B[i][i] = 1;
	matpow(A, T, B), ans = 1ll << T;
	for (i = 0; i < n; ++i) ans -= B[i][i];
	printf("%lld\n", ans);
	return 0;
}