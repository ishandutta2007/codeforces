#include <bits/stdc++.h>

typedef long long ll;
const int M = 1054000;

int H, h, N, n, inf, sup, base, best;
int a[M], b[M];
bool tag[M];
ll ans = 0;

void dfs(int x) {
	if (a[x] <= base) a[x] = INT_MAX;
	else if (a[x] < a[best]) best = x;
	if (x < inf) dfs(x * 2), dfs(x * 2 + 1);
}

int solve(int root, int dep) {
	if (!dep) return 0;
	int pos, val;
	base = std::max(solve(root * 2, dep - 1), solve(root * 2 + 1, dep - 1));
	best = 0, dfs(root), pos = best, ans += val = a[pos];
	return a[pos] = INT_MAX, tag[pos] = false, val;
}

void work() {
	int i; ans = 0; bool first = true;
	scanf("%d%d", &H, &h), N = ~(-1 << H), n = ~(-1 << h);
	for (i = 1; i <= N; ++i) scanf("%d", a + i), tag[i] = true, b[i] = a[i];
	inf = 1 << (H - 1), solve(1, h);
	printf("%lld\n", ans);
	for (i = N; i; --i) if (tag[i])
		first || putchar(32), first = false, printf("%d", i);
	putchar(10);
}

int main() {
	int T; *a = INT_MAX;
	for (scanf("%d", &T); T; --T) work();
	return 0;
}