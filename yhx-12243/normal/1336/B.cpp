#include <bits/stdc++.h>

typedef long long ll;
const int N = 100054;

ll ans;
int A, B, C;
int a[N], b[N], c[N];

inline ll sqr(int x) {return (ll)x * x;}

void solve(int A, int *a, int B, int *b, int C, int *c) {
	int i, j, k;
	for (i = j = k = 0; i < A; ++i) {
		for (; j < B && b[j] <= a[i]; ++j);
		for (; k < C && c[k] < a[i]; ++k);
		if (j > 0 && k < C) {
			ans = std::min(ans, sqr(a[i] - b[j - 1]) + sqr(b[j - 1] - c[k]) + sqr(c[k] - a[i]));
		}
	}
}

void work() {
	int i; ans = LLONG_MAX;
	scanf("%d%d%d", &A, &B, &C);
	for (i = 0; i < A; ++i) scanf("%d", a + i);
	for (i = 0; i < B; ++i) scanf("%d", b + i);
	for (i = 0; i < C; ++i) scanf("%d", c + i);
	std::sort(a, a + A), std::sort(b, b + B), std::sort(c, c + C);
	solve(A, a, B, b, C, c);
	solve(A, a, C, c, B, b);
	solve(B, b, A, a, C, c);
	solve(B, b, C, c, A, a);
	solve(C, c, A, a, B, b);
	solve(C, c, B, b, A, a);
	printf("%lld\n", ans);
}

int main() {
	int T;
	for (scanf("%d", &T); T; --T) work();
	return 0;
}