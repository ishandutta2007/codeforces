#include<bits/stdc++.h>
using namespace std;

const int maxn = 2000009, MOD = 1000000007;
int fac[maxn], rev[maxn], n, now, ans;

int power(int x, int p) {
	int res = 1;
	while (p) {
		if (p & 1) res = 1LL * res * x % MOD;
		x = 1LL * x * x % MOD; p >>= 1;
	}
	return res;
}

int C(int n, int m) {
	if (m < 0 || m > n) return 0;
	return 1LL * fac[n] * rev[m] % MOD * rev[n-m] % MOD;
}

int main() {
	scanf("%d", &n);
	fac[0] = rev[0] = 1;
	for (int i=1; i<=2*n; i++) {
		fac[i] = 1LL * fac[i-1] * i % MOD;
		rev[i] = power(fac[i], MOD - 2);
	}
	ans = now = 1;
	for (int i=1; i<=2*n; i++) {
		now = 2 * now % MOD;
		//printf("~%d\n", now);
		//printf("%d\n", C(i, n+1));
		if (i >= n+1) {
			now = (now - C(i-1, (i-1)-n) + MOD) % MOD;
			now = (now - C(i-1, n) + MOD) % MOD;
		}
		//printf("%d %d\n", i, now);
		ans = (ans + now) % MOD;
	}
	printf("%d\n", ans);
	return 0;
}