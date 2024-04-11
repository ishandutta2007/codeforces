#include <bits/stdc++.h>

const int N = 105, M = 2540;

int n;
int a[N], b[N];
char s[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}

int main() {
	int i, j, ans = 0;
	scanf("%d%s", &n, s);
	for (i = 0; i < n; ++i) scanf("%d%d", a + i, b + i);
	for (i = 0; i < M; ) {
		up(ans, std::count(s, s + n, 49));
		++i;
		for (j = 0; j < n; ++j)
			if (i >= b[j] && (i - b[j]) % a[j] == 0)
				s[j] ^= 1;
//		puts(s);
	}
	printf("%d\n", ans);
	return 0;
}