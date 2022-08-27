#include <bits/stdc++.h>

const int N = 100054;

int n;
char s[N], t[N];
int S[26], T[26], rS[26], rT[26];

int main() {
	int i, j, $, ans = 0;
#ifndef OsNLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%s%s", s, t), n = strlen(s);
	for (i = 0; i < n; ++i) ++S[ s[i] -= 65 ], ++T[ t[i] -= 65 ];
	for (i = 0; i < 26; ++i)
		$ = std::min(S[i], T[i]), rS[i] = S[i] - $, rT[i] = T[i] - $, ans += rS[i] | rT[i];
	printf("%d\n", ans / 2);
	for (j = i = 0; i < n; ++i) {
		for (; j < 26 && !rT[j]; ++j);
		if (rS[ s[i] ] > 0) {
			assert(j < 26);
			if (j < int(s[i]) || rS[ s[i] ] == S[ s[i] ]) t[i] = j, --rS[ s[i] ], --rT[j];
			else t[i] = s[i];
		} else t[i] = s[i];
		--S[ s[i] ], putchar(t[i] + 65);
	}
	putchar(10);
	return 0;
}