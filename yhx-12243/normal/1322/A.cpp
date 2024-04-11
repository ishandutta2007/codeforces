#include <bits/stdc++.h>

const int N = 1000054;

int n;
int c[N];
char s[N];

int main() {
	int i, L, R, ans = 0;
	scanf("%d%s", &n, s);
	L = std::count(s, s + n, '(');
	R = std::count(s, s + n, ')');
	if (L != R) return puts("-1"), 0;
	for (i = 0; i < n; ++i) c[i + 1] = c[i] + (s[i] == 40 ? 1 : -1);
	for (i = 1; i <= n; ++i)
		ans += (c[i] < 0 || (c[i] == 0 && c[i - 1] < 0));
	return printf("%d\n", ans), 0;
}