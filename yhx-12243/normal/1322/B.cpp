#include <bits/stdc++.h>

typedef long long ll;

int n;
int a[400054];
int buf[16777777];

int main() {
	int i, b, c, d, mask, ans = 0; ll S;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%d", a + i);
	for (b = 0; b <= 24; ++b) {
		mask = ~(-1 << b);
		for (i = 0; i < n; ++i) ++buf[(a[i] & mask) + 1];
		for (i = 0; i <= mask; ++i) buf[i + 1] += buf[i];
		S = d = 0;
		for (i = 0; i < n; ++i) {
			d += a[i] >> b & 1;
			c = 1 + (~a[i] & mask), S += n - buf[c];
			if ((a[i] << 1) >> b & 1) --S;
		}
		S /= 2, c = (d & (n ^ d) & 1) ^ (S & 1);
		ans |= c << b;
		memset(buf, 0, (mask + 2) << 2);
	}
	printf("%d\n", ans);
	return 0;
}