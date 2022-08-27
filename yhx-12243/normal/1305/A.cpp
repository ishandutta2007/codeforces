#include <bits/stdc++.h>

const int N = 100054;

int n;
int a[N], b[N];

void work() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%d", a + i);
	for (i = 0; i < n; ++i) scanf("%d", b + i);
	std::sort(a, a + n), std::sort(b, b + n);
	for (i = 0; i < n; ++i) printf("%d%c", a[i], i==n-1?10:32);
	for (i = 0; i < n; ++i) printf("%d%c", b[i], i==n-1?10:32);
}

int main() {
	int T;
	for (scanf("%d", &T); T; --T) work();
	return 0;
}