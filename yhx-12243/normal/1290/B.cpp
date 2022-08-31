#include <bits/stdc++.h>

const int N = 200054;

int n, q;
int f[N][26];
char s[N];

int main() {
	int i, ch, l, r, cnt; bool ok;
	scanf("%s%d", s + 1, &q), n = strlen(s + 1);
	for (i = 1; i <= n; ++i) memcpy(f[i], f[i - 1], 104), ++f[i][s[i] - 97];
	for (; q; --q) {
		scanf("%d%d", &l, &r), ok = true;
		if (l < r && s[l] == s[r]) {
			ch = s[l] - 97, cnt = f[r][ch] - f[l - 1][ch];
			ok = cnt != r - l + 1;
			for (i = 0; i < 26 && ok; ++i)
				if (i != ch && f[r][i] - f[l - 1][i] + cnt == r - l + 1)
					ok = false;
		}
		puts(ok ? "Yes" : "No");
	}
	return 0;
}