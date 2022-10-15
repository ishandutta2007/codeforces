#include <bits/stdc++.h>

typedef long long ll;

const int kN = 4e4 + 5;

int a[kN], b[kN], f[kN], d[kN], cnt = 0;
int n, m, k; ll ans = 0;

void Fact() {
	for(int i = 1; i * i <= k; ++i)
		if(k % i == 0) {
			d[++cnt] = i;
			if(i * i != k) d[++cnt] = k / i;
		}
}

int main() {
	scanf("%d%d%d", &n, &m, &k); Fact();
	for(int i = 1; i <= n; ++i) scanf("%d", a + i);
	for(int i = 1; i <= m; ++i) scanf("%d", b + i);
	for(int i = 1; i <= cnt; ++i) {
		int lt = 1;
		for(int j = 1; j <= n; ++j, ++lt) {
			if(a[j] == 0) { lt = 0; continue; }
			if(lt >= d[i]) ++f[i];
		}
	}
	int lst = 1;
	for(int i = 1; i <= m; ++i, ++lst) {
		if(b[i] == 0) { lst = 0; continue; }
		for(int j = 1; j <= cnt; ++j)
			if(k / d[j] <= lst) ans += f[j];
	}
	printf("%lld", ans);
	return 0;
}