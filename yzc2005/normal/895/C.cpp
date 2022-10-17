#include <bits/stdc++.h>

const int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};

const int N = 19, mod = 1e9 + 7, M = 75;
int n, a, s, x, cnt, f[1 << N], g[1 << N], tot[M], po[100005];

int main() {
	scanf("%d", &n);
	f[0] = 1;
	po[0] = 1; for(int i = 1; i <= n; ++i) po[i] = 1ll * po[i - 1] * 2 % mod;
	while(n--) scanf("%d", &a), ++tot[a];
	for(int a = 1; a <= 70; ++a) {
		if(!tot[a]) continue;
		for(int i = 0; i < 1 << N; ++i) g[i] = f[i];
		s = 0, x = a;
		for(int i = 0; i < N; ++i) {
			if(x % p[i]) continue;
			cnt = 0;
			while(x % p[i] == 0) ++cnt, x /= p[i];
			if(cnt & 1) s |= 1 << i;
		}
		if(!s) for(int i = 0; i < 1 << N; ++i) f[i] = 1ll * g[i] * po[tot[a]] % mod;
		else for(int i = 0; i < 1 << N; ++i) f[i] = 1ll * (g[i] + g[i ^ s]) * po[tot[a] - 1] % mod;
	}
	printf("%d", f[0] - 1);
}