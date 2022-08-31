#include <bits/stdc++.h>
#define ctz __builtin_ctz

typedef unsigned int u32;
const int N = 162;

int n, p, lim;
int v2[N];
u32 C[N];

inline void down(int &x, const int y) {x > y ? x = y : 0;}

inline u32 inv(u32 x) { // x must be odd
	u32 y = 1u;
	y = y * (2u - x * y), y = y * (2u - x * y);
	y = y * (2u - x * y), y = y * (2u - x * y);
	return y * (2u - x * y);
}

int main() {
	int i, j, k; u32 I, cur, ans = 0;
	scanf("%d%d%d", &n, &p, &lim), down(p, n - 1);
	for (*C = i = 1; i <= p; ++i) {
		I = n - i + 1, j = ctz(I), I >>= j, k = ctz(i);
		C[i] = C[i - 1] * I * inv(i >> k);
		v2[i] = v2[i - 1] + j - k;
	}
	for (i = 1; i <= p; ++i) C[i] <<= v2[i];
	for (i = 1; i <= lim; ans ^= i++ * cur)
		for (I = cur = j = 1; j <= p; ++j)
			cur += C[j] * (I *= i);
	printf("%u\n", ans);
	return 0;
}