#include <bits/stdc++.h>

const int kMaxN = 24;
const int kMod = 1e9 + 7;

int f[(1 << kMaxN) + 5], s[kMaxN], sum[(1 << kMaxN) + 5], n, k;

int main() {
	register int p[2];
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", s + i);
	scanf("%d", &k); p[0] = p[1] = -1;
	for(int i = 0; i < k; ++i) scanf("%d", p + i);
	f[0] = 1;
	for(int i = 0; i < n; ++i) sum[1 << i] = s[i];
	for(register int i = 0; i < 1 << n; ++i) sum[i] = sum[i ^ (i & -i)] + sum[i & -i];
	for(register int i = 0; i < 1 << n; ++i) {
		if(sum[i] == p[0] || sum[i] == p[1]) {f[i] = 0; continue;}
		for(register int tmp = i; tmp; tmp &= (tmp - 1))
			f[i] = (f[i] + f[i ^ (tmp & -tmp)]) % kMod;
	}
	printf("%d", f[(1 << n) - 1]);
	return 0;
}