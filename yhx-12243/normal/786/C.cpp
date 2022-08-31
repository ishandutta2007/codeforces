#include <bits/stdc++.h>

const int N = 100054;

int n;
int a[N], c[N];
int ans[N];
int cnt = 0, li[N];

inline void insert(int x) {if (!c[x]++) li[cnt++] = x;}
inline void reset() {for (; cnt; li[--cnt][c] = 0);}

int work(int lim) {
	int i, seg = 1; reset();
	for (i = 0; i < n; ++i) if (insert(a[i]), cnt > lim) ++seg, reset(), insert(a[i]);
	return seg;
}

void partition(int L, int R) {
	if (L + 1 >= R) return;
	int M = (L + R) / 2;
	ans[M] = work(M);
	ans[L] == ans[M] ? std::fill(ans + (L + 1), ans + M, ans[L]) : partition(L, M);
	ans[M] == ans[R] ? std::fill(ans + (M + 1), ans + R, ans[M]) : partition(M, R);
}

int main() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%d", a + i);
	ans[1] = work(1), ans[n] = 1;
	partition(1, n);
	for (i = 1; i <= n; ++i) printf("%d\n", ans[i]);
	return 0;
}