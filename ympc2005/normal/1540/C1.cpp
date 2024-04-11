#include <bits/stdc++.h>
using namespace std;

const int N = 105, mod = 1e9 + 7;

int n, a[N], b[N], q, ans[N<<5], res = 1, f[N*N];

int solve_(int x) {
	memset(f, 0, sizeof(f));
	f[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= a[i]; j++) {
			f[j] = (f[j] + f[j - 1])%mod;
		}

		int y = a[i] - a[i - 1];

		for (int j = a[i]; j > y; j--) {
			f[j] = (f[j] - f[j - y - 1])%mod;
		}

		for (int j = 0; j <= a[i]; j++) {
			if (j - b[i] < x*i) {
				f[j] = 0;
			}
		}
	}

	int res = 0;

	for (int i = 0; i <= a[n]; i++) {
		res = (res + f[i])%mod;
	}

	return res;
}

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		res = 1ll*res*(a[i] + 1)%mod;
		a[i] += a[i - 1];
	}

	for (int i = 2; i <= n; i++) {
		scanf("%d", &b[i]);
		b[i] += b[i - 1];
	}

	for (int i = 2; i <= n; i++) {
		b[i] += b[i - 1];
	}

	int L = 1e9, R = 1e9;

	for (int i = 1; i <= n; i++) {
		L = min(L, -b[i]/i - 2);
		R = min(R, (a[i] - b[i])/i + 2);
	}

	for (int i = L; i <= R; i++) {
		ans[i - L] = solve_(i);
	}

	scanf("%d", &q);

	for (int x, i = 1; i <= q; i++) {
		scanf("%d", &x);

		if (x < L) {
			printf("%d\n", (res%mod + mod)%mod);
		} else if (x > R) {
			puts("0");
		} else {
			printf("%d\n", (ans[x - L]%mod + mod)%mod);
		}
	}
}