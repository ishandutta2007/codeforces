#include <bits/stdc++.h>
using namespace std;

const int maxn = 800;
int n, a[maxn + 3], b[maxn + 3], tmp[maxn + 3], res[maxn + 3];
int get() { int x; scanf("%d", &x); return x; }

int main() {
	srand(time(0));
	scanf("%d", &n);
	int t = 0;
	for (int i = 1; i <= n; i++) {
		printf("? %d", n - 1);
		for (int k = 1; k <= n; k++) if (k != i) printf(" %d", k);
		puts(""), fflush(stdout);
		if (get()) {
			b[i] = -1;
			if (++t == 1) a[1] = i;
			if (t == 2) { a[n] = i; break; }
		}
	}
	for (int l = 1, r = n, k = 0; l + 1 <= r - 1; l <<= 1, r = n - l + 1, k++) {
		int s = 0, mod = l << 1;
		for (int i = 1; i <= l; i++) s = (s + i) % mod;
		for (int i = r; i <= n; i++) s = (s + i) % mod;
		for (int i = 1; i <= n; i++) if (b[i] != -1) {
			printf("? %d", 1 << (k + 1));
			int p = 0;
			for (int j = 1; j <= l; j++) if ((s - j + b[i] + l) % l) printf(" %d", a[j]); else p = j;
			for (int j = r; j <= n; j++) printf(" %d", a[j]);
			printf(" %d\n", i), fflush(stdout);
			if (((s - p + b[i] + l) % mod == 0) == get()) b[i] |= 1 << k;
		}
		for (int i = 1; i <= l && l + i < r - i; i++) {
			int m = 0, x = 0;
			for (int j = 1; j <= n; j++) if (b[j] != -1) tmp[++m] = j;
			x = l + i;
			for (int j = 1; j <= n; j++) if (b[j] == x % mod) {
				printf("? %d", m - 1);
				for (int k = 1; k <= m; k++) if (tmp[k] != j) printf(" %d", tmp[k]);
				puts(""), fflush(stdout);
				if (get()) { a[x] = j; b[j] = -1; break; }
			}
			x = r - i;
			for (int j = 1; j <= n; j++) if (b[j] == x % mod) {
				printf("? %d", m - 1);
				for (int k = 1; k <= m; k++) if (tmp[k] != j) printf(" %d", tmp[k]);
				puts(""), fflush(stdout);
				if (get()) { a[x] = j; b[j] = -1; break; }
			}
		}
	}
	for (int i = 1; i <= n; i++) res[a[i]] = i;
	if (res[1] > n / 2) for (int i = 1; i <= n; i++) res[i] = n + 1 - res[i];
	printf("! ");
	for (int i = 1; i <= n; i++) printf("%d%c", res[i], " \n"[i == n]);
	fflush(stdout);
	return 0;
}