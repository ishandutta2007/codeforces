#include <bits/stdc++.h>
#define puts(x) fputs(x, stdout)

const int N = 2000054;

int n;
char s[N], S[N];
int f[N];

void solve(int n, char *s) {
	int i, j = *f = -1, L1, L2;
	memcpy(S, s, n), std::reverse_copy(s, s + n, S + n);
	for (i = 0; i < 2 * n; f[++i] = ++j)
		for (; ~j && S[j] != S[i]; j = f[j]);
	for (L1 = f[2 * n]; L1 > n; L1 = f[L1]);
	std::rotate(S, S + n, S + 2 * n), j = -1;
	for (i = 0; i < 2 * n; f[++i] = ++j)
		for (; ~j && S[j] != S[i]; j = f[j]);
	for (L2 = f[2 * n]; L2 > n; L2 = f[L2]);
	if (L2 < L1) std::swap(L1, L2), std::rotate(S, S + n, S + 2 * n);
	S[L2] = 0, puts(S);
}

void work() {
	int i, j; char tt;
	scanf("%s", s), n = strlen(s);
	for (i = 0, j = n - 1; i < j && s[i] == s[j]; ++i, --j);
	if (i >= j) {puts(s); return;}
	if (i != 0) tt = s[i], s[i] = 0, puts(s), s[i] = tt;
	solve(j - i + 1, s + i);
	if (j != n - 1) puts(s + (j + 1));
}

int main() {
	int T;
	for (scanf("%d", &T); T; --T) work(), putchar(10);
	return 0;
}