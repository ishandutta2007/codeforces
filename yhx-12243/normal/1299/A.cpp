#include <bits/stdc++.h>

const int N = 100054;

int n;
int a[N], pre[N], suf[N];

inline bool up(int &x, const int y) {return x < y ? x = y, 1 : 0;}

int main() {
	int i, j = 0, ans = -1;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) scanf("%d", a + i), pre[i] = pre[i - 1] | a[i];
	for (i = n; i; --i) suf[i] = suf[i + 1] | a[i];
	for (i = 1; i <= n; ++i) if (up(ans, a[i] & ~(pre[i - 1] | suf[i + 1]))) j = i;
	printf("%d", a[j]);
	for (i = 1; i <= n; ++i) if (i != j) printf(" %d", a[i]);
	putchar(10);
//	fprintf(stderr, "%d\n", ans);
	return 0;
}